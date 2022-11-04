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
		vector<int>good(26);
		int cnt=1;
		for(int i=1;i<n;++i){
			if(s[i]==s[i-1])++cnt;
			else{
				if(cnt%2)good[s[i-1]-'a']=1;
				cnt=1;
			}
		}
		if(cnt%2)good[s.back()-'a']=1;
		for(int i=0;i<26;++i)if(good[i])cout<<char(i+'a');
		cout<<endl;
	}
}