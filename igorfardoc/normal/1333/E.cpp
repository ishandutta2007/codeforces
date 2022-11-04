#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi b = {{4, 3, 6, 12}, {7, 5, 9, 15,}, {14, 1, 11, 10,}, {13, 8, 16, 2}};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    if(n < 3) {
        cout << -1;
        return 0;
    }
    if(n == 3) {
        cout << "1 7 9\n3 2 5\n4 8 6\n";
        return 0;
    }
    vvi a(n, vi(n));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            a[i][j] = b[i][j] + n * n - 16;
        }
    }
    if(n != 4) {
        int now = 1;
        int x = n - 1;
        int y = 0;
        int dir = 1;
        if(n % 2 == 1) {
            x = 0;
            y = n - 1;
            dir = -1;
        }
        while(x != 4 || y != 1) {
            //cout << x << ' ' << y << endl;
            a[x][y] = now;
            ++now;
            if(x == 0 && dir == 1) {
                --y;
                dir = -1;
                continue;
            }
            if(y == 0 && dir == -1) {
                --x;
                dir = 1;
                continue;
            }
            if(dir == 1) {
                if(x > y) {
                    ++y;
                } else {
                    --x;
                }
            } else {
                if(x >= y) {
                    --y;
                } else {
                    ++x;
                }
            }
        }
        a[4][0] = now;
        a[4][1] = now + 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

}