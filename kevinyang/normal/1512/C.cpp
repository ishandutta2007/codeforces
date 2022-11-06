#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int n = a+b;
		string s;
		cin >> s;
		bool f = true;
		int extra = 0;
		for(int i = 0; i<(n+1)/2; i++){
			if(s[i]=='?'&&s[n-i-1]=='?')extra+=2;
			else if(s[i]=='?'){
				if(s[n-i-1]=='0')a-=2;
				else if(s[n-i-1]=='1')b-=2;
				s[i] = s[n-i-1];
			}
			else if(s[n-i-1]=='?'){
				if(s[i]=='0')a-=2;
				else if(s[i]=='1')b-=2;
				s[n-i-1] = s[i];
			}
			else{
				if(s[i]==s[n-i-1]){
					if(s[i]=='0')a-=2;
					else b-=2;
					continue;
				}
				else f = false;
				if(s[i]=='0')a--;
				else b--;
				if(s[n-i-1]=='0')a--;
				else b--;
			}
		}
		if(n%2==1&&s[n/2]=='?')extra--;
		if(n%2==1&&s[n/2]=='0')a++;
		if(n%2==1&&s[n/2]=='1')b++;
		if(a<0||b<0)f = false;
		if(!f)cout << "-1\n";
		else{
			for(int i = 0; i<(n+1)/2; i++){
				if(s[i]!='?')continue;
				if(i!=n-i-1){
					if(a>=2){
						s[i] = '0'; s[n-i-1] = '0'; a-=2;
					}
					else if(b>=2){
						s[i] = '1'; s[n-i-1] = '1'; b-=2;
					}
				}
				else{
					if(a>=1){
						a--; s[i] = '0';
					}
					else if(b>=1){
						s[i] = '1'; b--;
					}
				}
			}
			if(a>0||b>0)cout << "-1\n";
			else cout << s << "\n";
		}
	}
	return 0;
}