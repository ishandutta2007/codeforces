#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct box {
    int in;
    int out;
    int w;
    int s;
    int v;
    
    bool operator<(const box &b) const
    {
        if (in != b.in) {
            return in < b.in;
        } else {
            return out > b.out;
        }
    }
};

int dp[500][1001];
int dp2[501][1000];
vector <box> v;

int dfs(int x, int y)
{
    int i, j;
    
    if (x == -1) {
        int ans = 0, sum = 0;
        
        for (i = 0, j = 0; i < v.size(); i++) {
            int tmp;
            
            if (v[i].w > y) continue;
            
            while (j <= v[i].in) {
                sum = max(sum, dp2[500][j]);
                
                j++;
            }
            
            tmp = sum + dfs(i, min(y - v[i].w, v[i].s)) + v[i].v;
            
            dp2[500][v[i].out] = max(dp2[500][v[i].out], tmp);
            ans = max(ans, tmp);
        }
        
        return ans;
    } else {
        int ans = 0, sum = 0;
        
        if (dp[x][y] >= 0) return dp[x][y];
        
        for (i = v[x].in; i <= v[x].out; i++) dp2[x][i] = 0;
        
        for (i = x + 1, j = v[x].in; i < v.size(); i++) {
            int tmp;
            
            if (v[i].in > v[x].out) break;
            if (v[i].out > v[x].out || v[i].w > y) continue;
            
            while (j <= v[i].in) {
                sum = max(sum, dp2[x][j]);
                
                j++;
            }
            
            tmp = sum + dfs(i, min(y - v[i].w, v[i].s)) + v[i].v;
            
            dp2[x][v[i].out] = max(dp2[x][v[i].out], tmp);
            ans = max(ans, tmp);
        }
        
        return dp[x][y] = ans;
    }
}

int main()
{
    int n, s, i, j;
    
    scanf("%d %d", &n, &s);
    
    for (i = 0; i < n; i++) {
        box b;
        
        scanf("%d %d %d %d %d", &b.in, &b.out, &b.w, &b.s, &b.v);
        
        v.push_back(b);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n; i++) {
        for (j = 0; j <= s; j++) {
            dp[i][j] = -1;
        }
    }
    
    printf("%d\n", dfs(-1, s));
    
    return 0;
}