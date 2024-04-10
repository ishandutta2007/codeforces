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
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
//const int N = 100 * 1000 + 10;
//const ll mod = 1000 * 1000 * 1000 + 7;;


int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            cout << k * n + ((i + k + 1) % n + 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}