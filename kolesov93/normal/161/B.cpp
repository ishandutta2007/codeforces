#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long ll;

#define N 1111
pair<long long, int> a[N], b[N];
long long cost[N];
ll lim[N];
int n, k;
int n1, n2;

vector<int> w[N];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x *= 2;
        
        if (y == 1) {
            a[n1++] = make_pair(x, i + 1);
        } else {
            b[n2++] = make_pair(x, i + 1);
        } 
        
        cost[i + 1] = x;
    }
    
    sort(a, a + n1, greater<pair<long long, int> >());
    sort(b, b + n2, greater<pair<long long, int> >());
    
    for (int i = 0; i < n1; ++i)
        if (i < k) { 
            w[i].push_back(a[i].second);
        }
        else { 
            w[k - 1].push_back(a[i].second);
        }
    
    if (n1 < k) {
        for (int i = 0; i < n2; ++i)
            if (n1 + i < k) {
                w[n1 + i].push_back(b[i].second);
            } else {
                w[k - 1].push_back(b[i].second);
            }
    } else {
        for (int i = 0; i < n2; ++i) w[k - 1].push_back(b[i].second);
    }
    
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ll mn = cost[w[i][0]];
        for (int j = 0; j < w[i].size(); ++j) {
            ans += cost[w[i][j]];
            mn = min(mn, cost[w[i][j]]);
        }
        if (i < n1) ans -= mn / 2;
    } 
    
    cout << ans / 2 << ".";
    if (ans & 1) cout << "5\n";
    else cout << "0\n";
    
    for (int i = 0; i < k; ++i) {
        cout << w[i].size();
        for (int j = 0; j < w[i].size(); ++j) cout << " " << w[i][j];
        cout << endl;
    }
    
    return 0;
}