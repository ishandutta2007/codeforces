#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,d;
    cin >> n >> m >> d;
    int c[m], w[m+1];
    for (int i = 0; i < m; i ++){
        cin >> c[i];
        n -= c[i]; // number of water cells
    }
    int k = 0; // index of water cells
    if ((d-1)*(m+1) < n){
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    memset(w, 0, sizeof(w));
    while(n){
        w[k] = min(n, d-1);
        n -= min(n, d-1);
        k++;
    }
    for (int i = 0; i < m; i ++){
        while(w[i]--){
            cout << 0 << ' ';
        }
        while(c[i]--){
            cout << i+1 << ' ';
        }
    }
    while(w[m]--){
        cout << 0 << ' ';
    }
    return 0;
}