#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	long long n, m;
	string S, T;
	cin >> n >> m >> S >> T;
	int g = gcd((int)S.size(), (int)T.size());
	const int mx = 26;
	long long res = 0;
	for(auto rg = 0; rg < g; ++ rg){
		string s, t;
		for(auto i = rg; i < (int)S.size(); i += g){
			s.push_back(S[i]);
		}
		for(auto i = rg; i < (int)T.size(); i += g){
			t.push_back(T[i]);
		}
		vector<int> order{0}, pos((int)t.size(), -1);
		pos[0] = 0;
		for(auto j = (int)s.size() % (int)t.size(); j; j = (j + (int)s.size()) % (int)t.size()){
			pos[j] = (int)order.size();
			order.push_back(j);
		}
		vector<array<long long, mx>> cnt((int)t.size() + 1);
		for(auto i = 0; i < (int)s.size(); ++ i){
			int c = s[i] - 'a';
			int k = pos[i % (int)t.size()];
			// [k, k + n)
			long long l = k, r = k + n;
			if(l % (int)t.size()){
				long long up = (l + (int)t.size() - 1) / (int)t.size() * (int)t.size();
				++ cnt[l % (int)t.size()][c];
				-- cnt[(int)t.size()][c];
				l = up;
			}
			if(r % (int)t.size()){
				long long down = r / (int)t.size() * (int)t.size();
				++ cnt[0][c];
				-- cnt[r % (int)t.size()][c];
				r = down;
			}
			cnt[0][c] += (r - l) / (int)t.size();
			cnt[(int)t.size()][c] -= (r - l) / (int)t.size();
		}
		for(auto j = 0; j < (int)t.size(); ++ j){
			int c = t[j] - 'a';
			for(auto d = 0; d < 26; ++ d){
				if(c != d){
					res += cnt[j][d];
				}
				cnt[j + 1][d] += cnt[j][d];
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////