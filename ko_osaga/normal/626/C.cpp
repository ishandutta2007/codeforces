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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 9;

int n, m;

int main(){
	cin >> n >> m;
	for(int i=1; ; i++){
		int rem1 = i / 2 - i / 6; // n only
		int rem2 = i / 3 - i / 6; // m only
		int rem3 = i / 6; // both
		if(max(n - rem1, 0) + max(m - rem2, 0) <= rem3){
			printf("%d",i);
			return 0;
		}
	}
}