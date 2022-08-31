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
vector<string> ops;
struct basis{
	vector<ll> V;
	int size;
	basis(){size = 0;}
	bool insert(ll x, bool add = true){
		if(x==0) return false;
		ll curr = add ? x : 0;
		vector<string> to_add;

		for(ll a : V) if(a & -a & x){
			x ^= a;
			if(curr != 0){
				to_add.push_back(to_string(curr) + " ^ " + to_string(a));
			}
			curr ^= a;
		}

		bool ret = x == 0;
		if(!add){
			if(ret){
				copy(all(to_add), back_inserter(ops));
			}
			return ret;
		}
		if(ret) return 0;
		copy(all(to_add), back_inserter(ops));
		for(ll & a : V){
			if(x & -x & a){
				ops.push_back(to_string(a) + " ^ " + to_string(x));
				a ^= x;
			}
		}
		V.push_back(x);
		size++;
		return 1;
	}
};
void go (ll x){
	basis B;
	int X = x;
	x *= 2;
	for(; x < 1e18; x *= 2){
		ops.push_back(to_string(x / 2) + " + " + to_string(x / 2));
		ops.push_back(to_string(x) + " + " + to_string(X));
		if(x != 2 * X){
			ops.push_back(to_string(x / 2) + " + " + to_string(x / 2 - X));
		}
		B.insert(x - X);
		B.insert(x + X);
		if(B.insert(1, false)){
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int x;
	cin >> x;
	go(x);
	cout << ops.size()<<"\n";
	for(auto it : ops) cout << it << "\n";
	cout << "\n";
}