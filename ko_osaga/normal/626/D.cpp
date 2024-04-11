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
const int mod = 1e9 + 9;

int a[2005], n;
int cnt[5005];
lint scnt[5005];
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			cnt[a[i] - a[j]]++;
		}
	}
	for(int i=1; i<=5000; i++){
		scnt[i] = scnt[i-1] + cnt[i];
	}
	lint ret = 0;
	lint gs = n * (n-1) / 2;
	gs = gs * gs * gs;
	for(int i=3; i<=5000; i++){
		for(int j=1; j<i; j++){
			ret += scnt[j-1] * cnt[i] * cnt[i-j];
		}
	}
	printf("%.10f",1.0 * ret / gs);
}