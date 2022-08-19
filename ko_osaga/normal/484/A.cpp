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

int main(){
	int n;
	cin >> n;
	while(n--){
		lint l, r;
		cin >> l >> r;
		while(1){
			lint lsb = (~l) & -(~l);
			if(l + lsb <= r) l += lsb;
			else break;
		}
		cout << l << endl;
	}
}