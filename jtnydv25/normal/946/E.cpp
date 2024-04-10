#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
const int N = 200005;
string s;
int mask[N];
int main(){
	int t;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> s;
		int n = s.length();
		s = "0" + s;
		for(int i = 1; i <= n; i++){
			mask[i] = mask[i - 1] ^ (1 << (s[i] - '0'));
		}
		bool done = 0;
		for(int j = n; j >= 1; j--){
			int d = s[j] - '0';
			if(done) break;
			for(int dig = d - 1; dig >= ((j == 1) ? 1: 0); dig--){
				if(done) break;
				int mask2 = mask[j - 1] ^ (1 << dig);
				vector<int> vec;
				int rem = n - j;
				for(int k = 0; k < 10; k++) if(mask2 >> k & 1) vec.push_back(k);
				if((int)vec.size() <= rem){
					for(int i = 1; i < j; i++) cout << s[i]; cout << dig;
					for(int i = 0; i < rem - ((int) vec.size()); i++) cout << 9;
					for(int i = ((int)vec.size()) - 1; i >= 0; i--) cout << vec[i];
					cout << endl;
					done = 1;
				}
			}
		}
		if(done) continue;
		// reduce length by 2 and print all 9
		for(int i = 0; i < n - 2; i++) cout << 9;
		cout << "\n";
	}
}