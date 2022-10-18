#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int n, s, a, b;
    int ras[1001];
    for (int i = 0; i < 1001; i++){
        ras[i] = 0;
    }
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if (ras[a] < b){
            ras[a] = b;
        }
    }
    int tek = -1;
    for (int i = s; i >= 0; i--){
        tek++;
        if (ras[i] > tek){
            tek = ras[i];
        }
    }
    cout << tek;
}