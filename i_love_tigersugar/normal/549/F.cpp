#include<bits/stdc++.h>
#define MAX   300300
#define MAXV   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,mod,a[MAX],sum[MAX],cnt[MAXV];
void init(void) {
    scanf("%d%d",&n,&mod);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) sum[i]=(sum[i-1]+a[i])%mod;
}
int value(int l,int r) {
    int sum=0;
    int maxVal=a[l];
    FOR(i,l,r) {
        sum=(sum+a[i])%mod;
        maxVal=max(maxVal,a[i]);
    }
    return ((sum-maxVal%mod+mod)%mod);
}
long long countPair(int l,int r) {
    if (r-l<=4) {
        int res=0;
        FOR(i,l,r) FOR(j,i+1,r) if (value(i,j)==0) res++;
        return (res);
    }
    int m=(l+r)>>1;
    int maxVal=a[m];
    int j=m;
    long long res=0;
    FORD(i,m,l) {
        maxVal=max(maxVal,a[i]);
        while (j<r && a[j+1]<=maxVal) {
            j++;
            cnt[(sum[j]-sum[m]+mod)%mod]++;
        }
        int val=((sum[m]-sum[i-1]-maxVal)%mod+mod)%mod;
        res+=cnt[(mod-val%mod)%mod];
    }
    FOR(i,m+1,r) cnt[(sum[i]-sum[m]+mod)%mod]=0;
    j=m+1;
    maxVal=a[m+1];
    FOR(i,m+1,r) {
        maxVal=max(maxVal,a[i]);
        while (j>l && a[j-1]<maxVal) {
            j--;
            cnt[(sum[m]-sum[j-1]+mod)%mod]++;
        }
        int val=((sum[i]-sum[m]-maxVal)%mod+mod)%mod;
        res+=cnt[(mod-val%mod)%mod];
    }
    FOR(i,l,m) cnt[(sum[m]-sum[i-1]+mod)%mod]=0;
    return (res+countPair(l,m)+countPair(m+1,r));
}
void process(void) {
    cout<<countPair(1,n)<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}