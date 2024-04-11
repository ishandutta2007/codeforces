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


int main(){
	int tc;
	cin >> tc;
	while(tc--){
	int n;
	cin >> n;
	lint t = 1ll * n * (n+1) / 2;
	for(int i=1; i<=n; i<<=1){
		t -= 2 * i;
	}
	cout << t << endl;

	}
}