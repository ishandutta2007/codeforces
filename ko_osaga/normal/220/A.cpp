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

int a[100005], b[100005], n;
vector<int> v;
map<int, int> mp;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1, b+n+1);
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(a[i] != b[i]){
			cnt++;
		}
	}
	puts(cnt <= 2 ? "YES" : "NO");
}