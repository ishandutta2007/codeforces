#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q){
        q--;
        int n;
        cin >> n;
        int a[4*n], b[2*n];
        for (int i = 0; i < 4*n; i++){
            cin >> a[i];
        }
        sort(a,a+4*n);
        bool t = false;
        for (int i = 0; i < 2*n; i++){
            if (a[2*i]!=a[2*i+1]) {
                cout << "NO" << endl;
                t = true;
                break;
            }
            b[i] = a[2*i];
        }
        if (t) continue;
        int s = b[0]*b[2*n-1];
        for (int i = 0; i < n; i++){
            if (b[i]*b[2*n-i-1] != s) {
                cout << "NO" << endl;
                t = true;
                break;
            }
        }
        if (!t) cout << "YES" << endl;
    }
}