#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int nums[300001];
int binLift[19][300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> binLift[0][i+1];
    }
    for(int i = 1; i < 19; i++) {
        for(int j = 1; j <= m; j++) {
            if(j + (1 << (i-1)) > m) binLift[i][j] = binLift[i-1][j];
            else binLift[i][j] = max(binLift[i-1][j], binLift[i-1][j + (1 << (i-1))]);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        int k;
        cin >> k;
        if((abs(x1 - x2) % k) || (abs(y1 - y2) % k)) {
            cout << "NO\n";
            continue;
        }
        if(x1 == x2) {
            cout << "YES\n";
            continue;
        }
        int lim = ((n - y1) / k) * k + y1;
        int i = 0;
        x2++;
        while((1 << i) <= abs(x2 - x1)) i++;
        i--;
        int maxi = max(binLift[i][x1], binLift[i][x2 - (1 << i)]);
        if(maxi >= lim) cout << "NO\n";
        else cout << "YES\n";
    }
}