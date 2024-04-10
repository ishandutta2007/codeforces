#include <bits/stdc++.h>
using namespace std;
#define int long long
string solve(string a, string b, int n, char letter){
	int cur = 0;
	string ans;
	for(int i = 0; i<2*n; i++){
		if(cur<2*n&&a[cur]!=letter&&b[i]!=letter){
			ans+=a[cur];
			cur++;
			continue;
		}
		if(b[i]!=letter){
			ans+=b[i];
			continue;
		}
		while(cur<2*n&&a[cur]!=letter){
			ans+=a[cur];
			cur++;
		}
		if(cur<2*n&&a[cur]==letter&&b[i]==letter){
			ans+=a[cur];
			cur++;
			continue;
		}
		ans+=b[i];
	}
	while(cur<2*n){
		ans+=a[cur];
		cur++;
	}
	return ans;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a,b,c;
		cin >> a >> b >> c;
		int a1 = count(a.begin(),a.end(),'1');
		int a0 = count(a.begin(),a.end(),'0');
		int b1 = count(b.begin(),b.end(),'1');
		int b0 = count(b.begin(),b.end(),'0');
		int c1 = count(c.begin(),c.end(),'1');
		int c0 = count(c.begin(),c.end(),'0');
		if(a1>=n&&b1>=n){
			cout << solve(a,b,n,'1') << "\n";
		}
		else if(a0>=n&&b0>=n){
			cout << solve(a,b,n,'0') << "\n";
		}
		else if(a1>=n&&c1>=n){
			cout << solve(a,c,n,'1') << "\n";
		}
		else if(a0>=n&&c0>=n){
			cout << solve(a,c,n,'0') << "\n";
		}
		else if(b1>=n&&b1>=n){
			cout << solve(b,c,n,'1') << "\n";
		}
		else if(b0>=n&&b0>=n){
			cout << solve(b,c,n,'0') << "\n";
		}
		else{
			assert(false);
		}
	}
	return 0;
}