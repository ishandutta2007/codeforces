#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <locale>
using namespace std;
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define MS0(I) memset(I, 0, sizeof(I));
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define rep(i, n) for(int i = 0; i < n; i ++)
#define rep1(i, a, b) for(int i = a; i < b; i ++)
#define per1(i, a, b) for(int i = a; i >= b; i --)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long LL;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
//////////////////////
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)2e9;
const LL  INFF = (LL)2e18+7;
const int mod = 998244353;
const int MXN = (int)1e5 + 7;
map<LL, int>mp;
vector<LL>st;
LL ck(LL v, LL t){
	LL res = 1;
	rep1(i, 1, t+1){
		if((LDB)res*v > INFF) return INFF + 7;
		res *= v;
	}
	return res;
}
LL typ(LL v, int t){
	LL ll = 1, rr = INF;
	while(ll <= rr){
		LL mid = (ll + rr) >> 1;
		LL res = ck(mid, t);
		if(res > v) rr = mid - 1;
		else if(res == v) return mid;
		else ll = mid + 1;
	}
	return 0;
}
LL gcd(LL v1, LL v2){
	while(v1){
		LL tmp = v2 % v1;
		v2 = v1;
		v1 = tmp;
	}
	return v2;
}
LL mypow(LL v, LL t){
	LL res = 1;
	while(t){
		if(t & 1) res = res*v%mod;
		t >>= 1;
		v = v*v%mod;
	}
	return res;
}
queue<LL>Q;
void go(){
	while(!Q.empty()){
		LL v = Q.front(); Q.pop();
		rep(i, SZ(st)){
			if(st[i] % v == 0){
				if(!mp.count(st[i]/v)) Q.push(st[i] / v);
				mp[st[i]/v]++;
				mp[v]++;
				swap(st[i], st.back());
				st.pop_back();
				i--;
			}
		}
	}
	return ;
}
int main(void){
	int n; scanf("%d", &n);
	rep1(i, 1, n+1){
		LL v; scanf("%lld", &v);
		LL pr = 0;
		if( (pr = typ(v, 4)) ) mp[pr] += 4;
		else if( (pr = typ(v, 3)) ) mp[pr] += 3;
		else if( (pr = typ(v, 2)) ) mp[pr] += 2;
		else st.pb(v);
	}
	for(auto it = mp.begin(); it != mp.end(); it++)
		Q.push( it->F );
	go();
	LL ans = 1;
	while(!st.empty()){
		LL v = st.back(); st.pop_back();
		bool ok = 0;
		LL v1;
		rep(i, SZ(st)) if(st[i] != v){
			LL gd = gcd(v, st[i]);
			if(gd != 1){
				v1 = gd;
				ok = 1;
				break;
			}
		}
		if(ok){
			mp[v1]++;
			mp[v/v1]++;
			Q.push(v1);
			Q.push(v/v1);
			go();
		}
		else{
			LL cnt = 1;
			rep(i, SZ(st)){
				if(st[i] == v){
					cnt++;
					swap(st[i], st.back());
					st.pop_back();
					i--;
				}
			}
			ans = ans*(cnt+1)%mod*(cnt+1)%mod;
		}
	}
	for(auto it = mp.begin(); it != mp.end(); it++){
		ans = ans*(it->S + 1)%mod;
	}
	printf("%lld\n", ans);
	fflush(stdout);
	return 0;
}