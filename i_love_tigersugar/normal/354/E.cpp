#include<bits/stdc++.h>
#define x   first
#define y   second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<vector<int>,ii> trc;
struct num {
    int nd;
    int d[23];
    num(){
        nd=0;
        memset(d,0,sizeof d);
    }
    num(ll x) {
        nd=0;
        memset(d,0,sizeof d);
        if (x==0LL) {
            nd=1;
            d[nd-1]=0;
        }
        while (x>0LL) {
            nd++;
            d[nd-1]=x%10;
            x=x/10;
        }
    }
    int operator [] (const int &i) const {
        if (i>nd) return (0);
        return (d[i-1]);
    }
    void add(const int &i) {
        nd++;
        d[nd-1]=i;
    }
    void print(void) {
        int i;
        ll val=0LL;
        for (i=0;i<nd;i=i+1)
            val=val*10LL+d[i];
        printf("%I64d",val);
    }
};
const int digit[]={0,4,7};
int ndg;
ll n;
num tmp;
num ans[7];
bool vst[23][9];
trc t[23][9];
void init(void) {
    scanf("%I64d",&n);
    tmp=num(n);
    ndg=tmp.nd;
    memset(vst,false,sizeof vst);
    int i;
    for (i=0;i<6;i=i+1) ans[i].nd=0;    
    //for (i=1;i<=ndg;i=i+1) printf("%d ",tmp[i]); printf("\n");
}
void BFS(void) {
    queue<ii> q;
    while (!q.empty()) q.pop();
    ii p;
    int i1,i2,i3,i4,i5,i6;
    int pd,pr;
    vst[0][0]=true;
    q.push(ii(0,0));
    while (!q.empty()) {
        p=q.front();q.pop();
        pd=p.x;pr=p.y;
        if (pd==ndg && pr==0) return;
        if (pd==ndg) continue;
        for (i1=0;i1<3;i1++)
            for (i2=i1;i2<3;i2++)
                for (i3=i2;i3<3;i3++)
                    for (i4=i3;i4<3;i4++)
                        for (i5=i4;i5<3;i5++)
                            for (i6=i5;i6<3;i6++)
                                if ((digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)%10==tmp[pd+1])
                                    if (!vst[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10]) {
                                        vst[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10]=true;
                                        t[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10].x.clear();
                                        t[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10].x.push_back(i1);
                                        t[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10].x.push_back(i2);
                                        t[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10].x.push_back(i3);
                                        t[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10].x.push_back(i4);
                                        t[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10].x.push_back(i5);
                                        t[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10].x.push_back(i6);
                                        t[pd+1][(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10].y=p;
                                        q.push(ii(pd+1,(digit[i1]+digit[i2]+digit[i3]+digit[i4]+digit[i5]+digit[i6]+pr)/10));
                                    }
    }
}
void trace(void) {
    if (!vst[ndg][0]) {
        printf("-1\n");
        return;
    }
    ii cur=ii(ndg,0);
    int cd,cr,i;
    while (cur!=ii(0,0)) {
        cd=cur.x;cr=cur.y;
        for (i=0;i<6;i=i+1)
            ans[i].add(digit[t[cd][cr].x[i]]);
        cur=t[cd][cr].y;
    }
    for (i=0;i<6;i=i+1) {
        ans[i].print();
        if (i<5) printf(" "); else printf("\n");
    }
}
int main(void) {
    int t,ct;
    scanf("%d",&t);
    for (ct=0;ct<t;ct++) {
        init();
        BFS();
        trace();        
    }
    return 0;
}