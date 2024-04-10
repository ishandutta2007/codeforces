#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    if(n==3){
        cout << "2\n";
        cout << "1 1\n2 2\n";
        return 0;
    }
    int ans = 0; int num = 0;
    int v = (n+2)/3;
    bool f = false;
    if(n%3==0)f = true;
    cout << v+v-1+f << "\n";
    if(f)n--;
    for(int i = 1; i<=v; i++){
        cout << i << " " << v+1-i << "\n";
    }
    v--;
    for(int i = 1; i<=v; i++){
        cout << n+1-i << " " << n-v+i << "\n";
    }
    if(f){
        cout << n+1 << " " << n+1 << "\n";
    }
    return 0;
}