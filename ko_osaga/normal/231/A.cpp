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

int ret = 0;
int main(){
	int n;
	cin >> n;
	while(n--){
		int a, b, c;
		cin >> a >> b >> c;
		if(a + b + c > 1) ret++;
	}
	cout << ret;
}