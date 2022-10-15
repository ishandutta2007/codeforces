#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 1000 * 1000 * 1000 + 10;



int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n; 
    vector<int> a(n);
    vector<int> a1, a2, a3;
    vector<int> r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((a[i] < 0) && (a1.empty())) {
            a1.push_back(a[i]);
            continue;
        }
        if (a[i] == 0) {
            a3.push_back(0);
            continue;
        }
        if (a[i] < 0)
            r.push_back(a[i]);
        else
            a2.push_back(a[i]);
    }
    if (a2.empty()) {
        a2.push_back(r[0]);
        a2.push_back(r[1]);
        for (int i = 2; i < r.size(); ++i)
            a3.push_back(r[i]);
    }
    else {
        for (int i = 0; i < r.size(); ++i)
            a3.push_back(r[i]);
    }
    cout << a1.size();
    for (int i = 0; i < a1.size(); ++i)
        cout << " " << a1[i];
    cout << endl;
    cout << a2.size();
    for (int i = 0; i < a2.size(); ++i)
        cout << " " << a2[i];
    cout << endl;
    cout << a3.size();
    for (int i = 0; i < a3.size(); ++i)
        cout << " " << a3[i];
    cout << endl;
    return 0;
}