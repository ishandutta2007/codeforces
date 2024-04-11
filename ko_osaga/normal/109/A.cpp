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

int n;

int main(){
	cin >> n;
	int reta = -1, retb = -1, crit = 1e9;
	for(int i=0; i<=n; i+=4){
		if((n - i) % 7 == 0){
			int u = i/4 + (n-i)/7;
			if(u < crit){
				crit = u;
				reta = i/4, retb = (n-i)/7;
			}
		}
	}
	if(crit > 1e8) puts("-1");
	else{
		for(int i=0; i<reta; i++) putchar('4');
		for(int i=0; i<retb; i++) putchar('7');
	}
}