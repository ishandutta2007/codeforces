#include<cstdio>
#include<iostream>
#define MAX   200200
#define LOG   18
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
#define MASK(i) (1<<(i))
using namespace std;
typedef long long ll;
const int INF=(int)2e9+7;
struct Item {
    int pos,len;
    Item() {
        pos=len=0;
    }
    void input(void) {
        scanf("%d%d",&pos,&len);
    }
};
Item item[MAX];
int lg2[MAX];
int minPrevToFree[MAX][LOG+1];
int maxSum[MAX][LOG+1];
pair<int,ll> nextBuy[MAX][LOG+1];
int n,q;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) item[i].input();
    FOR(i,1,n) {
        while (MASK(lg2[i])<=i) lg2[i]++;
        lg2[i]--;
    }
}
void countMaxSum(void) {
    FOR(i,1,n) maxSum[i][0]=item[i].pos+item[i].len;
    FOR(j,1,LOG) FOR(i,1,n-MASK(j)+1) maxSum[i][j]=max(maxSum[i][j-1],maxSum[i+MASK(j-1)][j-1]);
}
int getMaxSum(int l,int r) {
    if (l>r) return (-INF);
    int k=lg2[r-l+1];
    return (max(maxSum[l][k],maxSum[r-MASK(k)+1][k]));
}
int findPrevToFree(int x) {
    if (item[x].pos+item[x].len>=item[x+1].pos) return (x);
    if (getMaxSum(1,x)<item[x+1].pos) return (0);
    int L=1;
    int R=x;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (getMaxSum(R,x)>=item[x+1].pos?R:L);
        int M=(L+R)>>1;
        if (getMaxSum(M,x)>=item[x+1].pos) L=M; else R=M-1;
    }
}
void countPrevToFree(void) {
    FOR(i,1,n-1) minPrevToFree[i][0]=findPrevToFree(i);
    //FOR(i,1,n-1) printf("jump at %d need prev %d\n",i,prevToFree[i]);
    FOR(j,1,LOG) FOR(i,1,n-1-MASK(j)+1)
        minPrevToFree[i][j]=min(minPrevToFree[i][j-1],minPrevToFree[i+MASK(j-1)][j-1]);
}
int getMinPrevToFree(int l,int r) {
    if (l>r) return (INF);
    int k=lg2[r-l+1];
    return (min(minPrevToFree[l][k],minPrevToFree[r-MASK(k)+1][k]));
}
int findNextFree(int i) {
    if (item[i].pos+item[i].len<item[i+1].pos) return (i);
    if (getMinPrevToFree(i,n-1)>=i) return (n);
    int L=i;
    int R=n;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (getMinPrevToFree(i,R-1)>=i?R:L);
        int M=(L+R)>>1;
        if (getMinPrevToFree(i,M-1)>=i) L=M; else R=M-1;
    }
}
void countNextBuy(void) {
    nextBuy[n][0]=make_pair(n,0);
    FOR(i,1,n-1) {
        int j=findNextFree(i);
        if (j<n) {
            nextBuy[i][0].fi=j+1;
            nextBuy[i][0].se=item[j+1].pos-getMaxSum(i,j);
        } else nextBuy[i][0]=make_pair(n,0);
    }
    FOR(j,1,LOG) FOR(i,1,n) {
        nextBuy[i][j].fi=nextBuy[nextBuy[i][j-1].fi][j-1].fi;
        nextBuy[i][j].se=nextBuy[nextBuy[i][j-1].fi][j-1].se+nextBuy[i][j-1].se;
    }
}
ll answer(int l,int r) {
    ll res=0;
    FORD(i,LOG,0) if (nextBuy[l][i].fi<=r) {
        res+=nextBuy[l][i].se;
        l=nextBuy[l][i].fi;
    }
    return (res);
}
void process(void) {
    scanf("%d",&q);
    REP(love,q) {
        int l,r;
        scanf("%d%d",&l,&r);
        cout<<answer(l,r)<<"\n";
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif // ONLINE_JUDGE
    init();
    countMaxSum();
    countPrevToFree();
    countNextBuy();
    process();
    return 0;
}