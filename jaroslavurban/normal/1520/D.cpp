#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		unordered_map<int,int>mp;
		ll res=0;
		for(int i=0;i<n;++i){
			int a;cin>>a;
			res+=mp[a-i]++;
		}
		cout<<res<<"\n";
	}
}