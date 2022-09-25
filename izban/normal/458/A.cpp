#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const double q = (sqrt(5.0) + 1) / 2.0;

string a, b;

string slowsolve() {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = a.length();
    int m = b.length();
    n = max(2, max(n, m));
    while (a.length() < n) a += "0";
    while (b.length() < n) b += "0";
    
    vector<ll> aa(n), bb(n);
    for (int i = 0; i < n; i++) aa[i] += a[i] - '0';
    for (int i = 0; i < n; i++) bb[i] += b[i] - '0';
    for (int i = n - 1; i >= 0; i--) {
        aa[i] += a[i] - '0';
        bb[i] += b[i] - '0';
        if (i > 1) {
            if (aa[i] > bb[i] && aa[i - 1] >= bb[i - 1]) {
                reverse(a.begin(), a.end());
                reverse(b.begin(), b.end());              
                return ">";
            }
            if (aa[i] < bb[i] && aa[i - 1] <= bb[i - 1]) {
                reverse(a.begin(), a.end());
                reverse(b.begin(), b.end());              
                return "<";
            }
        }
        int k = min(aa[i], bb[i]);
        aa[i] -= k;
        bb[i] -= k;
        if (i > 1) {
            aa[i - 1] += aa[i];
            aa[i - 2] += aa[i];
            bb[i - 1] += bb[i];
            bb[i - 2] += bb[i];            
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());    
    double A = aa[0] + aa[1] * q, B = bb[0] + bb[1] * q;
    if (aa[0] == bb[0] && aa[1] == bb[1]) {
        return "=";
    }
    if (A < B) return "<";
    else return ">";
}

void fastsolve() {
    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> a >> b) {
        cout << slowsolve() << endl;
    }
    
    return 0;
}