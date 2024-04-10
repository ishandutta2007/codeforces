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
    vector<pii> a(8);
    for (int i = 0; i < 8; ++i)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    if (((a[0].first == a[1].first) && (a[2].first == a[1].first) && 
        (a[2].first < a[3].first) && (a[3].first == a[4].first) && 
        (a[4].first < a[5].first) && (a[5].first == a[6].first) && (a[6].first == a[7].first)) && 
        ((a[0].second == a[3].second) && (a[3].second == a[5].second) && 
        (a[0].second < a[1].second) && (a[1].second == a[6].second) && 
        (a[1].second < a[2].second) && (a[2].second == a[4].second) && (a[2].second == a[7].second)))
        cout << "respectable" << endl;
    else
        cout << "ugly" << endl;
    return 0;
}