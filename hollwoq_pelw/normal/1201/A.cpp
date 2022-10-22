#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    string a[n];
    int b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int res = 0;
    for (int j = 0; j < m; j++){
        int c[5] = {0,0,0,0,0};
        for (int i = 0; i < n; i++){
            c[(int) a[i][j] - 'A'] ++;
        }
        res += *std::max_element(c, c + 5)*b[j];
    }
    cout << res;
}