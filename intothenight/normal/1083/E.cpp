#include <bits/stdc++.h>
using namespace std;

// array<T, 3> represents a line. (constant term, slope, auxiliary variable)
template<class T, bool GET_MAX = false>
struct sorted_line_container: deque<array<T, 3>>{
#define USE(x) using deque<array<T, 3>>::x;
	USE(size) USE(empty) USE(front) USE(back) USE(begin) USE(end) USE(rbegin) USE(rend) USE(pop_front) USE(pop_back) USE(erase) USE(push_back) USE(push_front)
#undef USE
	static constexpr T inf = numeric_limits<T>::max();
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	T div(T a, T b){ return a / b - ((a ^ b) < 0 && a % b); }
	bool isect_front(class deque<array<T, 3>>::iterator x, class deque<array<T, 3>>::iterator y){
		if(y == end()){ (*x)[2] = inf; return false; }
		else{ (*x)[2] = div((*y)[0] - (*x)[0], (*x)[1] - (*y)[1]); return (*x)[2] >= (*y)[2]; }
	}
	bool isect_back(class deque<array<T, 3>>::reverse_iterator x, class deque<array<T, 3>>::reverse_iterator y){
		if(x == rend()) return false;
		else{ (*x)[2] = div((*y)[0] - (*x)[0], (*x)[1] - (*y)[1]); return (*x)[2] >= (*y)[2]; }
	}
	T eval(array<T, 3> &line, T x){
		return line[0] + line[1] * x;
	}
	// Slopes must increase monotonously
	template<bool FIRST_CALL = true>
	void inc_push(array<T, 3> L){
		if(FIRST_CALL && !GET_MAX){
			dec_push<false>({-L[0], -L[1]});
			return;
		}
		assert(empty() || back()[1] <= L[1]);
		if(empty() || back()[1] < L[1] || back()[0] < L[0]){
			if(!empty() && L[1] == back()[1]) erase(-- end());
			L[2] = inf, push_back(L); isect_back(++ rbegin(), rbegin());
			while((int)size() >= 2 && isect_back(++ ++ rbegin(), ++ rbegin())) erase(-- -- end()), isect_back(++ rbegin(), rbegin());
		}
	}
	// Slopes must decrease monotonously
	template<bool FIRST_CALL = true>
	void dec_push(array<T, 3> L){
		if(FIRST_CALL && !GET_MAX){
			inc_push<false>({-L[0], -L[1]});
			return;
		}
		assert(empty() || L[1] <= front()[1]);
		if(empty() || L[1] < front()[1] || front()[0] < L[0]){
			if(!empty() && L[1] == front()[1]) erase(begin());
			L[2] = 0, push_front(L), isect_front(begin(), ++ begin());
			while((int)size() >= 2 && isect_front(begin(), ++ begin())) erase(++ begin());
		}
	}
	// Other queries must not be called and x must be decreasing
	// O(1)
	T dec_query(T x){
		assert(!empty());
		while((int)size() >= 2 && eval(*rbegin(), x) <= eval(*++ rbegin(), x)) pop_back(); back()[2] = inf;
		return eval(*rbegin(), x) * (GET_MAX ? 1 : -1);
	}
	// Other queries must not be called and x must be increasing
	// O(1)
	T inc_query(T x){
		assert(!empty());
		while((int)size() >= 2 && eval(*begin(), x) <= eval(*++ begin(), x)) pop_front();
		return eval(*begin(), x) * (GET_MAX ? 1 : -1);
	}
	// Other queries must not be called
	// O(log n)
	T query(T x){
		assert(!empty());
		if((int)size() == 1) return eval(*begin(), x) * (GET_MAX ? 1 : -1);
		if(eval(*begin(), x) >= eval(*++ begin(), x)) return eval(*begin(), x) * (GET_MAX ? 1 : -1);
		int low = 0, high = (int)size() - 1;
		while(high - low >= 2){
			int mid = low + (high - low >> 1);
			(eval(*(begin() + mid), x) < eval(*(begin() + mid + 1), x) ? low : high) = mid;
		}
		return eval(*(begin() + low + 1), x) * (GET_MAX ? 1 : -1);
	}
};

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<tuple<int, int, long long>> r(n);
	for(auto &[x, y, a]: r){
		cin >> x >> y >> a;
	}
	sort(r.begin(), r.end());
	vector<long long> dp(n);
	sorted_line_container<long long, true> lc;
	for(auto i = 0; i < n; ++ i){
		auto [x, y, a] = r[i];
		if(!lc.empty()){
			ctmax(dp[i], lc.dec_query(y));
		}
		dp[i] += 1LL * x * y - a;
		lc.dec_push({dp[i], -x});
	}
	cout << *max_element(dp.begin(), dp.end()) << "\n";
	return 0;
}

/*
dp[i]: max value looking upto i, i-th must be picked
dp[i] = max(0, max{0 <= j < i}( dp[j] - y_i * x_j) )) + x_i * y_i - a_i
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////