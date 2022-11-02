#include<bits/stdc++.h>
const int inf = 1e9;
using namespace std;
int dx[9] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[9] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, a[105], ans;
bool dt[305][305][31][9], vis[305][305];

void solve (int X, int Y, int T, int D) {
    if(T>n) return;
    if(dt[X][Y][T][D]) return;
    dt[X][Y][T][D] = true;
    for(int i=0;i<=a[T];i++) {
        if(!vis[X+i*dx[D]][Y+i*dy[D]]) {
            ans++;
            vis[X+i*dx[D]][Y+i*dy[D]] = true;
        }
    }
    solve(X+a[T]*dx[D], Y+a[T]*dy[D], T+1, (D+7)%8);
    solve(X+a[T]*dx[D], Y+a[T]*dy[D], T+1, (D+1)%8);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    a[1]--;
    solve(150, 150, 1, 0);
    printf("%d\n",ans);
}