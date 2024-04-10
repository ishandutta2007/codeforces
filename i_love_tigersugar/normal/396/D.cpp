#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const int mod=(int)1e9+7;
class BIT {
    private:
    int n;
    vector<int> v;
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v=vector<int>(n+7,0);
    }
    void update(int x) {
        for (;x<=n;x+=x&(-x)) v[x]++;
    }
    int lower(int x) const {
        int ret=0;
        for (;x>=1;x=x&(x-1)) ret+=v[x];
        return (ret);
    }
    int upper(int x) const {
        if (x>n) return (0);
        return (lower(n)-lower(x-1));
    }
};
BIT bit;
int n;
int p[MAX],frac[MAX],ninv[MAX];
void process(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&p[i]);
    bit=BIT(n);
    frac[0]=1;
    FOR(i,1,n) frac[i]=1LL*frac[i-1]*i%mod;
    ninv[2]=1;
    FOR(i,3,n) ninv[i]=(1LL*ninv[i-1]*i%mod+1LL*(i-1)*i/2%mod*frac[i-1]%mod)%mod;
    //FOR(i,2,n) printf("%d ",ninv[i]); printf("\n");
    int res=0;
    int left=0;
    int between=0;
    FOR(i,1,n) {
        //printf("AT %d\n",i);
        if (i>1) {
            int del=bit.upper(p[i-1]+1);
            left=(left+del)%mod;
            between=(between-del+mod)%mod;
            between=(between+p[i-1]-1-bit.lower(p[i-1]-1))%mod;
            bit.update(p[i-1]);
        }
        int k=p[i]-1-bit.lower(p[i]-1);
        int mid=1LL*k*(k-1)/2%mod;       
        //printf("left %d between %d\n",left,between);
        int more=(left+between)%mod;
        int nperm=1LL*k*frac[n-i]%mod;
        res=(res+1LL*more*nperm%mod+1LL*mid*frac[n-i]%mod+1LL*k*ninv[n-i]%mod)%mod;
        //printf("Current %d\n",res);
    }
    left=(left+bit.upper(p[n]+1))%mod;
    res=(res+left)%mod;
    printf("%d",res);
}
int main(void) {
    process();
    return 0;
}