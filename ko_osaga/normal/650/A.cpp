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

int n;
pi a[200005];

lint bino(lint x){
	return x * (x-1) / 2;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i].first >> a[i].second;
	}
	// x coincide
	sort(a, a+n);
	lint ret = 0;
	for(int i=0; i<n; i++){
		int e = i;
		while(e < n && a[e].first == a[i].first) e++;
		ret += bino(e-i);
		i = e-1;
	}
	for(int i=0; i<n; i++){
		swap(a[i].first, a[i].second);
	}
	sort(a, a+n);
	for(int i=0; i<n; i++){
		int e = i;
		while(e < n && a[e].first == a[i].first) e++;
		ret += bino(e-i);
		i = e-1;
	}

	for(int i=0; i<n; i++){
		int e = i;
		while(e < n && a[e] == a[i]) e++;
		ret -= bino(e-i);
		i = e-1;
	}
	cout << ret;
	// y coincide
	// xy coincide
}