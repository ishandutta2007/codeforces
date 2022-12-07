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

const int N = 411111;
int n, l, v1, v2;
long long a[N];

struct cell {
    double x;
    int val;
    
    bool operator <(const cell& A) const {
        return x < A.x || (x == A.x && val > A.val);
    }
} b[N];

int m = 0;
void add(double L, double R) {
    if (L < 0) {
        add(double(2*l) + L, double(2*l));
        add(0, R);
        return; 
    }
    
    b[m].val = 1;
    b[m].x = L;
        
    m++;
        
    b[m].val = -1;
    b[m].x = R;
    
    m++;
}

double ans[N];

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d%d%d%d", &n, &l, &v1, &v2);
    for (int i = 0; i < n; ++i) { 
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    
    double t = double(l) / double(v1 + v2);
    double d = t * double(v2);
    
    if (d >= 2 * l) {
        ans[n] = 1;
        for (int i = 0; i <= n; ++i) printf("%.15lf\n", ans[i]);
        return 0;
    }
    
    for (int i = 0; i < n; ++i) add(a[i] - d, a[i]);
    b[m].val = 0;
    b[m].x = 0;
    
    m++;
    
    b[m].x = 2 * l;
    b[m].val = 0;
    
    m++;
    
    sort(b, b + m);

    int cur = 0;
    for (int i = 0; i < m; ++i) {
        int ncur = cur;
        cur += b[i].val;
        
        if (i) ans[ncur] += (b[i].x - b[i - 1].x) / (2.0 * double(l));
    }
     
    for (int i = 0; i <= n; ++i) printf("%.15lf\n", ans[i]);
     
    return 0;
}