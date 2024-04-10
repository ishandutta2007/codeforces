#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    long n,m,p;
    cin >> n >> m >> p;
    long a = -1, b = -1, x;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (a == -1 && x%p != 0) a = i;
    }
    for (int i = 0; i < m; i++){
        cin >> x;
        if (b == -1 && x%p != 0) b = i;
    }
    cout << a+b;
}