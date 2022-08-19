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
typedef tuple<int, int, int> tp;

lint n;
vector<lint> v;
set<tp> ret;

void submit(int a, int b, int s){
	if(1ll * (a + b) * (b + s) * (a + s) == n){
		ret.insert(make_tuple(a, b, s));
		ret.insert(make_tuple(a, s, b));
		ret.insert(make_tuple(b, a, s));
		ret.insert(make_tuple(b, s, a));
		ret.insert(make_tuple(s, a, b));
		ret.insert(make_tuple(s, b, a));
	}
}

int intsqrt(lint x){
	if(x < 0) return -1;
	int b = sqrt(x);
	if(1ll * b * b == x) return b;
	return -1;
}

int main(){
	cin >> n;
	if(n%3 != 0){
		puts("0");
		return 0;
	}
	n /= 3;
	for(int i=2; i<=44444; i++){
		if(n%i == 0){
			v.push_back(i);
		}
	}
	for(int a=1; a<=22222; a++){
		for(auto &j : v){ // a + b
			int b = j - a;
			if(b >= a){
				if(j * (a + b) * (b + b) > n) break;
				lint t = n / j;
				lint det = j * j - 4ll * (1ll * a * b - t);
				int u = intsqrt(det);
				if(u < 0) continue;
				int geun1 = (u - j), geun2 = (-u - j);
				if(geun1 % 2 == 0 && geun1/2 >= b) submit(a, b, geun1/2);
				if(geun2 % 2 == 0 && geun2/2 >= b) submit(a, b, geun2/2);
			}
		}
	}
	cout << ret.size();
}