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

int n,m;
bool a[1111][1111];
int ans = 0;

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    cin >> n >> m;
    
    for (int i = 2; i < n + 2; ++i)
        for (int j = 2; j < m + 2; ++j)
            if (!a[i][j]) {
                ans++;
                a[i - 2][j - 1] = 1;
                a[i - 2][j + 1] = 1;
                a[i + 2][j - 1] = 1;
                a[i + 2][j + 1] = 1;
                
                a[i - 1][j - 2] = 1;
                a[i - 1][j + 2] = 1;
                a[i + 1][j - 2] = 1;
                a[i + 1][j + 2] = 1;
            }
    
    memset(a, 0, sizeof(a));
    
    int can = 0;
    for (int j = 2; j < m + 2; ++j)
        for (int i = 2; i < n + 2; ++i)        
            if (!a[i][j]) {
                can++;
                //cout << i << " " << j << endl;
                a[i - 2][j - 1] = 1;
                a[i - 2][j + 1] = 1;
                a[i + 2][j - 1] = 1;
                a[i + 2][j + 1] = 1;
                
                a[i - 1][j - 2] = 1;
                a[i - 1][j + 2] = 1;
                a[i + 1][j - 2] = 1;
                a[i + 1][j + 2] = 1;
            }
    
    int c2 = 0;
    for (int i = 0; i < n; ++i)
        for (int j = (1 & i); j < m; j += 2) c2++;
    c2 = max(c2, n*m-c2);
    can = max(c2, can);
    
    int c1 = max(can, ((m + 2) / 3) * n);
    c1 = max(c1, ((n + 2) / 3) * m);
    cout << max(c1, ans) << endl;
    
    return 0;
}