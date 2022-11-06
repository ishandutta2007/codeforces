#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		string s;
		int n;cin>>n>>s;
		vector<int>done(256);
		bool sus=false;
		for(int i=0;i<n;++i)if(i&&done[s[i]]&&s[i]!=s[i-1])sus=true;
		else done[s[i]]=true;
		if(sus)cout<<"NO\n";
		else cout<<"YES\n";
	}
}