#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int x){
	for(int i = 2; i*i<=x; i++){
		if(x%i==0){
			return true;
		}
	}
	return false;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = (int)1e18;
		//bool f = false;
		for(int i = 2; i<10; i++){
			//if(f)break;
			if(count(s.begin(),s.end(),'0'+i)>=2){
				//f = true;
				ans = min(ans,i*11);
			}
		}
		//if(f)continue;
		for(int i = 1; i<10; i++){
			if(i==2||i==3||i==5||i==7)continue;
			//if(f)break;
			if(count(s.begin(),s.end(),'0'+i)>0){
				//f = true;
				ans = min(ans,i);
			}
		}
		//if(f)continue;
		//assert(s.size()<=4);
		if(n<=4)
		for(int i = 1; i<(1<<n); i++){
			string v = "";
			for(int j = 0; j<4; j++){
				if(i&(1<<j))v+=s[j];
			}
			//if(f)break;
			if(isprime(stoll(v))){
				int x = stoll(v);
				ans = min(ans,x);
				//f = true;
			}
		}
		cout << to_string(ans).length() << "\n" << ans << "\n";
	}
	return 0;
}