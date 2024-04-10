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
    vector<vector<int> > a(2, vector<int> (2, 0));
    int t, x, y;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t >> x >> y;
        a[t - 1][0] += x;
        a[t - 1][1] += y;
    }
    for (int i = 0; i < 2; ++i)
        if (a[i][0] >= a[i][1])
            cout << "LIVE" << endl;
        else
            cout << "DEAD" << endl;
    return 0;
}