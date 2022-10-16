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
    int n;
    cin >> n;
    vector<double> arr(n);
    vector<int> b(n);
    int can = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	b[i] = (int)arr[i];
    	if (arr[i] != b[i]) {
    		can++;
    		if (arr[i] < 0) {
    			b[i]--;
    		}
    	}
    	now += b[i];
    }
    for (int i = 0; i < n; i++) {
    	if (now == 0) {
    		break;
    	}
    	if (arr[i] != b[i]) {
    		now++;
    		b[i]++;
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << b[i] << endl;
    }
}