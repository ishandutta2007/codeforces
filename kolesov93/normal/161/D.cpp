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

const int N = 111111;
const int M = 555;

int n, k;
int f[N][M];
int fir[N+N], nxt[N+N], tov[N+N];
int ke;
vector<int> sons[N];
bool used[N];

ll ans = 0;

void dfs(int x) {
    used[x] = true;
    for (int t = fir[x]; t; t = nxt[t])
        if (!used[tov[t]]) {
            dfs(tov[t]);
            sons[x].push_back(tov[t]);
            
            for (int i = 1; i <= k; ++i)
                f[x][i] += f[tov[t]][i - 1];
        }
    
    f[x][0] = 1;
    ans += f[x][k];
    
    ll add = 0;
    
    for (int i = 0; i < sons[x].size(); ++i)
        for (int j = 0; j + 1 < k; ++j) {
            ll mul = f[x][k - j - 1];
            if (k - j - 2 >= 0) mul -= f[ sons[x][i] ][k - j - 2];
            add += ll(f[ sons[x][i] ][j]) * mul;
        }
    
    ans += add / 2;
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d%d",&n,&k);
    for (int i = 1; i < n; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        nxt[++ke] = fir[a]; fir[a] = ke; tov[ke] = b; 
        nxt[++ke] = fir[b]; fir[b] = ke; tov[ke] = a; 
    }
    
    dfs(1);
    
    cout << ans << endl;
    
    return 0;
}