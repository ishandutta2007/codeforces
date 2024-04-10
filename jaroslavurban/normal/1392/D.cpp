#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=200010,inf=1e9,M=2;
ll n;
string s;
ll dp[N][2][2]; // pos, prev: left/right attacked/not attacked
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>s;
//		dp[0][0][0]=s[n-1]=='L';
//		dp[0][0][1]=s[n-1]=='R';
//		dp[0][1][0]=s[n-1]=='L';
//		dp[0][1][1]=s[n-1]=='R';
		char c1=s[n-2],c2=s[n-1];
		ll res=inf;
		for(int j=0;j<4;++j){
			for(int i=0;i<=n;++i)	
				for(int j=0;j<M;++j)
					for(int k=0;k<M;++k)
						dp[i][j][k]=inf;

			if(j==0){
				dp[0][0][0]=(c1!='R')+(c2!='L');
				s[n-2]='R';s[n-1]='L';
			}
			if(j==1){
				dp[0][0][1]=(c1!='L')+(c2!='L');
				s[n-2]='L';s[n-1]='L';
			}
			if(j==2){
				dp[0][1][0]=(c1!='R')+(c2!='R');
				s[n-2]='R';s[n-1]='R';
			}
			if(j==3){
				dp[0][1][1]=(c1!='L')+(c2!='R');
				s[n-2]='L';s[n-1]='R';
			}

			for(int i=0;i<n;++i){
				dp[i+1][0][0]=min({dp[i+1][0][0],dp[i][1][0]+(s[i]!='L'),dp[i][1][1]+(s[i]!='L')});
				dp[i+1][0][1]=min({dp[i+1][0][1],dp[i][0][0]+(s[i]!='L')});
				dp[i+1][1][0]=min({dp[i+1][1][0],dp[i][1][1]+(s[i]!='R')});
				dp[i+1][1][1]=min({dp[i+1][1][1],dp[i][0][0]+(s[i]!='R'),dp[i][0][1]+(s[i]!='R')});
			}
//			if(j==2){
//				for(int i=0;i<=n;++i)cerr<<dp[i][1][1]<<" ";cerr<<endl;
//			}
			if(j==0)res=min(res,dp[n][0][0]);
			if(j==1)res=min(res,dp[n][0][1]);
			if(j==2)res=min(res,dp[n][1][0]);
			if(j==3)res=min(res,dp[n][1][1]);
		}
		cout<<res<<endl;
	}
}