#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7; int N , Q; string s0 , t; int cnt[100003][26] , iv[100003];

int main(){
	ios::sync_with_stdio(0); cin >> N >> Q >> s0 >> t; int tms = 1;
	for(int i = N - 1 ; ~i ; --i , tms = 2 * tms % P){memcpy(cnt[i] , cnt[i + 1] , sizeof(cnt[i])); cnt[i][t[i] - 'a'] = (cnt[i][t[i] - 'a'] + tms) % P;}
	iv[0] = 1; for(int i = 1 ; i <= 1e5 ; ++i) iv[i] = 1ll * iv[i - 1] * ((P + 1) / 2) % P;
	
	while(Q--){
		int ans = 0 , c; string s; cin >> c >> s;
		for(int i = 0 ; i <= s0.size() ; ++i){
			int plc = i; vector < int > matchpot; bool f = 1;
			for(int j = 0 ; f && j < s.size() ; ++j)
				if(plc == s0.size()){matchpot.push_back(s[j] - 'a'); plc = 0;} else f &= s[j] == s0[plc++];
			if(f){
				if(matchpot.empty()){ans = (ans + tms) % P; continue;}
				for(int j = 0 ; j < c ; ++j){
					if(matchpot.size() == 1){ans = (0ll + ans + cnt[j][matchpot[0]] - cnt[c][matchpot[0]] + P) % P; break;}
					bool f0 = 1 , f1 = 1; for(int k = 0 ; k < matchpot.size() ; ++k) (k & 1 ? f1 : f0) &= matchpot[k] == t[j] - 'a';
					if(f0 && f1){
						map < int , int > num; num[matchpot.size()] = 1; int vl = matchpot[0];
						while(j < c && num.size()){
							map < int , int > temp;
							for(auto t : num){
								if(t.first == 1){ans = (ans + 1ll * t.second * (cnt[j][vl] - cnt[c][vl] + P)) % P; continue;}
								temp[t.first / 2] = (temp[t.first / 2] + t.second) % P;
								temp[(t.first + 1) / 2] = (temp[(t.first + 1) / 2] + t.second) % P;
							}
							if(t[j] - 'a' != vl) break;
							++j; num = temp;
						}
						break;
					}else if(f0 || f1){
						vector < int > val; for(int k = 0 ; k < matchpot.size() ; ++k) if(f1 ^ (k & 1)) val.push_back(matchpot[k]);
						matchpot = val;
					}else break;
				}
			}
		}
		cout << 1ll * ans * iv[N - c] % P << endl;
	}
	return 0;
}