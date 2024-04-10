#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int k, x, n, m;
	cin >> k >> x >> n >> m;
	for(auto startC0 = 0; startC0 <= 1; ++ startC0){
		for(auto endA0 = 0; endA0 <= 1; ++ endA0){
			for(auto inner0 = 0; inner0 * 2 <= n - startC0 - endA0; ++ inner0){
				for(auto startC1 = 0; startC1 <= 1; ++ startC1){
					for(auto endA1 = 0; endA1 <= 1; ++ endA1){
						for(auto inner1 = 0; inner1 * 2 <= m - startC1 - endA1; ++ inner1){
							vector<long long> s(k), e(k), cnt(k);
							s[0] = startC0, s[1] = startC1;
							e[0] = endA0, e[1] = endA1;
							cnt[0] = inner0, cnt[1] = inner1;
							for(auto i = 2; i < k; ++ i){
								s[i] = s[i - 2], e[i] = e[i - 1];
								cnt[i] = cnt[i - 2] + cnt[i - 1] + (e[i - 2] && s[i - 1]);
							}
							if(cnt[k - 1] == x){
								string s(n, 'X'), t(m, 'X');
								if(startC0){
									s[0] = 'C';
								}
								if(endA0){
									s[n - 1] = 'A';
								}
								if(startC1){
									t[0] = 'C';
								}
								if(endA1){
									t[m - 1] = 'A';
								}
								for(auto rep = 0, i = startC0; rep < inner0; ++ rep, i += 2){
									s[i] = 'A', s[i + 1] = 'C';
								}
								for(auto rep = 0, i = startC1; rep < inner1; ++ rep, i += 2){
									t[i] = 'A', t[i + 1] = 'C';
								}
								cout << s << "\n" << t << "\n";
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << "Happy new year!\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////