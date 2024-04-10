#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, b, a, maxb, maxa;
    cin >> n >> maxb >> maxa;
    b = maxb;
    a = maxa;
    int d = 0;
    bool s;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (b > 0 && s && a < maxa) {b--; a++;}
        else if(a > 0) a--;
        else if(b > 0) b--;
        else break;
        d++;
    }
    cout << d;
    
}