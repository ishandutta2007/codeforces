#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<char>s2(n);
		bool f = true;
		for(int i = 0; i<k; i++){
			int one = 0;
			int zero = 0;
			for(int j = i; j<n; j+=k){
				if(s[j]=='1')one++;
				if(s[j]=='0')zero++;
			}
			if(one>0&&zero>0){
				f = false; break;
			}
			if(one){
				for(int j = i; j<n; j+=k){
					s2[j] = '1';
				}
			}
			else if(zero){
				for(int j = i; j<n; j+=k){
					s2[j] = '0';
				}
			}
			else{
				for(int j = i; j<n; j+=k){
					s2[j] = '?';
				}
			}
		}
		if(!f){
			cout << "NO\n";
			continue;
		}
		int curone = 0;
		int curzero = 0;
		int any = 0;
		for(int i = 0; i<k; i++){
			if(s2[i] =='1')curone++;
			else if(s2[i]=='0')curzero++;
			else any++;
		}
		if(abs(curone-curzero)>any)f = false;
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}