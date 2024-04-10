#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 200200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

double sqr(double x) {
    return x * x;
}

double dist(pair<int, int> a, pair<int, int> b) {
    return sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}

double slowsolve(int n, int m) {
    vector<pair<int, int> > v;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) v.push_back(make_pair(i, j));
    double ans = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v.size(); j++) if (i != j) {
            for (int k = 0; k < (int)v.size(); k++) if (i != k && j != k) {
                for (int l = 0; l < (int)v.size(); l++) if (i != l && j != l && k != l) {
                    double res = dist(v[i], v[j]) + dist(v[j], v[k]) + dist(v[k], v[l]);
                    if (res > ans - 1e-9) {
                        /*cout << res << endl;
                        cout << v[i].first << " " << v[i].second << endl;
                        cout << v[j].first << " " << v[j].second << endl;
                        cout << v[k].first << " " << v[k].second << endl;
                        cout << v[l].first << " " << v[l].second << endl; 
                        */ans = res;                       
                    }
                }
            }
        }
    }
    return ans;
}

void push(int n, int m, vector<pair<int, int> > &v, pair<int, int> o) {
    if (o.first >= 0 && o.first <= n && o.second >= 0 && o.second <= m) v.push_back(o);
}

double fastsolve(int n, int m) {
        /*if (n == 0) {
            cout << "0 1" << endl << "0 " << m << endl << "0 0" << endl << "0 " << m - 1 << endl;
            return 3 * m - 2;
        } else if (m == 0) {
            cout << "1 0" << endl << m << " 0" << endl << "0 0" << endl << m - 1 << " 0" << endl;
            return 3 * n - 2;
        } else {
            //if (n <= 2 || m <= 2) return slowsolve(n, m);
            cout << n - (n < m) << " " << m - (n >= m) << endl;
            cout << 0 << " " << 0 << endl;
            cout << n << " " << m << endl;
            cout << (n < m) << " " << (n >= m) << endl;
            return dist(make_pair(n - (n < m), m - (n >= m)), make_pair(0, 0)) +
                + dist(make_pair(0, 0), make_pair(n, m))
                + dist(make_pair(n, m), make_pair((n < m), (n >= m)));
        } */
    vector<pair<int, int> > v;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            push(n, m, v, make_pair(i, j));
            push(n, m, v, make_pair(n - i, j));
            push(n, m, v, make_pair(i, m - j));
            push(n, m, v, make_pair(n - i, m - j));
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    double ans = -1;
    pair<int, int> pans1, pans2, pans3, pans4;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v.size(); j++) if (i != j) {
            for (int k = 0; k < (int)v.size(); k++) if (i != k && j != k) {
                for (int l = 0; l < (int)v.size(); l++) if (i != l && j != l && k != l) {
                    double res = dist(v[i], v[j]) + dist(v[j], v[k]) + dist(v[k], v[l]);
                    if (res > ans - 1e-9) {
                        ans = res;         
                        pans1 = v[i];
                        pans2 = v[j];
                        pans3 = v[k];
                        pans4 = v[l];              
                    }
                }
            }
        }
    }    
    cout << pans1.first << " " << pans1.second << endl;
    cout << pans2.first << " " << pans2.second << endl;
    cout << pans3.first << " " << pans3.second << endl;
    cout << pans4.first << " " << pans4.second << endl;
    return ans;    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    //slowsolve(5, 7);
    //return 0;
    
    /*for (int i = 0; i <= 10; i++) for (int j = 0; j <= 10; j++) if ((i + 1) * (j + 1) >= 4) {
        cerr << i << " "<< j << endl;
        if (fabs(fastsolve(i, j) - slowsolve(i, j)) > 1e-9) {
            cout << fastsolve(i, j) << " " << slowsolve(i, j) << endl;
            cout << i << " " << j << endl;
            return 0;
        }
    }*/
        
    int n, m;
    while (cin >> n >> m) {
        fastsolve(n, m);
    }
    
    return 0;
}