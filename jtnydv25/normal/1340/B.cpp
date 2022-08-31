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

vector<string> nums = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
const int N = 2005;
int dp[N][N];
int can[N][10];
int main(){
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<string> orig(n);
	vector<int> curr_cnts(n);
	vector<int> cnts;
	
	for(int i = 0; i < n; i++){
		cin >> orig[i];
		for(int j = 0; j < 10; j++){
			can[i][j] = -1;
			int t = 0, ok = 1;
			for(int l = 0; l < 7; l++){
				if(orig[i][l] == '1' && nums[j][l] == '0'){
					ok = 0; break;
				}
				t += (orig[i][l] == '0' && nums[j][l] == '1');
			}
			if(ok) can[i][j] = t;
			
		}
	}
	dp[n][0] = 1;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j <= k; j++){
			for(int v = 0; v < 10; v++) if(can[i][v] != -1 && can[i][v] <= j){
				dp[i][j] |= dp[i + 1][j - can[i][v]];
			}
		}
	}
	if(!dp[0][k]){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		int which = -1;
		for(int v = 0; v < 10; v++) if(can[i][v] != -1 && can[i][v] <= k && dp[i + 1][k - can[i][v]]) which = v;
		cout << which;
		k -= can[i][which];
	}
}