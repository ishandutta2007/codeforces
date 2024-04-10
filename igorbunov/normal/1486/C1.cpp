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
    int n;
    cin >> n;
    cout << "? " << 1 << " " << n << endl;
    int ind;
    cin >> ind;
    if (ind == 1) {
    	int l = ind;
    	int r = n;
    	while (r - l > 1) {
    		int m = (l + r) / 2;
    		cout << "? " << ind << " " << m << endl;
    		int res;
    		cin >> res;
    		if (res == ind) {
    			r = m;
    		} else {
    			l = m;
    		}
    	}
    	cout << "! " << r << endl;
    	return 0;
    }
    if (ind == n) {
    	int l = 1;
    	int r = ind;
    	while (r - l > 1) {
    		int m = (l + r) / 2;
    		cout << "? " << m << " " << ind << endl;
    		int res;
    		cin >> res;
    		if (res == ind) {
    			l = m;
    		} else {
    			r = m;
    		}
    	}
    	cout << "! " << l << endl;
    	return 0;
    }

    cout << "? " << 1 << " " << ind << endl;
    int ind1;
    cin >> ind1;
    cout << "? " << ind << " " << n << endl;
    int ind2;
    cin >> ind2;

    if (ind1 == ind) {
    	int l = 1;
    	int r = ind;
    	while (r - l > 1) {
    		int m = (l + r) / 2;
    		cout << "? " << m << " " << ind << endl;
    		int res;
    		cin >> res;
    		if (res == ind) {
    			l = m;
    		} else {
    			r = m;
    		}
    	}
    	cout << "! " << l << endl;
    } else {
    	int l = ind;
    	int r = n;
    	while (r - l > 1) {
    		int m = (l + r) / 2;
    		cout << "? " << ind << " " << m << endl;
    		int res;
    		cin >> res;
    		if (res == ind) {
    			r = m;
    		} else {
    			l = m;
    		}
    	}
    	cout << "! " << r << endl;
    }
}