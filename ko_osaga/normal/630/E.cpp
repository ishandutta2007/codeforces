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
typedef pair<int,int> pi;

int main(){
	lint x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << ((y2 - y1) / 2 + 1) * (x2 - x1 + 1) - (x2 - x1) / 2;
}