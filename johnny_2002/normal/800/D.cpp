#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=1e6;
const int MOD=1e9+7;


int h[N+5];
ll p2[N+5],p10[12];


struct info{
    int sum,sumsq,n;
    info(int _sum=0,int _sumsq=0,int _n=0){
        sum=_sum;
        sumsq=_sumsq;
        n=_n;
    }
    info operator +(const info &oth){
        return info((sum+oth.sum)%MOD,(sumsq+oth.sumsq)%MOD,(n+oth.n)%MOD);
    }
    info operator -(const info &oth){
        return info((sum-oth.sum+MOD)%MOD,(sumsq-oth.sumsq+MOD)%MOD,(n-oth.n+MOD)%MOD);
    }
};
info f[N+5];

int ans[N+5];
int bi[64];
int a10[64],mask[N];
int redir(int val,int bit){
    if (mask[val]&bit) return -1;
    return val+a10[bit];
}


ll solve(){
    for(int j=1;j<64;j++) {
        bi[j]=bi[j>>1]+(j&1);
        for(int i=0;i<6;i++) if (j&(1<<i)) a10[j]+=p10[i];
    }
    for(int i=1;i<N;i++){
        for(int cur=i,j=0;cur;j++,cur/=10) if (cur%10==9) mask[i]+=1<<j;
    }
    for(int i=N-1;i>=1;i--){
        f[i]=info(1LL*h[i]*i%MOD,1LL*h[i]*i%MOD*i%MOD,h[i]);
        for(int j=1;j<64;j++){
            int pos=redir(i,j);
            if (pos!=-1){
                if (bi[j]&1) f[i]=f[i]+f[pos];
                else f[i]=f[i]-f[pos];
            }
        }
    }
//    cout<<f[123].sum<<" "<<f[123].sumsq<<" "<<f[123].n<<'\n';
    for(int i=1;i<N;i++) if (f[i].n) {
        if (f[i].n==1) ans[i]=f[i].sumsq;
        else ans[i]=p2[f[i].n-2]*(f[i].sumsq+1LL*f[i].sum*f[i].sum%MOD)%MOD;
    }
    ll res=0;
    for(int i=1;i<N;i++){
        for(int j=1;j<64;j++){
            int pos=redir(i,j);
            if (pos!=-1){
                if (bi[j]&1) ans[i]=(ans[i]-ans[pos]+MOD)%MOD;
                else ans[i]=(ans[i]+ans[pos])%MOD;
            }
        }
        res^=1LL*i*ans[i];
    }
    return res;
}
int main(){
    p2[0]=1;
    for(int i=1;i<=N;i++) p2[i]=p2[i-1]*2%MOD;
    p10[0]=1;
    for(int i=1;i<=10;i++) p10[i]=p10[i-1]*10%MOD;
    ///
    int n;
    scanf("%d",&n);
    while (n--){
        int x;
        scanf("%d",&x);
        h[x]++;
    }
    cout<<solve();
}