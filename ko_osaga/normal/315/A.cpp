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

int n, a[105], b[105], ret;

int main(){
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i] >> b[i];
	for(int i=0; i<n; i++){
		bool ok = 0;
		for(int j=0; j<n; j++){
			if(i != j && a[i] == b[j]) ok = 1;
		}
		if(!ok) ret++;
	}
	cout << ret;
}