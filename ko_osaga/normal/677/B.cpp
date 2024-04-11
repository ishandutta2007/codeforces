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

int n, h, k, a[100005];
int main(){
	cin >> n>> h >> k;
	for(int i=0; i<n; i++) cin>> a[i];
	lint ret = 0;
	lint sum = 0;
	for(int i=0; i<n; i++){
		int e = i;
		if(sum + a[i] > h){
			sum = 0;
			ret++;
		}
		while(e < n && sum + a[e] <= h){
			sum += a[e];
			e++;
		}
		i = e-1;
		ret += sum / k;
		sum %= k;
	}
	if(sum) ret++;
	cout << ret;
}