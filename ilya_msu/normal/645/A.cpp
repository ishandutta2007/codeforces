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
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;


void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    s1 += s2[1];
    s1 += s2[0];
    while (s1[0] != 'A') {
        s2 = s1[1];
        s2 += s1[2];
        s2 += s1[3];
        s2 += s1[0];
        s1 = s2;
    }
    string s3, s4;
    cin >> s3 >> s4;
    s3 += s4[1];
    s3 += s4[0];
    while (s3[0] != 'A') {
        s4 = s3[1];
        s4 += s3[2];
        s4 += s3[3];
        s4 += s3[0];
        s3 = s4;
    }
    int a1 = 0;
    int a3 = 0;
    for (int i = 1; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if ((s1[i] == 'B') && (s1[j] == 'C'))
                a1 = 1;
            if ((s3[i] == 'B') && (s3[j] == 'C'))
                a3 = 1;
        }
    }
    if (a1 == a3)
        cout << "YES\n";
    else
        cout << "NO\n";

         

    
}



//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}