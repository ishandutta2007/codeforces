#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#define MAX   2020
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int INF=(int)1e9+7;
char a[MAX][MAX];
int m,n,nw,lreq,rreq,nrow;
bool mark[MAX];
int top[MAX];
int bot[MAX];
vector<int> incol[MAX];
vector<int> row;
struct ans {
    int x,y,d;
    ans(){
        d=INF;
        x=-1;
        y=-1;
    }
    ans(int _x,int _y,int _d) {     
        x=_x;y=_y;d=_d;
    }
    void update(const ans &t) {
        if (t.x<1) return;
        if (t.y<1) return;
        if (t.x+t.d-1>m) return;
        if (t.y+t.d-1>n) return;
        if (d<=t.d) return;     
        (*this)=t;
    }
};
ans best;
void minimize(int &x,const int &y) {
    if (x>y) x=y;
}
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%d",&m);
    scanf("%d",&n);
    FOR(i,1,m) {
        scanf("%s",a[i]+1);
        FOR(j,1,n) nw+=(a[i][j]=='w');      
    }
    if (nw==1) {
        FOR(i,1,m) printf("%s\n",a[i]+1);
        exit(0);
    }
    lreq=n+1;
    rreq=0;
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]=='w') {
        minimize(lreq,j);
        maximize(rreq,j);
    }
    FOR(j,1,n) {
        top[j]=m+1;
        bot[j]=0;
        FOR(i,1,m) if (a[i][j]=='w') {
            minimize(top[j],i);
            maximize(bot[j],i);
        }
    }
    FOR(i,1,m) FOR(j,1,n) if (a[i][j]=='w') incol[j].push_back(i);
    best=ans();
}
void markwhite(int x,int y) {
    if (a[x][y]!='w') return;
    if (mark[x]) return;    
    mark[x]=true;
    row.push_back(x);
}
void choose(int left) {
    memset(mark,false,sizeof mark);
    row.clear();    
    FOR(right,left+1,n) {
        if (right>left+1) FORE(it,incol[right-1]) {
            markwhite(*it,right-1);
            if (row.size()>2) return;
        }
        if (right<rreq) continue;
        //printf("Choosing %d %d\n",left,right);
        int sz=right-left+1;
        int topreq=min(top[left],top[right]);
        int botreq=max(bot[left],bot[right]);   
        if (row.size()==1) {
            int x=row[0];
            //choose as top
            if (x+sz-1>=botreq && x<=topreq) best.update(ans(x,left,sz));
            //chose as bot
            if (x-sz+1<=topreq && x>=botreq) best.update(ans(x-sz+1,left,sz));
        }
        else {
            if (row.empty()) {
                if (topreq>=1 && botreq<=sz) best.update(ans(1,left,sz));
                if (topreq>=m-sz+1 && botreq<=m) best.update(ans(m-sz+1,left,sz));
                if (topreq>m && botreq<1) {
                    best.update(ans(1,left,sz));
                    continue;
                }
                if (topreq>m) {
                    best.update(ans(botreq-sz+1,left,sz));
                    continue;
                }
                if (botreq<1) {
                    best.update(ans(topreq,left,sz));
                    continue;
                }
                if (botreq-topreq+1<=sz) best.update(ans(topreq,left,sz));
            }
            else {              
                sort(row.begin(),row.end());
                int ctop=row[0];
                int cbot=row[1];
                if (ctop<=topreq && cbot>=botreq && cbot-ctop+1==sz) best.update(ans(ctop,left,sz));                
            }
        }
    }   
}
void process(void) {    
    FOR(i,1,lreq) choose(i);
    if (best.d>=INF) {
        printf("-1");
        return;
    }
    else {
        FOR(i,best.x,best.x+best.d-1) {
            if (a[i][best.y]=='.') a[i][best.y]='+';
            if (a[i][best.y+best.d-1]=='.') a[i][best.y+best.d-1]='+';
        }
        FOR(j,best.y,best.y+best.d-1) {
            if (a[best.x][j]=='.') a[best.x][j]='+';
            if (a[best.x+best.d-1][j]=='.') a[best.x+best.d-1][j]='+';
        }
    }
    FOR(i,1,m) printf("%s\n",a[i]+1);
}
int main(void) {
#ifdef MYHOME
    freopen("tmp.txt","r",stdin);
#endif
    init();
    process();
    return 0;
}