#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;cin>>s;
		int n=s.size();
		string res,over;over+=s[0];
		int p1=0,p2=1;
		while(p2!=n){
			while(p2<n&&s[p2]%2==over[p1]%2)over+=s[p2++];
			if(p2<n){
				while(p1<over.size()&&over[p1]<s[p2])res+=over[p1++];
				if(p1==over.size())over+=s[p2++];
				else res+=s[p2++];
			}
		}
		res+=over.substr(p1,over.size()-p1);
		cout<<res<<endl;
	}
}