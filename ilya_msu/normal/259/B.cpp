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
    vector<vector<int> > a(3, vector<int> (3));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    for (int x = 1; x <= 100000; ++x) {
        a[0][0] = x;
        int s = a[0][0] + a[0][1] + a[0][2];
        a[1][1] = s - a[1][0] - a[1][2];
        a[2][2] = s - a[2][0] - a[2][1];
        if (a[0][0] + a[1][0] + a[2][0] != s)
            continue;
        if (a[0][1] + a[1][1] + a[2][1] != s)
            continue;
        if (a[0][2] + a[1][2] + a[2][2] != s)
            continue;
        if (a[0][0] + a[1][1] + a[2][2] != s)
            continue;
        if (a[2][0] + a[1][1] + a[0][2] != s)
            continue;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
        return 0;
    }
    return 0;
}