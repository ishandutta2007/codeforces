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

#pragma GCC_OPTIMAZE("ofast")

using namespace std;


#define int long long
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    if (a == b) {
    	cout << a << 1 << " ";
    	cout << b << 2;
    	return 0;
    }

    if (b == a + 1) {
    	cout << a << "9" << " ";
    	cout << b << "0";
    	return 0;
    }

    if (a == 9 && b == 1) {
    	cout << 9 << " " << 10;
    	return 0;
    }

    cout << -1;
    return 0;
}