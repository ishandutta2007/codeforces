#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

template<typename O>
struct SparseTable{
	using T=typename O::T;
	int n,p;
	vector<vector<T>>dp;
	vector<int>lg;
	SparseTable(vector<T>a={1}):n(a.size()),p(log2(n)+1),dp(p,vector<T>(n)),lg(n+1){
		dp[0]=a;
		for(int i=2;i<=n;++i)lg[i]=lg[i/2]+1;
		for(int i=1;i<p;++i)
			for(int j=0,j2=(1<<(i-1));j2<n;++j,++j2)
				dp[i][j]=O::uni(dp[i-1][j],dp[i-1][j2]);
	}
	// inclusive, exclusive
	T query(int l,int r){
		int x=lg[r-l];
		return O::uni(dp[x][l],dp[x][r-(1<<x)]);
	}
};

struct maxq{
	typedef ll T;
	static const T D=0;
	static T uni(T a,T b){return max(a,b);}
};

struct minq{
	typedef ll T;
	static const T D=0;
	static T uni(T a,T b){return min(a,b);}
};


void ProGamerMove(){
	int n,q;cin>>n>>q;
	vector<int>a(n),b(n);
	vector<ll>pref(n+1);
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];
	for(int i=1;i<=n;++i)pref[i]=pref[i-1]+b[i-1]-a[i-1];
	SparseTable<maxq>maxst(pref);
	SparseTable<minq>minst(pref);
	for(int l,r;q--;){
		cin>>l>>r;++r;
		if(pref[r-1]-pref[l-1]||minst.query(l,r)-pref[l-1]<0){cout<<"-1\n";continue;}
		ll mx=maxst.query(l,r);
		cout<<mx-pref[l-1]<<"\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}