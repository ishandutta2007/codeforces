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
	int n; cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i]; c[i]--;
	}
	vector<vector<int>> ops;
	function<void(vector<int>)> go = [&](vector<int> D){
		ops.push_back(D);
		vector<int> C = c;
		int k = D.size();
		int r = n - 1;
		c.clear();
		for(int i = k - 1; i >= 0; i--){
			int l = r - D[i] + 1;
			copy(C.begin() + l, C.begin() + r + 1, back_inserter(c));
			r = l - 1;
		}
	};
	int done = 0;
	while(!is_sorted(all(c))){
		vector<int> where(n);
		for(int i = 0; i < n; i++) where[c[i]] = i;
		int i = 0;
		int old = -1;
		int old2 = -1;
		while(i < n){
			int j = where[i];
			int I = i, J = j;
			
			while(i + 1 < n && where[i + 1] == j + 1){
				i++;
				j++;
			}
			if(old > J){
				vector<int> D;
				if(J!=0) D.push_back(J);
				D.push_back(old - J);
				D.push_back(old2 - old + 1);
				if(old2!=n-1) D.push_back(n - 1 - old2);
				go(D);
				break;
			}
			old2 = j;
			old = J;
			i++;
		}
	}
	cout << ops.size() << "\n";
	for(auto D : ops){
		cout << D.size() << " ";
		for(auto it : D) cout << it << " ";
		cout << "\n";
	}
}