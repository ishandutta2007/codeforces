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

void gen(const vector<vector<int> >& a, vector<vector<int> >& b, int mid) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            b[i][j] = (a[i][j] >= mid);
}

bool f(vector<vector<int> >& b) {
    int n = b.size(), m = b[0].size();
    vector<vector<int> > used(m, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        vector<int> p;
        for (int j = 0; j < m; ++j)
            if (b[i][j])
                p.push_back(j);
        for (int j = 0; j < p.size(); ++j)
            for (int k = 0; k < j; ++k) {
                if (used[p[j]][p[k]])
                    return true;
                used[p[j]][p[k]] = true;
            }
    }
    return false;
}


int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    int down = 0, up = INF;
    vector<vector<int> > b(n, vector<int>(m));
    while(up - down > 1) {
        int mid = (up + down) / 2;
        gen(a, b, mid);
        if (f(b))
            down = mid;
        else
            up = mid;
    }
    cout << down << endl;
    return 0;
}