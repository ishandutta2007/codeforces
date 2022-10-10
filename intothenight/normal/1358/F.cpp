#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DEBUG BEGIN
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &p){
	return in >> p.first >> p.second;
}
template<class Tuple, size_t ...Is>
void read_tuple(istream &in, Tuple &t, index_sequence<Is...>){
	((in >> get<Is>(t)), ...);
}
template<class ...Args>
istream &operator>>(istream &in, tuple<Args...> &t){
	read_tuple(in, t, index_sequence_for<Args...>{});
	return in;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "P(" << p.first << " " << p.second << ")";
}
template<class Tuple, size_t ...Is>
void print_tuple(ostream &out, const Tuple &t, index_sequence<Is...>){
	((out << (Is ? " " : "") << get<Is>(t)), ...);
}
template<class ...Args>
ostream &operator<<(ostream &out, const tuple<Args...> &t){
	out << "T<";
	print_tuple(out, t, index_sequence_for<Args...>{});
	return out << ">\n";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	out << "V[";
	for(auto &x: arr) out << x << " ";
	return out << "]\n";
}
// DEBUG END

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	long long sa = 0, sb = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		sa += a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
		sb += b[i];
	}
	auto kill = [](){
		cout << "IMPOSSIBLE\n";
		exit(0);
	};
	if(sb < sa){
		kill();
	}
	string res;
	long long cnt = 0;
	bool is_big = false;
	const int lim = 2e5;
	if(n == 1){
		if(a != b){
			kill();
		}
	}
	else if(n == 2){
		while(a != b){
			if(b[0] == b[1]){
				kill();
			}
			if(b[0] > b[1]){
				swap(b[0], b[1]);
				res.push_back('R');
			}
			if(a == b){
				break;
			}
			if(a[0] == b[0]){
				if((b[1] - a[1]) % b[0]){
					kill();
				}
				if(!is_big){
					if(int(res.size()) + (b[1] - a[1]) / b[0] > lim){
						is_big = true;
					}
					else{
						res.append((b[1] - a[1]) / b[0], 'P');
					}
				}
				cnt += (b[1] - a[1]) / b[0];
				b[1] = a[1];
			}
			else if(a[1] == b[0]){
				if((b[1] - a[0]) % b[0]){
					kill();
				}
				if(!is_big){
					if(int(res.size()) + (b[1] - a[0]) / b[0] > lim){
						is_big = true;
					}
					else{
						res.append((b[1] - a[0]) / b[0], 'P');
					}
				}
				cnt += (b[1] - a[0]) / b[0];
				b[1] = a[0];
				swap(b[0], b[1]);
				res.push_back('R');
			}
			else{
				if(b[1] % b[0] == 0){
					kill();
				}
				if(!is_big){
					if(int(res.size()) + b[1] / b[0] > lim){
						is_big = true;
					}
					else{
						res.append(b[1] / b[0], 'P');
					}
				}
				cnt += b[1] / b[0];
				b[1] %= b[0];
				sb = b[0] + b[1];
				if(sb < sa){
					kill();
				}
			}
		}
	}
	else{
		while(a != b){
			reverse(b.begin(), b.end());
			res.push_back('R');
			if(a == b){
				break;
			}
			reverse(b.begin(), b.end());
			res.pop_back();
			if(!is_sorted(b.begin(), b.end())){
				reverse(b.begin(), b.end());
				res.push_back('R');
			}
			if(a == b){
				break;
			}
			if(!is_sorted(b.begin(), b.end()) || unique(b.begin(), b.end()) != b.end()){
				kill();
			}
			sb = b[0];
			for(auto i = n - 1; i > 0; -- i){
				b[i] -= b[i - 1];
				sb += b[i];
			}
			if(!is_big){
				res.push_back('P');
				if(int(res.size()) > lim){
					is_big = true;
				}
			}
			++ cnt;
			if(sb < sa){
				kill();
			}
		}
	}
	reverse(res.begin(), res.end());
	if(!is_big && int(res.size()) <= lim){
		cout << "SMALL\n" << int(res.size()) << "\n" << res << "\n";
	}
	else{
		cout << "BIG\n" << cnt << "\n";
	}
	return 0;
}

/*
PRPR
6 6 5 1 5
P
6 12 17 18 23
R
23 18 17 12 6
P
23 41 58 70 76
R
79 70 58 41 23
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////