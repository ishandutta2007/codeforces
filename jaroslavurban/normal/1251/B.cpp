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
		int sm0=0,sm1=0,odd=0;
		for(int i=0;i<n;++i){
			string s;cin>>s;
			odd+=s.size()%2;
			for(int j=0;j<s.size();++j)if(s[j]=='0')++sm0;
			else ++sm1;
		}
		if(!odd&&sm0%2)cout<<n-1<<endl;
		else cout<<n<<endl;
	}
}