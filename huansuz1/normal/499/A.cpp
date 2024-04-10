#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, x, t, pos, ans;
pair <int, int> a[200];

int main () {
	cin >> n >> x;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}	
    sort(a + 1, a + 1 + n);	

    pos = 1;
    for (int i = 1; i <= n; i++) {
     	 ans += (a[i].first-pos)%x;
     	 ans += a[i].second - a[i].first+1;
     	 pos = a[i].second+1;
    }

    cout << ans;
	
    return 0;
}