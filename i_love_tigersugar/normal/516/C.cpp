#include<bits/stdc++.h>
#define MAX   200200
#define LOG   18
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define MASK(i) (1<<(i))
#define fi   first
#define se   second
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
int d[MAX],h[MAX],lg2[MAX];
ll s[MAX];
int n,q;
bool CompAdd(const int &x,const int &y) {
    if (x<0) return (false);
    if (y<0) return (true);
    if (s[x]+2LL*h[x]==s[y]+2LL*h[y]) return (x<y);
    return (s[x]+2LL*h[x]>s[y]+2LL*h[y]);
}
bool CompSub(const int &x,const int &y) {
    if (x<0) return (false);
    if (y<0) return (true);
    if (-s[x]+2LL*h[x]==-s[y]+2LL*h[y]) return (x<y);
    return (-s[x]+2LL*h[x]>-s[y]+2LL*h[y]);
}
pair<int,int> rmqAdd[MAX][LOG+1];
pair<int,int> rmqSub[MAX][LOG+1];
template<class Compare>
    void update(pair<int,int> &a,int b,Compare Comp) {
        if (a.fi==b || a.se==b) return;
        if (Comp(b,a.fi)) {
            a.se=a.fi;
            a.fi=b;
        } else if (Comp(b,a.se)) a.se=b;
    }
template<class Compare>
    void mergeSet(const pair<int,int> &a,const pair<int,int> &b,Compare Comp,pair<int,int> &res) {
        res=a;
        update(res,b.fi,Comp);
        update(res,b.se,Comp);
    }
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&d[i]);
    FOR(i,1,n) scanf("%d",&h[i]);
    FOR(i,2,n+1) s[i]=s[i-1]+d[i-1];
    FOR(i,n+2,2*n) s[i]=s[i-1]+d[i-n-1];
    FOR(i,1,n) h[i+n]=h[i];
}
void setupRMQ(void) {
    FOR(i,1,2*n) {
        rmqAdd[i][0]=make_pair(i,-1);
        rmqSub[i][0]=make_pair(i,-1);
    }
    FOR(j,1,LOG) FOR(i,1,2*n-MASK(j)+1) {
        mergeSet(rmqAdd[i][j-1],rmqAdd[i+MASK(j-1)][j-1],CompAdd,rmqAdd[i][j]);
        mergeSet(rmqSub[i][j-1],rmqSub[i+MASK(j-1)][j-1],CompSub,rmqSub[i][j]);
    }
    FOR(i,1,2*n) {
        while (MASK(lg2[i])<=i) lg2[i]++;
        lg2[i]--;
    }
}
ll costJump(int i,int j) {
    return (2LL*h[i]+2LL*h[j]+s[i]-s[j]);
}
ll bestChoose(const pair<int,int> &add,const pair<int,int> &sub) {
    //cerr<<add.fi<<" "<<add.se<<endl;
    //cerr<<sub.fi<<" "<<sub.se<<endl;
    ll res=-INF;
/*    printf("finding best\n");
    printf("add set: ");
    FORE(it,add) printf("%d ",*it); printf("\n");
    printf("sub set: ");
    FORE(it,sub) printf("%d ",*it); printf("\n");*/
    if (add.fi>0 && sub.fi>0 && add.fi!=sub.fi) res=max(res,costJump(add.fi,sub.fi));
    if (add.fi>0 && sub.se>0 && add.fi!=sub.se) res=max(res,costJump(add.fi,sub.se));
    if (add.se>0 && sub.fi>0 && add.se!=sub.fi) res=max(res,costJump(add.se,sub.fi));
    if (add.se>0 && sub.se>0 && add.se!=sub.se) res=max(res,costJump(add.se,sub.se));
    return (res);
}
ll answer(int l,int r) {
    //printf("Answering %d %d\n",l,r);
    int k=lg2[r-l+1];
    pair<int,int> va,vs;
    mergeSet(rmqAdd[l][k],rmqAdd[r-MASK(k)+1][k],CompAdd,va);
    mergeSet(rmqSub[l][k],rmqSub[r-MASK(k)+1][k],CompSub,vs);
    return (bestChoose(va,vs));
}
void process(void) {
    REP(love,q) {
        int l,r;
        scanf("%d%d",&l,&r);
        if (l<=r) cout<<answer(r+1,l+n-1)<<"\n";
        else cout<<answer(r+n+1,l+n-1)<<"\n";
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif // ONLINE_JUDGE
    init();
    setupRMQ();
    process();
    return 0;
}