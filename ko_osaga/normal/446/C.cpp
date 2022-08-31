#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<double, int> pi;
const int mod = 1e9 + 9;

int n, a[300005];

struct mat{
	int a[2][2];
	mat operator*(const mat &a)const{
		mat c;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				c.a[i][j] = 0;
				for(int k=0; k<2; k++){
					c.a[i][j] += 1ll * this->a[i][k] * a.a[k][j] % mod;
					c.a[i][j] %= mod;
				}
			}
		}
		return c;
	}
	mat operator+(const mat &a)const{
		mat c;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				c.a[i][j] = this->a[i][j] + a.a[i][j];
				c.a[i][j] %= mod;
			}
		}
		return c;
	}
	mat negate(){
		mat c;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++){
				c.a[i][j] = (mod - a[i][j]) % mod;
			}
		}
		return c;
	}
}fib, base, inv, zero;

struct bit{
	int tree[300005];
	void add(int x, int v){
		while(x <= n){
			tree[x] += v;
			tree[x] %= mod;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
			ret %= mod;
		}
		return ret;
	}
}bit;

struct bit2{
	mat tree[300005];
	void add(int x, mat v){
		while(x <= n){
			tree[x] = tree[x] + v;
			x += x & -x;
		}
	}
	mat query(int x){
		mat ret = zero;
		while(x){
			ret = ret + tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit2;

mat getmat(int x){
	mat ret = base, piv;
	if(x < 0) x = -x, piv = inv;
	else piv = fib;
	while(x){
		if(x&1) ret = ret * piv;
		piv = piv * piv;
		x >>= 1;
	}
	return ret;
}

int f(int x){
	return getmat(x).a[1][0];
}

int get(int x){
	return (bit.query(x) + (getmat(x+3) * bit2.query(x)).a[1][0]) % mod;
}

int main(){
	base.a[0][0] = base.a[1][1] = 1;
	fib.a[0][0] = fib.a[0][1] = fib.a[1][0] = 1;
	inv.a[0][1] = inv.a[1][0] = 1;
	inv.a[1][1] = mod-1;
	int q;
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		int t;
		scanf("%d",&t);
		bit.add(i, t);
	}
	while(q--){
		int t, s, e;
		scanf("%d %d %d",&t,&s,&e);
		if(t == 1){
			mat t = getmat(-s);
			int u = f(e-s+3);
			bit2.add(s, t);
			bit2.add(e+1, t.negate());
			bit.add(s, mod - 1);
			bit.add(e+1, u);
		}
		else{
			printf("%d\n",(get(e) - get(s-1) + mod) % mod);
		}
	}
}