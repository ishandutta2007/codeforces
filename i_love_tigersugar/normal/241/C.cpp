#include<algorithm>
#include<cstdio>
#include<vector>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
struct miror {
    int l,r,v;
    miror() {
        l=0;r=0;v=0;
    }
    miror(int _l,int _r,int _v) {
        l=_l;r=_r;v=_v;     
    }
};
const int H=100;
const int W=100000;
const int INF=(int)1e9+7;
vector<miror> top,bot;
int hl,hr,ans,n;
void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
int roundup(ll x,int y) {
    if (x%y==0) return (x/y);
    return (x/y+1);
}
void init(void) {
    int l,r,v;
    char t;
    scanf("%d",&hl);
    scanf("%d",&hr);
    scanf("%d",&n);
    REP(i,n) {
        scanf("%d",&v);
        scanf(" %c",&t);
        scanf("%d",&l);
        scanf("%d",&r);
        if (t=='F') bot.push_back(miror(l,r,v));
        else top.push_back(miror(l,r,v));
    }
    ans=0;
//  FORE(it,bot) printf("%d %d %d\n",it->l,it->r,it->v);
}
bool less(int x,int p,int q) {
    return (1LL*x*q<=p);
}
bool greater(int x,int p,int q) {
    return (1LL*x*q>=p);
}
int mirorid(int p,int q,int type) {
//  printf("Checking %d %d %d\n",p,q,type);
    if (type==0) {
        REP(i,bot.size())
            if (less(bot[i].l,p,q) && greater(bot[i].r,p,q)) {
            //  printf("OK %d\n",i);
                return (i); 
            }
    }
    else {
        REP(i,top.size())
            if (less(top[i].l,p,q) && greater(top[i].r,p,q)) {
            //  printf("OK %d\n",i);
                return (i); 
            }
    }
    return (-1);
}
int choose(int x,int mode) {
    //printf("Choose %d %d\n",x,mode);
    vector<int> bid,tid;
    bid.clear();
    tid.clear();
    if (mode==0) {      
        REP(k,x+1) {
            bid.push_back(mirorid(W*(hl+2*k*H),hl+hr+2*x*H,0));
        //  printf("Push: %d\n",mirorid(W*(hl+2*k*H),hl+hr+2*x*H,0));
        }
        REP(k,x) {
            tid.push_back(mirorid(W*(hl+2*k*H+H),hl+hr+2*x*H,1));       
        //  printf("Push: %d\n",mirorid(W*(hl+2*k*H),hl+hr+2*x*H,0));
        }
    }
    else {
        REP(k,x+1) bid.push_back(mirorid(W*(hl+2*k*H),hl-hr+2*x*H+2*H,0));
        REP(k,x+1) tid.push_back(mirorid(W*(hl+2*k*H+H),hl-hr+2*x*H+2*H,1));
    }
    /*printf("Bot ID: ");
    FORE(it,bid) printf("%d ",*it);
    printf("\n");
    printf("Top ID: ");
    FORE(it,tid) printf("%d ",*it);
    printf("\n");*/
    sort(bid.begin(),bid.end());
    sort(tid.begin(),tid.end());    
    int res=0;
    int prev=-1;
    FORE(it,bid) {
        if (*it<0) return (-INF);
        if (*it==prev) return (-INF);
        res+=bot[*it].v;
        prev=*it;
    }
    prev=-1;
    FORE(it,tid) {
        if (*it<0) return (-INF);
        if (*it==prev) return (-INF);
        res+=top[*it].v;
        prev=*it;
    }
    return (res);
}
void process(void) {
    REP(x,n+7) REP(mode,2) maximize(ans,choose(x,mode));
    hl=H-hl;
    hr=H-hr;
    swap(top,bot);
    REP(x,n+7) REP(mode,2) maximize(ans,choose(x,mode));    
    printf("%d",ans);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
    //freopen("tmp.out","w",stdout);
#endif
    init();
    process();
    return 0;
}