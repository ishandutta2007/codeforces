#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
using lint = long long;
const int MAXN = 200005;
const int mod = 1e9 + 7;

lint fact[MAXN], invf[MAXN];

lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

lint bino(int x, int y){
	return fact[x] * (invf[y] * invf[x-y] % mod) % mod;
}

lint start_from_zero(vector<int> a, int l){
	if(*min_element(a.begin(), a.end()) < 0) return 0;
	assert(accumulate(a.begin(), a.end(), 0) == l);
	if(a[1] == a[2]){
		if(a[1] == 0){
			if(a[3]) return 0;
			return 1;
		}
		int S = a[0], X = a[1], T = a[3];
		return bino(X - 1 + T, X - 1) * bino(X + S, X) % mod;
	}
	if(a[1] - 1 != a[2]) return 0;
	int X = a[2];
	int S = a[0], T = a[3];
	return bino(X + T, X) * bino(X + S, X) % mod;
}

lint solve(string s, vector<int> a){
	int len = accumulate(a.begin(), a.end(), 1);
	if(len > s.size()) return 0;
	if(len == s.size()){
		vector<int> na(4);
		for(int i=1; i<s.size(); i++){
			int prv = (s[i-1] - '0') * 2 + (s[i] - '0');
			na[prv]++;
		}
		lint ans = 0;
		if(na == a) ans = 1;
		for(int i=1; i<s.size(); i++){	
			int prv = (s[i-1] - '0') * 2 + (s[i] - '0');
			if(s[i] == '1'){
				a[prv ^ 1]--;
				ans += start_from_zero(a, s.size() - 1 - i);
				a[prv ^ 1]++;
			}
			a[prv]--;
		}
		return ans % mod;
	}
	if(len < s.size()){
		swap(a[0], a[3]);
		swap(a[1], a[2]);
		lint ans = start_from_zero(a, len - 1);
		return ans % mod;
	}
}

int main(){
	fact[0] = invf[0] = 1;
	for(int i=1; i<200005; i++){
		fact[i] = fact[i-1] * i % mod;
		invf[i] = ipow(fact[i], mod - 2);
	}
	string L, R;
	cin >> L >> R;
	for(int i=L.size()-1; i>=0; i--){
		if(L[i] == '1'){
			L[i] = '0';
			for(int j=i+1; j<L.size(); j++) L[j] = '1';
			break;
		}
	}
	if(L[0] == '0') L.erase(L.begin());
	vector<int> a(4);
	for(int i=0; i<4; i++) cin >> a[i];
	cout << (solve(R, a) - solve(L, a) + mod) % mod;
}