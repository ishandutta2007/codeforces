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



int SOLVE(){
	/*vector<int> res(1000, 1000000000);
	res.back() = 1;
	//shuffle(res.begin(), res.end(), rng);
	int ANSWER = 999;
	while(res[ANSWER] == 1000000000){
		++ ANSWER;
	}
	int qcnt = 0;
	auto query = [&](const vector<int> &a, const vector<int> &b){
		++ qcnt;
		if(qcnt > 50){
			cout << "TOO MANY QUERIES " << endl;
			exit(0);
		}
		cout << "Query #" << qcnt << endl;
		cout << "? " << int(a.size()) << " " << int(b.size()) << "\n";
		for(auto x: a) cout << x + 1 << " ";
		cout << "\n";
		for(auto x: b) cout << x + 1 << " ";
		cout << endl;
		long long left = 0, right = 0;
		for(auto x: a){
			left += res[x];
		}
		for(auto x: b){
			right += res[x];
		}
		vector<int> c(a);
		c.insert(c.end(), b.begin(), b.end());
		sort(c.begin(), c.end()), sort(c.begin(), c.end()), c.erase(unique(c.begin(), c.end()), c.end());
		if(int(c.size()) != int(a.size()) + int(b.size())){
			cout << "UNIQUENESS FAILED!" << endl;
			exit(0);
		}
		if(left > right) return -1;
		else if(left == right) return 0;
		else return 1;
	};
	auto answer = [&](int i){
		cout << "! " << i + 1 << endl;
		cout << "ANSWER = " << ANSWER + 1 << endl;
		if(ANSWER != i) exit(0);
	};*/

	auto query = [&](const vector<int> &a, const vector<int> &b){
		cout << "? " << int(a.size()) << " " << int(b.size()) << "\n";
		for(auto x: a) cout << x + 1 << " ";
		cout << "\n";
		for(auto x: b) cout << x + 1 << " ";
		cout << endl;
		string resp;
		cin >> resp;
		if(resp[0] == 'W') exit(0);
		else if(resp[0] == 'F') return -1;
		else if(resp[0] == 'E') return 0;
		else return 1;
	};
	auto answer = [&](int i){
		cout << "! " << i + 1 << endl;
	};
	int n = 1000, k = 1;
	cin >> n >> k;
	int p = 0;
	const int repeat = 15;
	for(auto REP = 0; REP < repeat; ++ REP){
		int q;
		do{
			q = rng() % n;
		}while(p == q);
		if(query({p}, {q}) == 1){
			p = q;
		}
	}
	if(p && query({p}, {0}) != 1){
		answer(0);
		return 0;
	}
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	int i = 0, p2 = 1;
	while(1){
		int len = min(p2, n - i - 1);
		if(query(vector<int>(a.begin(), a.begin() + len), vector<int>(a.begin() + i + 1, a.begin() + i + 1 + len)) == 0){
			i += p2;
			p2 <<= 1;
		}
		else if(p2 > 1){
			p2 >>= 1;
		}
		else{
			break;
		}
	}
	answer(i + 1);
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
	}
	return 0;
}

/*
1
5 2
5 5 5 1 2
mine: 2
ans: 4
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////