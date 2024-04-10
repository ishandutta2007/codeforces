#include<bits/stdc++.h>
using namespace std;

int n, m;

char c;
int a[505][505];
int mt1[505][505];
int mt2[505][505];
int ans;

int x1, y11, x2, y2;

signed main(){
    cin >> n >> m;
    for(int i = 0; i <= n + 3; i++){
        for(int j = 0; j <= m + 3; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c;
            a[i][j] = (c == '.');
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            mt1[i][j] = 0;
            mt2[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mt1[i][j] = mt1[i - 1][j] + mt1[i][j - 1] - mt1[i - 1][j - 1];
            mt2[i][j] = mt2[i - 1][j] + mt2[i][j - 1] - mt2[i - 1][j - 1];
            if(a[i][j] == 1 && a[i][j + 1] == 1) mt1[i][j]++;
            if(a[i][j] == 1 && a[i + 1][j] == 1) mt2[i][j]++;
        }
    }
    int o; cin >> o;
    while(o--){
        ans = 0;
        cin >> x1 >> y11 >> x2 >> y2;
        y2--;
        if(y2 >= y11) ans = ans + mt1[x2][y2] - mt1[x1 - 1][y2] - mt1[x2][y11 - 1] + mt1[x1 - 1][y11 - 1];
        y2++;
        x2--;
        if(y2 >= y11) ans = ans + mt2[x2][y2] - mt2[x1 - 1][y2] - mt2[x2][y11 - 1] + mt2[x1 - 1][y11 - 1];
        x2++;
        cout << ans << endl;
    }
}