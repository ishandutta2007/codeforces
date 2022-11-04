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
		if(n==1){cout<<9<<endl;continue;}
		if(n==2){cout<<98<<endl;continue;}
		if(n==3){cout<<989<<endl;continue;}
		string s="989";
		for(int i=0;i<n-3;++i)s+=(i%10)+'0';
		cout<<s<<endl;
	}
}