#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

template<typename T>
struct SparseTable{
	int n,p;
	vector<vector<T>>dp;
	vector<int>lg;
	SparseTable(vector<T>a):n(a.size()),p(log2(n)+1),dp(p,vector<T>(n)),lg(n+1){
		dp[0]=a;
		for(int i=2;i<=n;++i)lg[i]=lg[i/2]+1;
		for(int i=1;i<p;++i)
			for(int j=0,j2=(1<<(i-1));j2<n;++j,++j2)
				dp[i][j]=T::uni(dp[i-1][j],dp[i-1][j2]);
	}
	// inclusive, exclusive
	T query(int l,int r){
		int x=lg[r-l];
		return T::uni(dp[x][l],dp[x][r-(1<<x)]);
	}
};

struct gcdq{
	typedef ll T;
	static const T D=0;
	T x;
	gcdq(T x=D):x(x){}
	operator T(){return x;}
	static gcdq uni(gcdq a,gcdq b){return gcdq(__gcd(a.x,b.x));}

};


void ProGamerMove(){
	int n;cin>>n;
	vector<ll>a(n);
	for(auto&v:a)cin>>v;
	if(n==1){cout<<"1\n";return;}
	vector<gcdq>tmp(n-1);
	for(int i=0;i+1<n;++i)tmp[i]=abs(a[i]-a[i+1]);
	SparseTable<gcdq>st(tmp);
	int res=1;
	for(int i=0;i<n;++i){
		int l=i+1,r=n;
		while(l<r){
			int m=(l+r)/2;
			if(st.query(i,m).x==1)r=m;
			else l=m+1;
		}
		res=max(res,l-i);
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}