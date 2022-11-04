#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	srand(time(0));
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;n*=2;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		bool found=false;
		do{
			random_shuffle(a.begin(),a.end());
			found=false;
			for(int i=0;i<n;++i)if(2*a[(i+1)%n]==a[i]+a[(i+2)%n]){found=true;break;}
		}while(found);
		for(int i=0;i<n;++i)cout<<a[i]<<" ";cout<<"\n";
	}
}