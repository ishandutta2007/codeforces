#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0, a; j < m; j++){
            cin >> a;
            if (i % 2 == j % 2)
                cout << 720720 << ' ';
            else
                cout << 720720 - a * a * a * a << ' ';
        }
        cout << endl;
    }
}