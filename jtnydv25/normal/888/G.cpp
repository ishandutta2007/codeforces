#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
const int K = 30;

inline int getLo(vi & v, int x){
	return upper_bound(v.begin(), v.end(), x) - v.begin();
}

inline int getRange(vi & v, int x, int y){
	return getLo(v, y) - getLo(v, x - 1);
}
int pw[30];
int get(vi & v, int x){
	if(v.empty()) return 0;
	int lo = 0, hi = (1 << K) - 1;
	int All = v.size(), ans = 0;
	int LO = 0, HI = v.size();
	int MID = getLo(v, (lo + hi) >> 1);
	for(int i = K - 1; i >= 0; i--){
		int mid = (lo + hi) >> 1;
		int lft = MID - LO;
		int rgt = All - lft;
		if(x & pw[i]){
			if(rgt){
				All = rgt;
				lo = mid + 1;
				LO = MID;
			}
			else{
				ans += pw[i];
				All = lft;
				hi = mid;
				HI = MID;
			}
		}
		else{
			if(lft){
				All = lft;
				hi = mid;
			}
			else{
				All = rgt;
				ans += pw[i];
				lo = mid + 1;
			}
		}
		MID = getLo(v, (lo + hi) >> 1);		
	}
	return ans;
}
const int N = (1 << 18) + 100;
vi vec;
#define ll long long
#define F first
#define S second
pair<vi, ll> go(int total, int s = 0, int e = (1 << K) - 1){
	if(total == 0) return {{}, 0LL};
	if(s == e){
		return {{s}, 0LL};
	}
	int mid = (s + e) >> 1;
	int LFT = getRange(vec, s, mid);
	pair<vi, ll> P = go(LFT, s, mid), Q = go(total - LFT, mid + 1, e);
	vi V1 = P.F, V2 = Q.F;
	ll ans = P.S + Q.S;
	vi ret = V1;
	int mn = 1e9;
	for(int x : V2){
		mn = min(mn, get(V1, x));
		ret.push_back(x);
	}
	if(V2.empty() || V1.empty()) mn = 0;
	return {ret, ans + mn};
}

int main(){
	for(int i = 0; i < K; i++) pw[i] = (1 << i);
	int n = 200000, x;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		// x = rand() % 1000000000;
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	cout << (go(vec.size()).second) << endl;
	// cerr << clock() / (double) CLOCKS_PER_SEC << endl;
}