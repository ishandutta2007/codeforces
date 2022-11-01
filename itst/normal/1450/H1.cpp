#include<bits/stdc++.h>
using namespace std;

const int _ = 1 << 18 , P = 998244353 , G = 3; int upd(int x){return x + (x >> 31 & P);}
int add(int x , int y){return upd(x + y - P);} int sub(int x , int y){return upd(x - y);}
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}

int dir[_] , need , invnd , w[_];
void init(int len){
	static int L = 1; need = 1; while(need < len) need <<= 1;
	invnd = poww(need , P - 2); for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	for(int &i = L ; i < need ; i <<= 1){w[i] = 1; int wn = poww(G , P / i / 2); for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % P;}
}

void dft(vector < int > &arr , int tp){
	arr.resize(need); for(int i = 1 ; i < need ; ++i) if(i < dir[i]) swap(arr[i] , arr[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				int x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % P;
				arr[j + k] = add(x , y); arr[i + j + k] = sub(x , y);
			}
	if(tp == -1){reverse(arr.begin() + 1 , arr.end()); for(auto &t : arr) t = 1ll * t * invnd % P;}
}


vector < int > solve(vector < vector < int > > &pot , int l , int r){
	if(l == r) return pot[l];
	int mid = (l + r) >> 1; vector < int > pl = solve(pot , l , mid) , pr = solve(pot , mid + 1 , r); int sz = pl.size() + pr.size() - 1;
	init(sz); dft(pl , 1); dft(pr , 1); for(int i = 0 ; i < need ; ++i) pl[i] = 1ll * pl[i] * pr[i] % P;
	dft(pl , -1); pl.resize(sz); return pl;
}

int main(){
	int N , M; cin >> N >> M; string s; cin >> s; vector < vector < int > > pot;
	int cnt = 0; for(auto t : s) cnt += t == '?';
	for(int i = 0 ; i < N ; i += 2)
		if(s[i] == 'b')
			if(s[i + 1] == 'b') pot.push_back({0 , 1});
			else if(s[i + 1] == 'w') pot.push_back({1});
			else pot.push_back({1 , 1});
		else if(s[i] == 'w')
			if(s[i + 1] == 'b') pot.push_back({0 , 0 , 1});
			else if(s[i + 1] == 'w') pot.push_back({0 , 1});
			else pot.push_back({0 , 1 , 1});
		else
			if(s[i + 1] == 'b') pot.push_back({0 , 1 , 1});
			else if(s[i + 1] == 'w') pot.push_back({1 , 1 , 0});
			else pot.push_back({1 , 2 , 1});
	vector < int > ans = solve(pot , 0 , pot.size() - 1); int pos = pot.size()  , sum = 0;
	for(int i = pos + 2 ; i < ans.size() ; i += 2) sum = (sum + 1ll * (i - pos) / 2 * ans[i]) % P;
	for(int i = pos - 2 ; i >= 0 ; i -= 2) if(i < ans.size()) sum = (sum + 1ll * (pos - i) / 2 * ans[i]) % P;
	cout << 1ll * sum * poww(poww(2 , cnt - 1) , P - 2) % P;
	return 0;
}