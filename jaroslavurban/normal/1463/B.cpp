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
		ll s1=0,s2=0;
		for(int i=0;i<n;++i)if(i%2)s1+=a[i];
		else s2+=a[i];
		for(int i=0;i<n;++i)
			if((i%2&&s1<s2)||(i%2==0&&s2<=s1))cout<<1<<" ";
			else cout<<a[i]<<" ";
		cout<<endl;
	}
}