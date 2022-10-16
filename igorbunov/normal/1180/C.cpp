#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;
  
#define int long long
#define endl '\n'

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, q;
    cin >> n >> q;
    deque<long long> arr;
    long long max1 = -1;
    for (long long i = 0; i < n; i++) {
    	long long a;
    	cin >> a;
    	arr.push_back(a);
    	max1 = max(a, max1);
    }
    vector<pair<long long, long long>> ans;
    while (arr.front() != max1) {
    	long long a = arr.front();
    	arr.pop_front();
    	int b = arr.front();
    	//cout << a << " " << b << endl;
    	arr.pop_front();
    	ans.push_back(make_pair(a, b));
    	if (a > b) {
    		arr.push_front(a);
    		arr.push_back(b);
    	} else {
    		arr.push_front(b);
    		arr.push_back(a);
    	}
    }
    vector<long long> now;
    for (long long i = 1; i < n; i++) {
    	now.push_back(arr[i]);
    }
    for (int i = 0; i < q; i++) {
    	long long m;
    	cin >> m;
    	if (m <= (long long)ans.size()) {
    		m--;
    		cout << ans[m].first << " " << ans[m].second << endl;
    	} else {
    		m -= (long long)ans.size();
    		m--;
    		cout << max1 << " " << now[m % (long long)now.size()] << endl;
    	}
    }
}