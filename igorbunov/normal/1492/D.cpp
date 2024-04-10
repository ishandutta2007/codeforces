#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

//#define endl "\n"
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    swap(a, b);

    if (k == 0) {
    	cout << "Yes\n";
    	for (int i = 0; i < a; i++) {
    		cout << 1;
    	}
    	for (int i = 0; i < b; i++) {
    		cout << 0;
    	}
    	cout << endl;
    	for (int i = 0; i < a; i++) {
    		cout << 1;
    	}
    	for (int i = 0; i < b; i++) {
    		cout << 0;
    	}
    	return 0;
    }
    if (a == 1 || b == 0) {
    	cout << "No\n";
    	return 0;
    }
    if (k >= a + b - 1) {
    	cout << "No\n";
    	return 0;
    }

    vector<int> ans1(a + b, -1);
    vector<int> ans2(a + b, -1);
    int osta = a - 1;
    int ostb = b;

    ans1[0] = 1;
    ans2[0] = 1;
    ans1[a + b - 1] = 0;
    ans2[a + b - 1] = 1;
    ans1[a + b - 1 - k] = 1;
    ans2[a + b - 1 - k] = 0;
    osta--;
    ostb--;
    for (int i = 1; i < a + b; i++) {
    	if (ans1[i] == -1) {
    		if (osta) {
    			ans1[i] = 1;
    			ans2[i] = 1;
    			osta--;
    		} else {
    			ans1[i] = 0;
    			ans2[i] = 0;
    			ostb--;
    		}
    	}
    }
    cout << "Yes\n";
    for (int i = 0; i < a + b; i++) {
    	cout << ans1[i];
    }
    cout << endl;
    for (int i = 0; i < a + b; i++) {
    	cout << ans2[i];
    }
     
}