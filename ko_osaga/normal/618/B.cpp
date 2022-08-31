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

int n, a[55][55];
lint mask[55];

lint ret[55];
int main(){
	cin >> n;
	fill(mask + 1, mask + n + 1, (2ll << n) - 2);
	set<int> s;
	for(int i=1; i<=n; i++){
		s.insert(i);
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
			if(a[i][j]){
				mask[a[i][j]] = mask[a[i][j]] & ((1ll<<i)|(1ll<<j));
			}
		}
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<=n; j++){
			if((mask[i] >> j) & 1){
				ret[j] = i;
				s.erase(j);
				break;
			}
		}
	}
	ret[*s.begin()] = n;
	for(int i=1; i<=n; i++) printf("%d ",ret[i]);
}