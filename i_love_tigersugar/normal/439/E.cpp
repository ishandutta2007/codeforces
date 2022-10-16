#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int mod=(int)1e9+7;
bool notprime[MAX];
int frac[MAX],finv[MAX],pro[MAX];
vector<int> prime;
void eratosthene(void) {
    REP(i,2) notprime[i]=true;
    FOR(i,2,MAX-1) if (!notprime[i]) {
        prime.push_back(i);
        for (int j=2*i;j<MAX;j=j+i) notprime[j]=true;
    }
}
void backtrack(bool mode,int id,int pr) {
    pro[pr]=mode?-1:1;
    FOR(i,id+1,prime.size()-1) {
        if (1LL*pr*prime[i]<1LL*MAX) backtrack(!mode,i,pr*prime[i]);
        else return;
    }
}
inline int inverse(int x) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void precount(void) {
    frac[0]=finv[0]=1;
    FOR(i,1,MAX-1) {
        frac[i]=1LL*frac[i-1]*i%mod;
        finv[i]=inverse(frac[i]);
    }
}
inline int comb(int k,int n) {
    if (k>n) return (0);
    return (1LL*frac[n]*finv[k]%mod*finv[n-k]%mod);
}
void update(int n,int f,int k,int &res) {
    assert(n%k==0);
    if (pro[k]==0) return;
    if (pro[k]>0) res=(res+comb(f-1,n/k-1))%mod;
    else res=(res-comb(f-1,n/k-1)+mod)%mod;
}
int answer(int n,int f) {
    int res=0;
    FOR(i,1,n+7) {
        if (1LL*i*i>n) return (res);
        if (n%i==0) {
            update(n,f,i,res);
            if (1LL*i*i<n) update(n,f,n/i,res);
        }
    }
}
void process(void) {
    int q;
    scanf("%d",&q);
    REP(zz,q) {
        int n,f;
        scanf("%d%d",&n,&f);
        printf("%d\n",answer(n,f));
    }
}
int main(void) {
    eratosthene();
    backtrack(false,-1,1);
    precount();
    process();
    return 0;
}