//This solution is based on stevenkplus's solution
#include<bits/stdc++.h>
#define MAX   100100
#define LIM   3333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int a[MAX],b[MAX],n,d,x;
inline int NextX(void) {
    x=(37LL*x+10007)%(int(1e9)+7);
    return (x);
}
void generate(void) {
    cin>>n>>d>>x;
    REP(i,n) a[i]=i+1;
    REP(i,n) swap(a[i],a[NextX()%(i+1)]);
    REP(i,n) b[i]=i<d;
    REP(i,n) swap(b[i],b[NextX()%(i+1)]);
}
void small(void) {
    vector<int> id;
    REP(i,n) if (b[i]) id.push_back(i);
    REP(i,n) {
        int ans=0;
        FORE(it,id) {
            if (*it>i) break;
            ans=max(ans,a[i-*it]);
        }
        printf("%d\n",ans);
    }
}
bool cmp(int x,int y) {
    return (a[x]>a[y]);
}
void big(void) {
    vector<int> pos;
    REP(i,n) pos.push_back(i);
    sort(pos.begin(),pos.end(),cmp);
    REP(i,n) {
        int ans=0;
        FORE(it,pos) if (*it<=i && b[i-*it]) {
            ans=a[*it];
            break;
        }
        printf("%d\n",ans);
    }
}
int main(void) {
    generate();
    if (d<LIM) small(); else big();
    return 0;
}