#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n+1];
    memset(a, 0, sizeof(a));
    int tp = 1;
    for (int i = 2; i <= n; i++){
        if (!a[i]){
            for (int x = i; x <= n; x+=i){
                if (!a[x]) a[x] = tp;
            }
            tp ++;
        }
    }
    for (int i = 2; i <= n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}