#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int ipow(int x, int p){
	lint ret = 1, piv = x;
	while(p){
		if(p&1) ret *= piv;
		piv *= piv;
		ret %= mod;
		piv %= mod;
		p >>= 1;
	}
	return ret;
}

int main(){
	int p, k;
	cin >> p >> k;
	if(k == 0) cout << ipow(p, p-1);
	else if(k == 1) cout << ipow(p, p);
	else{
		int ord = 1;
		lint tmp = k;
		while(tmp != 1){
			tmp *= k;
			tmp %= p;
			ord++;
		}
		cout << ipow(p, (p - 1) / ord);
	}
}