#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		auto counted=[&](int i){
			return i&&i<n-1&&((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]));
		};
		int hills=0;
		for(int i=1;i<n-1;++i)if(counted(i))++hills;
		int bst=hills;
		for(int i=1;i<n-1;++i){
			int prev=counted(i-1)+counted(i)+counted(i+1);
			int pr=a[i];
			a[i]=a[i-1];
			bst=min(bst,hills-prev+counted(i-1)+counted(i)+counted(i+1));
			a[i]=a[i+1];
			bst=min(bst,hills-prev+counted(i-1)+counted(i)+counted(i+1));
			a[i]=a[i-1]+1;
			bst=min(bst,hills-prev+counted(i-1)+counted(i)+counted(i+1));
			a[i]=a[i+1]+1;
			bst=min(bst,hills-prev+counted(i-1)+counted(i)+counted(i+1));
			a[i]=a[i-1]-1;
			bst=min(bst,hills-prev+counted(i-1)+counted(i)+counted(i+1));
			a[i]=a[i+1]-1;
			bst=min(bst,hills-prev+counted(i-1)+counted(i)+counted(i+1));
			a[i]=pr;
		}
		cout<<bst<<endl;
	}
}