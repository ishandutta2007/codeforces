#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>s;
		int res=0;
		for(int i=1;i<n;++i)if(s[i-1]%2==s[i]%2)++res;
		cout<<(res+1)/2<<endl;
	}
}