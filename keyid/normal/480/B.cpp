/*************************************************************************
    > File Name: B.cpp
    > Author: wmg_1001
    > Mail: wmg_1007@163.com 
    > Created Time: 20141019  173244
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

map <int, int> M;

int A[100005];

int main() {
    int n, x, y, l;
    cin >> n >> l >> x >> y;
    bool can_x = false, can_y = false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        M[A[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        if (A[i] < x) continue;
        if (M[A[i] - x] > 0) {
            can_x = true;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] < y) continue;
        if (M[A[i] - y] > 0) {
            can_y = true;
            break;
        }
    }
    if (can_x && can_y) {
        cout << 0 << endl;
        return 0;
    }
    if (can_x == true && can_y == false) {
        cout << 1 << endl;
        cout << y << endl;
        return 0;
    }
    if (can_x == false && can_y == true) {
        cout << 1 << endl;
        cout << x << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (A[i] + x <= l) {
            if (A[i] + x - y >= 0 && M[A[i] + x - y] > 0) {
                cout << 1 << endl;
                cout << A[i] + x << endl;
                return 0;
            }
            if (A[i] + x + y <= l && M[A[i] + x + y] > 0) {
                cout << 1 << endl;
                cout << A[i] + x << endl;
                return 0;
            }
        }
        if (A[i] - x >= 0) {
            if (A[i] - x - y >= 0 && M[A[i] - x - y] > 0) {
                cout << 1 << endl;
                cout << A[i] - x << endl;
                return 0;
            }
            if (A[i] - x + y <= l && M[A[i] - x + y] > 0) {
                cout << 1 << endl;
                cout << A[i] - x << endl;
                return 0;
            }
        }
    }
    cout << 2 << endl;
    cout << x << ' ' << y << endl;
    return 0;
}