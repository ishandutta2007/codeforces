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

int n,m,k,t,a[N],b[N],dp[N];

bool check(int x,int y){
	while(x<y) x*=k;
	return x==y;
}
int calc(int x){
	while(x%k==0) x/=k;
	return x;
}
void Main(){
	cin>>n>>k;
	vector<pair<int,int>> A,B;
	f(i,0,n){
		cin>>a[i];
		if(A.size()==0 || calc(a[i])!=A.back().F){
			A.pb({calc(a[i]),0});
		}
		A.back().S+=a[i]/calc(a[i]);
	}
	cin>>m;
	f(i,0,m){
		cin>>b[i];
		if(B.size()==0 || calc(b[i])!=B.back().F){
			B.pb({calc(b[i]),0});
		}
		B.back().S+=b[i]/calc(b[i]);
	}
	if(A==B){
		cout<<"Yes"<<'\n';
	}
	else{
		cout<<"NO"<<'\n';
	}
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
5 2
1 2 2 4 2
4
1 4 4 2
*/