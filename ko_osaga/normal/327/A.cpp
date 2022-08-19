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
const int mod = 1e9 + 7;

int n, a[105];
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			for(int k=i; k<=j; k++){
				a[k] ^= 1;
			}
			ret = max(ret, (int)count(a, a+n, 1));
			for(int k=i; k<=j; k++){
				a[k] ^= 1;
			}
		}
	}
	cout << ret;
}