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
typedef pair<int, int> pi;

int greatest(int x){
	if(x == 0) return 0;
	return max(x%10, greatest(x/10));
}
int n;
int main(){
	cin >> n;
	int cnt = 0;
	while(n){
		n -= greatest(n);
		cnt++;
	}
	cout << cnt;
}