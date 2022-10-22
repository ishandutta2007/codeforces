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

const int N=1e6+99;

int n,m,t,a[N],ans[N];
string s;

void Main(){
	cin>>n>>s;
	f(i,0,n) a[i]=s[i]-'0';
	if(s[0]!='9'){
		f(i,0,n){
			cout<<'9'-s[i];
		}
		cout<<'\n';
		return ;
	}
	if(a[n-1]>1) ans[n-1]=11-a[n-1],a[n-2]++;
	else ans[n-1]=1-a[n-1];
	f_(i,n-2,0){
		if(a[i]<=1) ans[i]=1-a[i];
		else{
			ans[i]=11-a[i];
			
			if(i!=0) a[i-1]++;
		}
	}
	while(a[0]<2) ans[0]++,a[0]++;
	f(i,0,n) cout<<ans[i]; cout<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}