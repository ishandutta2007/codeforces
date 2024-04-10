#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		pair<int,int>mn={INT_MAX,0};
		for(int i=0;i<n;++i)mn=min(mn,{a[i],i});
		cout<<n-1<<"\n";
		for(int i=0;i<n;++i)if(i!=mn.second){
			if((i&1)==(mn.second&1))cout<<i+1<<" "<<mn.second+1<<" "<<mn.first<<" "<<mn.first<<"\n";
			else cout<<i+1<<" "<<mn.second+1<<" "<<mn.first+1<<" "<<mn.first<<"\n";
		}
	}
}