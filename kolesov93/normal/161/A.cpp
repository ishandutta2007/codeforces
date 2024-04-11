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
typedef unsigned long long ull;

#define N 222222

int n,m;
long long x,y;

pair<int, long long> a[N], b[N];

vector<pair<int,int> > w; 

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d%d", &n, &m);
    cin >> x >> y;
    for (int i = 0; i < n; ++i) {
        int c;
        scanf("%d", &c);
        a[i].first = c;
        a[i].second = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        int c;
        scanf("%d", &c);
        b[i].first = c;
        b[i].second = i + 1;
    }
    
    sort(a, a + n);
    sort(b, b + m);
    
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        while (cur < m && b[cur].first < a[i].first - x) cur++;
        if (cur >= m) break;
        
        if (b[cur].first <= a[i].first + y) {
            w.push_back(make_pair(b[cur].second, a[i].second));
            cur++;
        }
     }
     
     
     printf("%d\n", (int) w.size());
     for (int i = 0; i < w.size(); ++i) printf("%d %d\n", w[i].second, w[i].first);
     
    return 0;
}