#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const char noSol[]="No solution";
vector<int> startAt[MAX],endAt[MAX];
int n,lim,len;
int ans[MAX];
map<int,int> cnt;
void init(void) {
    scanf("%d%d%d",&n,&lim,&len);
    FOR(i,1,n) {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        int t=h*3600+m*60+s;
        startAt[t].push_back(i);
        endAt[t+len].push_back(i);
    }
}
void add(int x) {
    cnt[x]++;
}
void rem(int x) {
    if (--cnt[x]==0) cnt.erase(x);
}
void process(void) {
    bool equ=false;
    int res=0;
    int prev=0;
    FOR(i,0,MAX/2) {
        FORE(it,endAt[i]) rem(ans[*it]);
        FORE(it,startAt[i]) {
            ans[*it]=cnt.size()<lim?++res:prev;
            add(ans[*it]);
            prev=ans[*it];
            equ|=cnt.size()==lim;
        }
    }
    if (!equ) {
        printf("%s\n",noSol);
        return;
    }
    printf("%d\n",res);
    FOR(i,1,n) printf("%d\n",ans[i]);
}
int main(void) {
    init();
    process();
    return 0;
}