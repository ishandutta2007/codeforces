#include <bits/stdc++.h>
#define ll          long long
#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
ll expo(ll base, ll exponent, ll mod) {								//return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
int n,a[1000006],f[1000006];
void solve(){
    int ans=0;
	f[0]=1;
	rep(i,1,1000003){
		f[i]=(i*f[i-1])%hell;
	}
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}	
	sort(a,a+n);
	int i=1;
	while(i<n){
		int cnt=1;
		while(i<n && a[i]==a[i-1]) i++,cnt++;	
		if(i-1==n-1) break;
		int cur=(a[i-1]*cnt)%hell;
		cur=(cur*expo(n-i+cnt,hell-2,hell))%hell;
		ans=(ans+cur)%hell;
		i++;
	}
	cout<<(f[n]*ans)%hell;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}