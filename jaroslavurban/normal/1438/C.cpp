#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=110;
int f[N][N];
bool done[N][N];
int n,m;


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>m;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				cin>>f[i][j];
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				done[i][j]=false;
		vector<int>nums(n*m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				nums[i*m+j]=f[i][j];
		sort(nums.begin(),nums.end());
		int k=unique(nums.begin(),nums.end())-nums.begin();
		for(int r=0;r<k;++r)
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
					if(f[i][j]==nums[r]&&!done[i][j]){
						done[i][j]=true;
						if(r%2)f[i][j]+=(i+j)%2;
						else f[i][j]+=!((i+j)%2);
					}
		for(int i=0;i<n;++i,cout<<endl)
			for(int j=0;j<m;++j)
				cout<<f[i][j]<<" ";
	}	
}