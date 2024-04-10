#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
const int M=1000006;
int f[M],inv[M];
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
	f[0]=1;
	rep(i,1,M){
		f[i]=(1LL*i*f[i-1])%hell;
	}
	inv[M-1]=expo(f[M-1],hell-2,hell);
	for(int i=M-2;i>=0;i--){
		inv[i]=(1LL*(i+1)*inv[i+1])%hell;
	}
}
int C(int n,int r){
    if(n<r || n<0 || r<0) return 0;
	return (1LL*((1LL*f[n]*inv[r])%hell)*inv[n-r])%hell;
}
int g(int n,int m,int k){
    if(n==0 and m==0) return 1;
    return C(n+m-k*n-1,m-k*n);
}
void solve(){
    compute();
    int f,w,h,num=0,denom=0;
    cin>>f>>w>>h;
    int mx=2*max(f,w)+1;
    rep(l,1,mx+1){
        if(l%2==0){
            num=(num+g(l/2,f,1)*g(l/2,w,h+1))%hell;
            denom=(denom+g(l/2,f,1)*g(l/2,w,1))%hell;
            num=(num+g(l/2,f,1)*g(l/2,w,h+1))%hell;
            denom=(denom+g(l/2,f,1)*g(l/2,w,1))%hell;
        }
        else{
            num=(num+g(l/2+1,f,1)*g(l/2,w,h+1))%hell;
            denom=(denom+g(l/2+1,f,1)*g(l/2,w,1))%hell;
            num=(num+g(l/2,f,1)*g(l/2+1,w,h+1))%hell;
            denom=(denom+g(l/2,f,1)*g(l/2+1,w,1))%hell;
        }
    }
    cout<<(num*expo(denom,hell-2,hell))%hell<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}