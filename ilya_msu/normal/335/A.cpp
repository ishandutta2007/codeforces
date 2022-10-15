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
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;
const long double eps = 1e-10;
vector<pii> a;
int n;

bool f(int m) {
    int k = 0;
    for (int i = 0; i < a.size(); ++i) {
        k += (a[i].first + m - 1) / m;
    }
    return k <= n;
}


int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    string s;
    cin >> s >> n;
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); ++i)
        ++count[s[i] - 'a'];
    for (int i = 0; i < 26; ++i)
        if (count[i] != 0)
            a.push_back(pii(count[i], i));
    sort(a.begin(), a.end());
    if (a.size() > n) {
        cout << -1 << endl;
        return 0;
    }
    int down = 0, up = s.size();
    while(up - down > 1) {
        int m = (up + down) / 2;
        if (f(m))
            up = m;
        else
            down = m;
    }
    cout << up << endl;
    string res;
    for (int i = 0; i < a.size(); ++i) {
        for (int k = 0; k < (a[i].first + up - 1) / up; ++k)
            res += ('a' + a[i].second);        
    }
    while(res.size() < n)
        res += 'a';
    cout << res << endl;
       
    return 0;
}