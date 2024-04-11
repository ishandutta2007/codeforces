#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99,inf=1e9+99;

int n,t,m,a[N];

void Main(){
	cin>>m>>n;
	f(i,0,n){
		cin>>a[i];
		a[i]--;
	}
	if(n==1){
		cout<<2<<'\n';
		return ;
	}
	sort(a,a+n);
	vector<int> vec;
	int ans=0;
	f(i,0,n){
		vec.pb((a[(i+1)%n]-a[i]+m)%m-1);
	}
	sort(all(vec));
	reverse(all(vec));
	int cnt=0;
	f(i,0,vec.size()){
		if(vec[i]==cnt+1 || vec[i]==cnt+2){
			ans++;
			cnt+=2;
		}
		if(vec[i]>cnt+1){
			ans+=max(0ll,vec[i]-cnt-1);
			cnt+=4;
		}
		//eror(ans);
	}
	cout<<m-ans<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
20 3
3 7 12
*/