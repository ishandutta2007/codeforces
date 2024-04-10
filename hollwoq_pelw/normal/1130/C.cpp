#include <bits/stdc++.h>
using namespace std;

int n;
char a[55][55];
pair<int, int> cell1, cell2;
vector<pair<int, int>> land1, land2;

void dfs(int n, int r, int c, vector<pair<int, int>>& land){
    land.push_back({r,c});
    a[r][c] = '1';
    //cout << r << ' ' << c << endl;
    if (r > 1 && a[r-1][c] == '0') dfs(n,r-1,c,land);
    if (c > 1 && a[r][c-1] == '0') dfs(n,r,c-1,land);
    if (r < n && a[r+1][c] == '0') dfs(n,r+1,c,land);
    if (c < n && a[r][c+1] == '0') dfs(n,r,c+1,land);
}

int main(){
    int n;
    cin >> n >> cell1.first >> cell1.second >> cell2.first >> cell2.second;
    for (int i = 1; i <= n; i++){
        scanf("%s", a[i]+1);
    }
    dfs(n,cell1.first, cell1.second, land1);
    dfs(n,cell2.first, cell2.second, land2);
    
    int ans = INT_MAX;
    for (auto [r1, c1]:land1){
        for (auto [r2, c2]:land2){
            ans = min(ans, (r1-r2)*(r1-r2)+(c1-c2)*(c1-c2));
        }
    }
    cout << ans;
}
/*
{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}









(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())

 \||/     \||/    \?+==-=-==      |+==|       |+==|       \\=   =//
  |/ |!|!| \|      ?|/       |    ||          ||          |\\+=+//|
  ||   +   ||   |  |/   |    ++=  || )&^@!    || $@^(~    / \\=// \
  +|==???==|+  =+  |++==+=-|      |+   %      |+   *     |  =+X+=  |
  ||   +   ||   |  |\   |    ++=  || ]&"*~    || %'&}!    \ //=\\ /
  |\ |!|!| /|      ?|\       |    ||          ||          |//+=+\\|
 /||\     /||\    /?+==-=-==      |+==+==+=|  |+==+==+=|  //=   =\\

>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<









[[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]]
*/