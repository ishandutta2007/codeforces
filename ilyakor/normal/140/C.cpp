/*
 * Powered by C++Helper v0.001alpha
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int main() {
    int n;
    cin >> n;
    map<int, int> M;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++M[x];
    }
    
    priority_queue<ii> q;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        q.push(ii(it->second, it->first));        
    }
    vector<vi> v;
    
    while (sz(q) > 2) {
        ii p1 = q.top(); q.pop();
        ii p2 = q.top(); q.pop();
        ii p3 = q.top(); q.pop();

        vi w;
        w.pb(p1.second);
        w.pb(p2.second);
        w.pb(p3.second);
        sort(all(w));
        reverse(all(w));
        v.pb(w);

        p1.first--, p2.first--, p3.first--;
        if (p1.first) q.push(p1);
        if (p2.first) q.push(p2);
        if (p3.first) q.push(p3);
    }

    cout << sz(v) << "\n";
    for (int i = 0; i < sz(v); ++i)
        printf("%d %d %d\n", v[i][0], v[i][1], v[i][2]);
    return 0;
}