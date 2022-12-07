#include <bits/stdc++.h>
using namespace std;
int a[1 << 22];
int vis[1 << 22];
int exists[1 << 22];
int xorMask = (1 << 22) - 1;
int n;
void dfs(int i) {
    vis[i] = 1;
    for(int j = 0; j < n; ++j) {
        if((i >> j & 1) == 1 && vis[i ^ (1 << j)] == 0)
            dfs(i ^ (1 << j));
    }
    if(exists[i] == 1 && vis[i ^ xorMask] == 0)
        dfs(i ^ xorMask);
}
int main()
{
	int m;
    cin >> n >> m;
    
    xorMask = (1 << n) - 1;
    
    for(int i = 0; i < (1 << n); ++i) {
        vis[i] = 0;
        exists[i] = 0;
    }
    
    for(int i = 0; i < m; ++i) {
        cin >> a[i];
        exists[a[i]] = 1;
    }
    
    int cnt = 0;
    
    for(int i = 0; i < (1 << n); ++i) {
        if(exists[i] == 1 && vis[i] == 0) {
            dfs(i);
            cnt++;
        }
    }
    
    cout << cnt;
    
	return 0;
}