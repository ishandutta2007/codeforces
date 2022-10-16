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

//2 4 8 16 32 64
void solve() {
	int n;
	cin >> n;
	int a = (1 << n);
	for (int i = 1; i <= (n / 2) - 1; i++) {
		a += (1 << i);
	}
	int b = 0;
	for (int i = (n / 2); i < n; i++) {
		b += (1 << i);
	}
	cout << abs(a - b) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }

}