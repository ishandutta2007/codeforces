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

int n;
double R,r;

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
        
    cin >> n >> R >> r;
    int m = 0;
    
    if (r > R) {
        if (n <= m) puts("YES");
        else puts("NO");
        return 0;
    }
    
    m = 1;
    if (r + r > R) {
        if (n <= m) puts("YES");
        else puts("NO");
        return 0;
    }
    
    double c = R - r;
    double alpha = asin(r / c);
    m = floor(1e-6 + (acos(-1.0) / (alpha)));
    
    if (n <= m) puts("YES");
    else puts("NO");
    
    return 0;
}