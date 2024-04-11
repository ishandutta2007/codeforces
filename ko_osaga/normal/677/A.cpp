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

int n, h;

int main(){
	cin >> n >> h;
	int ret= 0;
	while(n--){
		int t;
		cin >> t;
		ret++;
		if(t > h) ret++;
	}
	cout << ret;
}