#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef unsigned uint;
typedef unsigned char uint8;

const ull M = 10000000000000061LL;
const ll B = 541;
const ull mod = M;
ld invMOD = 1. / mod;

inline ll mul(ull a, ull b) {
	ull y = ull(ld(a) * ld(b) * invMOD + ld(1) / 2);
	ull r = a * b - y * mod;
	if(ll(r) < 0)
		r += mod;
	return r;
}
inline ull add(ull x, ull y){ x += y; if(x >= mod) x -= mod; return x;}
inline ull sub(ull x, ull y){ x -= y; if(ll(x) < 0) x += mod; return x;}

ull powers[200];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	powers[0] = 1;
	for(int i = 1; i < 200; i++) powers[i] = (powers[i - 1] * B) % M;
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<ull, int> dp;
		vector<string> S(n);
		vector<vector<vector<int>>> fst(n);
		for(int i = 0; i < n; i++){
			cin >> S[i];
			int m = S[i].length();
			vector<vector<int>> vec(m + 1, vector<int>(256));
			for(int j = 0; j < 256; j++) vec[m][j] = m;
			for(int j = m - 1; j >= 0; j--){
				vec[j] = vec[j + 1];
				vec[j][S[i][j]] = j;
			}
			fst[i] = vec;
		}
		function<int(vector<int>&, ull)> get = [&](vector<int>& pos, ull H){
			auto it = dp.find(H);
			if(it != dp.end()) return it->second;
			int ans = 1;
			for(int c = 'a'; c <= 'z'; c++){
				ull H2 = H;
				vector<int> pos2(n);
				bool bad = false;
				for(int r = 0; r < n; r++){
					int u = fst[r][pos[r] + 1][c];
					if(u == sz(S[r])){
						bad = true;
						break;
					} else{
						pos2[r] = u;
						H2 = add(H2, mul(sub(u, pos[r]), powers[r]));
					}
				}
				if(!bad){
					ans = max(ans, get(pos2, H2) + 1);
				}
			}

			for(int c = 'A'; c <= 'Z'; c++){
				ull H2 = H;
				vector<int> pos2(n);
				bool bad = false;
				for(int r = 0; r < n; r++){
					int u = fst[r][pos[r] + 1][c];
					if(u == sz(S[r])){
						bad = true;
						break;
					} else{
						pos2[r] = u;
						H2 = add(H2, mul(sub(u, pos[r]), powers[r]));
					}
				}
				if(!bad){
					ans = max(ans, get(pos2, H2) + 1);
				}
			}
			return dp[H] = ans;
		};

		function<void(vector<int>&, ull)> recurse = [&](vector<int>& pos, ull H){
			char go = -1;
			int mx = -1;
			for(int c = 'a'; c <= 'z'; c++){
				ull H2 = H;
				vector<int> pos2(n);
				bool bad = false;
				for(int r = 0; r < n; r++){
					int u = fst[r][pos[r] + 1][c];
					if(u == sz(S[r])){
						bad = true;
						break;
					} else{
						pos2[r] = u;
						H2 = add(H2, mul(sub(u, pos[r]), powers[r]));
					}
				}
				if(!bad && dp[H2] > mx){
					go = c;
					mx = dp[H2];
				}
			}

			for(int c = 'A'; c <= 'Z'; c++){
				ull H2 = H;
				vector<int> pos2(n);
				bool bad = false;
				for(int r = 0; r < n; r++){
					int u = fst[r][pos[r] + 1][c];
					if(u == sz(S[r])){
						bad = true;
						break;
					} else{
						pos2[r] = u;
						H2 = add(H2, mul(sub(u, pos[r]), powers[r]));
					}
				}
				if(!bad && dp[H2] > mx){
					go = c;
					mx = dp[H2];
				}
			}
			if(go==-1) return;
			char c = go;
			cout << c;
			ull H2 = H;
			vector<int> pos2(n);
			bool bad = false;
			for(int r = 0; r < n; r++){
				int u = fst[r][pos[r] + 1][c];
				if(u == sz(S[r])){
					bad = true;
					break;
				} else{
					pos2[r] = u;
					H2 = add(H2, mul(sub(u, pos[r]), powers[r]));
				}
			}
			recurse(pos2, H2);
		};
		vector<int> pos(n, -1);
		cout << get(pos, 0) - 1 << endl;
		recurse(pos, 0);
		cout << endl;
	}
}