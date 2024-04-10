#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 501;
int a[MAXN][MAXN];

int main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k - 1; j++){
            a[i][j] = cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = k - 1; j < n; j++){
            a[i][j] = cnt++;
            if(j == k - 1){
                ans += a[i][j];
            }
        }
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        if(i){
            cout << "\n";
        }
        for(int j = 0; j < n; j++){
            if(j){
                cout << " ";
            }
            cout << a[i][j];
        }
    }
    return 0;
}