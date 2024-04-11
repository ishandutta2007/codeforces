#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

int g(int x, int y){
	return y ? g(y, x%y) : x;
}

int main(){
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	int l = x * y / g(x, y);
	cout << b / l - (a - 1) / l;
}