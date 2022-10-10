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

template<typename Pred>
long long custom_binary_search(long long low, long long high, Pred p, bool is_left = true){
	assert(low < high);
	if(is_left){
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? low = mid : high = mid;
		}
		return low;
	}
	else{
		while(high - low > 1){
			long long mid = low + (high - low >> 1);
			p(mid) ? high = mid : low = mid;
		}
		return high;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> a(n);
	copy_n(istream_iterator<long long>(cin), n, a.begin());
	if(*max_element(a.begin(), a.end()) >= k){
		cout << 0;
		return 0;
	}
	int p = 0;
	while(!a[p]){
		++ p;
	}
	if(n - p >= 4){
		for(int x = 1; ; ++ x){
			for(int i = p + 1; i < n; ++ i){
				a[i] += a[i - 1];
				if(a[i] >= k){
					cout << x;
					return 0;
				}
			}
		}
	}
	else if(n - p == 3){
		cout << custom_binary_search(0, 9e18, [&](long long i){
			return __builtin_mul_overflow_p(a[p], i, 0LL) || __builtin_mul_overflow_p(a[p] * i, i + 1, 0LL) || k <= a[p + 2] + a[p + 1] * i + a[p] * i * (i + 1) / 2;
		}, false);
	}
	else{
		cout << (k - a[p + 1] + a[p] - 1) / a[p];
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////