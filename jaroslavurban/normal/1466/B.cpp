#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a.begin(),a.end());
		int last=1e9;
		int res=0;
		for(int i=n-1;i>=0;--i){
			if(a[i]+1==last){
				++res;
				last=a[i];
				continue;
			}
			if(a[i]==last)continue;
			last=a[i]+1;
			++res;
		}
		cout<<res<<endl;
	}
}