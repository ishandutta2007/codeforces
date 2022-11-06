#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a,b,c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		vector<char>ans(n);
		int total = 0;
		for(int i = 0; i<n; i++){
			ans[i] = ' ';
			if(s[i]=='S'&&a>0){
				a--;
				ans[i] = 'R';
				total++;
			}
			else if(s[i]=='R'&&b>0){
				b--;
				ans[i] = 'P';
				total++;
			}
			else if(s[i]=='P'&&c>0){
				c--;
				ans[i] = 'S';
				total++;
			}
		}
		if(total>=(n+1)/2){
			cout << "YES\n";
			for(int i = 0; i<n; i++){
				if(ans[i]==' '){
					if(a>0){
						a--;
						ans[i] = 'R';
					}
					else if(b>0){
						b--;
						ans[i] = 'P';
					}
					else{
						c--;
						ans[i] = 'S';
					}
				}
				cout << ans[i];
			}
			cout << "\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}