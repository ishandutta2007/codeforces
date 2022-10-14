#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

const ll NN = 1000010, M = 1000000007;
char s[NN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T;
	cin >> T;
	while(T--) {
		ll x;
		cin >> x;
		string str;
		cin >> str;
		ll last = str.size(), ind = last;
		bool f = false;
		for(ll i = 0; i < last; i++) s[i] = str[i];
		for(ll l = 0; l < x; l++) {
		//	for(ll i = 0; i < last; i++) cout << s[i]; cout << endl;
		//	cout << last << " " << len <<  " " << ind <<  " "<< l << endl;
			if(ind <= x + 5 && !f)
				for(ll k = 0; k < s[l] - '1'; k++) {
					for(ll i = l + 1; i < min(x + 5, last); i++) 
						if(ind <= x + 5) s[ind++] = s[i];
						else ind++;
					if(last >= x + 5) ind += last - x - 5;
				}
			else {
				ind = (ind + (s[l] - '1') * (last - l - 1 + M) % M) % M;
				f = true;
			}
			last = ind;
		}
		cout << (ind + M) % M << endl;
	}
	return 0;
}