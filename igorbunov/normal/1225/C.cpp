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
    int n, p;
    cin >> n >> p;

    for (int i = 1; i <= 30; i++) {
    	int a = n - p * i;
    	int now = 0;
    	if (a < i) {
    		break;
    	}
    	for (int j = 0; j < 30; j++) {
    		if (((a) & (1 << j)) != 0) {
    			now++;
    		}
    	}

    	if (now <= i) {
    		cout << i;
    		return 0;
    	}
    }

    cout << -1;
}