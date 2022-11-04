#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=404;
int INV[N];
int n,m;

ll powmod(ll a,ll b){
	if(!b)return 1;
	if(b&1)return a*powmod(a*a%m,b/2)%m;
	return powmod(a*a%m,b/2);
}

ll inv(int x){
	return powmod(x,m-2);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<N;++i)INV[i]=inv(i);
	vector<vector<int>>dp1(n+2,vector<int>(n+2));
	dp1[0][0]=1;
	for(int i=0;i<=n;++i){
		vector<vector<int>>dp2(n+2,vector<int>(n+2));
		for(int k=0;k<=n;++k){
			dp2[1][k+1]=dp1[0][k]*ll(k+1)%m;
			for(int j=1;j<=n;++j)
				if(dp1[j][k]){
					dp2[j+1][k+1]=dp1[j][k]*2*ll(k+1)%m*INV[j+1]%m;
					dp2[0][k]=(dp2[0][k]+dp1[j][k])%m;
				}
		}
		swap(dp1,dp2);
	}
	cout<<accumulate(dp1[0].begin(),dp1[0].end(),0ll)%m<<endl;
}