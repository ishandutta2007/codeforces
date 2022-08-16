#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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

struct sum2D{
	int n, m;
	vector<vector<int>> sm;
	sum2D(vector<vector<int>> & vec) : n(vec.size()), m(vec[0].size()){
		sm.assign(n, vector<int>(m, 0));
		vector<vector<int>> temp(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				temp[i][j] = vec[i][j] + (i == 0 ? 0 : temp[i - 1][j]);
				sm[i][j] = temp[i][j] + (j == 0 ? 0 : sm[i][j - 1]);
			}
		}
	}
	int getSum(int xl, int xr, int yl, int yr){
		assert(xl >= 0 && xl < n && yl >= 0 && yl < m);
		int ret = sm[xr][yr] + (xl > 0 && yl > 0 ? sm[xl - 1][yl - 1] : 0);
		if(xl > 0) ret -= sm[xl - 1][yr];
		if(yl > 0) ret -= sm[xr][yl - 1];
		return ret;	
	}
};

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<string> str(n);
	vector<vector<int>> V(n, vector<int>(m, 0));
	vector<vector<int>> mx(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++){
		cin >> str[i];
		// trace(str[i]);
		for(int j = 0; j < m; j++){
			V[i][j] = (str[i][j] == 'X');	
		}
	}
	sum2D X(V);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int lo = 0, hi = min(i, min(j, min(n - 1 - i, m - 1 - j)));
			while(lo < hi){
				int mid = (lo + hi + 1) / 2;
				int s = X.getSum(i - mid, i + mid, j - mid, j+ mid);
				if(s == (2 * mid + 1) * (2 * mid + 1)){
					lo = mid;
				} else hi = mid - 1;
			}
			mx[i][j] = lo;
			if(str[i][j] == '.') mx[i][j] = -1;
		}
	}
	int lo = 0, hi = min(n,m);
	while(lo < hi){
		int mid = (lo + hi + 1) / 2;
		vector<vector<int>> vec(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) vec[i][j] = mx[i][j] >= mid;

		sum2D Y(vec);
		bool ok = 1;		
		for(int i = 0; i < n && ok; i++)
			for(int j = 0; j < m; j++) if(str[i][j] == 'X'){
				int xl = max(0, i - mid);
				int xr = min(n -1, i + mid);
				int yl = max(0, j - mid);
				int yr = min(m - 1, j + mid);
				int num = Y.getSum(xl, xr, yl, yr);
				if(num == 0){
					ok = 0;
					break;
				}
			}
		if(ok) lo = mid;
		else hi = mid - 1;
	}
	// printf("%d\n", lo);
	cout << lo << "\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << ( (mx[i][j] >= lo ? "X" : "."));
		cout << "\n";
	}
}