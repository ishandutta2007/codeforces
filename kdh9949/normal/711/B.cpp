#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[510][510];
ll rs[510], cs[510], ul, dl;
int x, y;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", a[i] + j);
            if(!a[i][j]) x = i, y = j;
            rs[i] += a[i][j];
            cs[j] += a[i][j];
            if(i == j) dl += a[i][j];
            if(i + j == n - 1) ul += a[i][j];
        }
    }
    if(n == 1){
        puts("1"); return 0;
    }
    ll delta;
    if(x == 0) delta = rs[1] - rs[x];
    else delta = rs[0] - rs[x];
    rs[x] += delta;
    cs[y] += delta;
    if(x == y) dl += delta;
    if(x + y == n - 1) ul += delta;
    bool flag = true;
    for(int i = 0; i < n; i++) if(rs[i] != rs[0]) flag = false;
    for(int i = 0; i < n; i++) if(cs[i] != cs[0]) flag = false;
    if(ul != rs[0] || dl != rs[0]) flag = false;
    if(!flag || delta <= 0) puts("-1");
    else cout << delta;
}