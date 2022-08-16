#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x));
map<int,int> cntx, cnty;
map<pair<int, int>, int > cntb;
ll C2(int x){ return (x * 1ll *(x - 1)) >> 1;}
int main(){
	int n, x, y;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(x); sd(y);
		cntx[x] ++; cnty[y] ++;
		cntb[{x, y}] ++;
	}
	ll ans = 0;
	for(auto it : cntx) ans += C2(it.second);
	for(auto it : cnty) ans += C2(it.second);
	for(auto it : cntb) ans -= C2(it.second);
	cout << ans;
}