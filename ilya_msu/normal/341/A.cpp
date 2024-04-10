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
const int mod = 1000 * 1000 * 1000 + 9;
const long double eps = 1e-10;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    ll res = 0;
    ll sum = 0;
    ll ab = 0;
    for (int i = 0; i < n; ++i) {
        res += a[i] * i;
        res -= sum;
        sum += a[i];
        ab += abs(a[i]);
    }
    ll b = res * 2 + ab;
    ll c = n;
    ll d = gcd(b, c);
    cout << b / d << " " << c / d << endl;
    return 0;
}