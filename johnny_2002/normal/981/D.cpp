#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const int N=60;

int f[N][N];
int n,k;
long long a[N];
long long psum[N];
bool check(ll ans){
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int en=1;en<=n;en++)
                for(int st=en-1;st>=0;st--)
                        if (((psum[en]-psum[st])&ans)==ans){
                                for(int use=1;use<=k;use++)
                                        f[en][use]|=f[st][use-1];
                        }
        return f[n][k];
        
}
int main(){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) psum[i]=psum[i-1]+a[i];
        long long ans=0;
        for(int i=60;i>=0;i--)
                if (check(ans+(1LL<<i))) ans+=1LL<<i;
        cout<<ans;
}