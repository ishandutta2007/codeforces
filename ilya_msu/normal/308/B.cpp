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

ll up(ll a, ll b) {
    ll q = a / b;
    if (a % b != 0)
        ++q;
    return q;
}

vector<int> c(30, 0);
void add(ll a) {
    int ind = 0;
    while(a) {
        if (a & 1)
            ++c[ind];
        ++ind;
        a /= 2;
    }
}

vector<int> mult(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i];
        if (c[i] == -1)
            continue;
        if (c[i] == n - 1)
            continue;
        c[i] = max(c[i], b[c[i] + 1]);
    }
    return c;
}

vector<int> power(vector<int> d, int k) {
    int n = d.size();
    vector<int> res(n, -1);
    while(k) {
        if (k & 1) {
            res = mult(d, res);
        }
        k /= 2;
        d = mult(d, d);
    }
    return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n, r, c;
    cin >> n >> r >> c;
    vector<string> words(n);
    vector<int> sum(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        sum[i] = words[i].size();
        if (i)
            sum[i] += sum[i - 1];
    }
    vector<int> d(n, -1);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (words[i].size() > c)
            continue;
        int j = i;
        if (i)
            j = max(j, d[i - 1]);
        cur = sum[j];
        if (i)
            cur -= sum[i - 1];
        cur += j - i;
        while(j + 1 < n) {
            if (cur + words[j + 1].size() + 1 <= c) {
                cur = cur + words[j + 1].size() + 1;
                ++j;
            }
            else
                break;            
        }
        d[i] = j;
    }
    vector<int> a = power(d, r);
    int ind = 0;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] + 1 - i > m) {
            ind = i;
            m = a[i] + 1 - i;
        }
    }
    for (int i = 0; i < r; ++i) {
        if ((ind >= n) || (d[ind] == -1))
            return 0;
        for (int j = ind; j < d[ind]; ++j)
            cout << words[j] << " ";
        cout << words[d[ind]] << "\n";
        ind = d[ind] + 1;
    }
    return 0;
}