#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,x;cin>>n>>x;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		int ms=accumulate(a.begin(),a.end(),0);
		int same=x%a[0]==0;
		for(int i=0;i<n-1;++i)if(a[i]!=a[i+1])same=0;
		if((same&&ms>x)||ms==x)cout<<"NO\n";
		else{
			sort(a.begin(),a.end());
			cout<<"YES\n";
			int sm=0;
			for(int i=0;i<a.size();++i)if(sm+a[i]==x){
				assert(i!=n-1);
				cout<<a.back()<<" ";
				sm+=a.back();
				a.pop_back();
				--i;
			}else{
				cout<<a[i]<<" ";
				sm+=a[i];
			}
			cout<<"\n";
		}
	}
}