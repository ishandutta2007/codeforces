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
//#define endl "\n"

vector<int> arr(10000, -1);
vector<bool> used(10001);
void ask(int i, int j) {
	int a, b;
	cout << "? " << i + 1 << " " << j + 1 << endl;
	cin >> a;
	cout << "? " << j + 1 << " " << i + 1 << endl;
	cin >> b;
	if (a > b) {
		arr[i] = a;
		used[a] = true;
	} else {
		arr[j] = b;
		used[b] = true;
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (true) {
    	int i1 = -1;
    	int j1 = -1;
    	for (int i = 0; i < n; i++) {
    		if (arr[i] == -1 && i1 == -1) {
    			i1 = i;
    			continue;
    		}
    		if (arr[i] == -1 && j1 == -1) {
    			j1 = i;
    			break;
    		}
    	}
    	if (j1 == -1) {
    		for (int i = 1; i <= n; i++) {
    			if (!used[i]) {
    				arr[i1] = i;
    				break;
    			}
    		}
    		break;
    	}
    	ask(i1, j1);
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}