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

int n, a[100005];

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	for(int i=1; i<n; i++){
		if(a[i] % a[0]){
			puts("-1");
			return 0;
		}
	}
	cout << a[0];
}