#include <bits/stdc++.h>
using namespace std;

int n;
int x[110];
int ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    int s = 10;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        s += x[i];
        if(s > 720) break;
        cnt++;
        ans += max(0, s - 360);
    }
    cout << cnt << ' ' << ans;
}