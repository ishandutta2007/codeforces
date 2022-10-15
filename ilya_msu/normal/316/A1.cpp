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
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 100 * 1000 + 10;
//const ll mod = 3046201;


int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int q = 0;
    vector<int> a(10);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            ++q;
            continue;
        }
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
            ++a[s[i] - 'A'];
    }
    int k = 0;
    for (int i = 0; i < 10; ++i)
        if (a[i])
            ++k;
    ll res = 1;
    if ((s[0] >= 'A') && (s[0] <= 'Z')) {
        for (int i = 0; i < k; ++i)
            res *= (10 - i);
        res = res / 10 * 9;
    }
    else
        for (int i = 0; i < k; ++i)
            res *= (10 - i);
    if (s[0] == '?') {
        res *= 9;
        --q;
    }
    cout << res;
    string z = "";
    for (int i = 0; i < q; ++i)
        z += '0';
    cout << z << endl;
    return 0;
}