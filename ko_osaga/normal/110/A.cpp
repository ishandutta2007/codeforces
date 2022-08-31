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

string s;

int main(){
	cin >> s;
	int u = count(s.begin(), s.end(), '4') + count(s.begin(), s.end(), '7');
	cout << (u == 4 || u == 7 ? "YES" : "NO");
}