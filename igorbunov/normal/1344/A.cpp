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

 
//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"

int INF = 1000000000LL;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);

	vector<int> cnt(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] += i;
		arr[i] += INF * n;
		arr[i] %= n;
		cnt[arr[i]]++;
		//cout << arr[i] << " ";
	}
	//cout << endl;

	for (int i = 0; i < n; i++) {
		//cout << cnt[i] << " ";
		if (cnt[i] != 1) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	solve();
    }
}