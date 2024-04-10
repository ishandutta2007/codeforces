#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		if(n==2){cout<<"-1\n";continue;}
		int cur=1;
		vector<vector<int>>res(n,vector<int>(n));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if((i+j)&1)
					res[i][j]=cur++;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(!((i+j)&1))
					res[i][j]=cur++;
		for(int i=0;i<n;++i,cout<<"\n")
			for(int j=0;j<n;++j)
				cout<<res[i][j]<<" ";
	}
}