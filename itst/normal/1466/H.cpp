#include<bits/stdc++.h>
using namespace std;

#define pii pair < int , int >
const int P = 1e9 + 7; int N , val[41][41] , fac[41] , ifac[41] , nxt[41];
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}
int binom(int a , int b){return 1ll * fac[a] * ifac[b] % P * ifac[a - b] % P;}

#define ull unsigned long long
map < ull , int > ans;
ull qhash(vector < pii > &cnt){ull sum = 0; for(auto t : cnt){sum = (sum * 41 + t.first) * 41 + t.second;} return sum;}

int solve(vector < pii >);
int dfs(vector < pii > &cnt , int pos , vector < pii > &pot , int all , int in , int tms , int num){
	if(pos == cnt.size()) return num ? (num & 1 ? 1ll : P - 1ll) * tms % P * val[all - in][in] % P * solve(pot) % P : 0;
	int t = cnt[pos].first , c = cnt[pos].second , sum = dfs(cnt , pos + 1 , pot , all , in + t * c , tms , num + c);
	for(int i = 1 ; i <= c ; ++i){
		pot.push_back(pii(t , i)); sum = (sum + dfs(cnt , pos + 1 , pot , all , in + t * (c - i) , 1ll * tms * binom(c , i) % P , num + c - i)) % P;
		pot.pop_back();
	}
	return sum;
}
int solve(vector < pii > cnt){
	if(cnt.empty()) return 1;
	ull val = qhash(cnt); if(ans.find(val) != ans.end()) return ans[val];
	int sz = 0; for(auto t : cnt) sz += t.first * t.second;
	vector < pii > tmp; return ans[val] = dfs(cnt , 0 , tmp , sz , 0 , 1 , 0);
}

int main(){
	vector < int > pot; cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> nxt[i];
	for(int i = 1 ; i <= N ; ++i) if(nxt[i]){int p = i , cnt = 0; do{++cnt; int r = nxt[p]; nxt[p] = 0; p = r;}while(p != i); pot.push_back(cnt);}
	sort(pot.begin() , pot.end()); vector < pii > cnt;
	for(auto t : pot) if(cnt.empty() || cnt.back().first != t) cnt.push_back(make_pair(t , 1)); else ++cnt.back().second;

	fac[0] = 1; for(int i = 1 ; i <= N ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[N] = poww(fac[N] , P - 2); for(int i = N - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	for(int j = 0 ; j < N ; ++j){
		for(int k = 0 ; k <= j ; ++k)
			val[j][1] = (val[j][1] + 1ll * binom(j , k) * fac[k] % P * fac[N - k - 1]) % P;
		for(int k = 2 ; k + j <= N ; ++k) val[j][k] = 1ll * val[j][1] * val[j][k - 1] % P;
	}
	cout << solve(cnt); return 0;
}