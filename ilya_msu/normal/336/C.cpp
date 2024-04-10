#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
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
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const int N = 1000 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;

int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int x = 1;
    vector<int> b;
    while(x <= 1000000000) {
        b.push_back(x);
        x *= 2;
    }
    int ans = -1;
    for (int i = 0; i < b.size(); ++i) {
        vector<int> c;
        for (int j = 0; j < a.size(); ++j)
            if (a[j] & b[i])
                c.push_back(a[j]);
        if (c.empty())
            continue;
        int res = c[0];
        for (int j = 1; j < c.size(); ++j)
            res = res & c[j];
        if (res % (1 << i) == 0)
            ans = i;
    }
    vector<int> c;
    for (int j = 0; j < a.size(); ++j)
        if (a[j] & b[ans])
            c.push_back(a[j]);
    cout << c.size() << endl;
    for (int i = 0; i < c.size(); ++i)
        cout << c[i] << " ";
    cout << "\n";


    return 0;
}