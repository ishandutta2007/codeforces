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

vector<int> v;
int n, m;

int main(){
	cin >> n >> m;
	while(n--){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	while(m--){
		int t;
		cin >> t;
		cout << upper_bound(v.begin(), v.end(), t) - v.begin() << " "; 
	}
}