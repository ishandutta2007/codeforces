#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int h,m;
		cin >> h >> m;
		string s;
		cin >> s;
		map<char,int>hm; hm['0'] = 0; hm['1'] = 1; hm['2'] = 5; hm['5'] = 2; hm['8'] = 8;
		while(true){
			int c = 0; int d = 0;
			bool f = true;
			if(hm[s[4]]||s[4]=='0')c+=10*hm[s[4]];
			else f = false;
			if(hm[s[3]]||s[3]=='0')c+=hm[s[3]];
			else f = false;
			if(hm[s[1]]||s[1]=='0')d+=hm[s[1]]*10;
			else f = false;
			if(hm[s[0]]||s[0]=='0')d+=hm[s[0]];
			else f = false;
			if(c>=h)f = false;
			if(d>=m)f = false;
			if(f){
				cout << s << "\n";
				break;
			}
			int a = stoll(s.substr(0,2)); int b = stoll(s.substr(3,2));
			b++; 
			if(b==m){
				b = 0;
				a++;
				a%=h;
			}
			s = (to_string(a).length()==1?"0":"")+to_string(a)+":"+(to_string(b).length()==1?"0":"")+to_string(b);
		}
	}
	return 0;
}