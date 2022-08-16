#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		string s;
		int n, k;
		cin >> n >> k;
		cin >> s;
		vector<int> losing_streaks;
		int num_wins = 0, winning_streaks = 0;
		for(int i = 0; i < n;){
			int W = 0;
			while(i < n && s[i] == 'W'){
				num_wins++;
				i++;
				W++;
			}
			if(W) winning_streaks++;
			int L = 0;
			while(i < n && s[i] == 'L'){
				L++;
				i++;
			}
			if(winning_streaks && L > 0 && i != n) losing_streaks.push_back(L);
		}

		sort(all(losing_streaks));
		if(num_wins == 0){
			cout << max(0, 2 * k - 1) << "\n";
			continue;
		}
		if(num_wins + k >= n){
			cout << 2 * n - 1 << "\n";
			continue;
		}
		int ans = 2 * (num_wins + k);
		for(int L : losing_streaks){
			if(L <= k){
				winning_streaks--;
				k -= L;
			} else break;
		}
		cout << ans - winning_streaks << "\n";
	}
}