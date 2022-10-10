#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string temp;
	cin >> temp;
	int n = int(temp.size());
	vector<int> s(temp.begin(), temp.end());
	for(auto &x: s){
		x -= '0';
	}
	vector<int> t = s;
	string res(n, '0');
	bool ok = true;
	while(1){
		static int i = 0, j = n - 1;
		if(j - i <= 1){
			if(i == j){
				if(s[i] & 1){
					ok = false;
				}
				else{
					res[i] = s[i] / 2 + '0';
				}
			}
			else{
				if(s[i] == s[j]){
					res[i] = s[i] + '0';
				}
				else if(s[i] - 1 == s[j] + 10){
					if(s[j] == 9){
						ok = false;
						break;
					}
					res[i] = s[j] + 10 - (s[j] + 10) / 2 + '0', res[j] = (s[j] + 10) / 2 + '0';
				}
				else{
					ok = false;
				}
			}
			break;
		}
		else{
			if(s[j] < 0){
				-- s[j - 1], s[j] += 10;
			}
			if(s[i] % 10 == s[j] % 10){
				if(s[i] >= 10){
					if(s[i] == 19){
						ok = false;
						break;
					}
					res[i] = s[i] - s[i] / 2 + '0', res[j] = s[i] / 2 + '0';
					-- s[j - 1];
				}
				else{
					res[i] = s[i] + '0';
				}
			}
			else if(s[i] % 10 == (s[j] + 1) % 10){
				-- s[i];
				if(s[i] < 0){
					ok = false;
					break;
				}
				s[i + 1] += 10;
				if(s[i] >= 10){
					if(s[i] == 19){
						ok = false;
						break;
					}
					res[i] = s[i] - s[i] / 2 + '0', res[j] = s[i] / 2 + '0';
					-- s[j - 1];
				}
				else{
					res[i] = s[i] + '0';
				}
			}
			else{
				ok = false;
				break;
			}
		}
		++ i, -- j;
	}
	if(ok && res[0] != '0'){
		cout << res;
	}
	else if(n == 1 || t[0] != 1){
		cout << 0;
	}
	else{
		ok = true;
		-- n;
		s = {1 + t.begin(), t.end()};
		s[0] += 10;
		res = string(n, '0');
		while(1){
			static int i = 0, j = n - 1;
			if(j - i <= 1){
				if(i == j){
					if(s[i] & 1){
						ok = false;
					}
					else{
						res[i] = s[i] / 2 + '0';
					}
				}
				else{
					if(s[j] < 0){
						-- s[i], s[j] += 10;
					}
					if(s[i] == s[j]){
						res[i] = s[i] + '0';
					}
					else if(s[i] - 1 == s[j] + 10){
						if(s[j] == 9){
							ok = false;
							break;
						}
						res[i] = s[j] + 10 - (s[j] + 10) / 2 + '0', res[j] = (s[j] + 10) / 2 + '0';
					}
					else{
						ok = false;
					}
				}
				break;
			}
			else{
				if(s[j] < 0){
					-- s[j - 1], s[j] += 10;
				}
				if(s[i] % 10 == s[j] % 10){
					if(s[i] >= 10){
						if(s[i] == 19){
							ok = false;
							break;
						}
						res[i] = s[i] - s[i] / 2 + '0', res[j] = s[i] / 2 + '0';
						-- s[j - 1];
					}
					else{
						res[i] = s[i] + '0';
					}
				}
				else if(s[i] % 10 == (s[j] + 1) % 10){
					-- s[i];
					if(s[i] < 0){
						ok = false;
						break;
					}
					s[i + 1] += 10;
					if(s[i] >= 10){
						if(s[i] == 19){
							ok = false;
							break;
						}
						res[i] = s[i] - s[i] / 2 + '0', res[j] = s[i] / 2 + '0';
						-- s[j - 1];
					}
					else{
						res[i] = s[i] + '0';
					}
				}
				else{
					ok = false;
					break;
				}
			}
			++ i, -- j;
		}
		ok && res[0] != '0' ? cout << res : cout << 0;
	}
	return 0;
}

/*
 5905
 5095
10100

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////