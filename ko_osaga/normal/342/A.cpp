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

int n, c[8];

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		
		int t;
		cin >> t;
		c[t]++;
	}
	if(c[5] || c[7]){
		cout << -1;
		return 0;
	}
	int t1 = c[4];
	int t3 = c[3];
	int t2 = n/3-t1-t3;
	if(t2 < 0){
		cout << -1;
		return 0;
	}
	if(t1 + t2 != c[2]){
		cout << -1;
		return 0;
	}
	if(t2 + t3 != c[6]){
		cout << -1;
		return 0;
	}
	for(int i=0; i<t1; i++) puts("1 2 4");
	for(int i=0; i<t2; i++) puts("1 2 6");
	for(int i=0; i<t3; i++) puts("1 3 6");
}