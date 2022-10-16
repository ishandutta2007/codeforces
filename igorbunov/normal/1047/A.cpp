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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n % 3 == 0) {
    	cout << 1 << " " << 1 << " " << n - 2;
    }
    if (n % 3 == 1) {
    	cout << 1 << " " << 2 << " " << n - 3;
    }
    if (n % 3 == 2) {
    	cout << 1 << " " << 2 << " " << n - 3;
    }
}