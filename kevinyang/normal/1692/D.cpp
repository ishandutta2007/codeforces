#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int a = stoll(s.substr(0,2));
		int b = stoll(s.substr(3));
		int x;
		cin >> x;
		set<int>st;
		for(int i = 0; i<24*60; i++){
			b+=x;
			int v = b/60;
			a+=v;
			a%=24;
			b%=60;
			int val = a*100+b;
			string str = to_string(val);
			while(str.size()<4){
				str = "0"+str;
			}
			string s2 = str;
			reverse(s2.begin(),s2.end());
			if(s2==str){
				st.insert(val);
			}
		}
		cout << st.size() << "\n";
	}
	return 0;
}