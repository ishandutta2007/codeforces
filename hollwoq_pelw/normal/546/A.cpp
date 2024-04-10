#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,w,res;
    cin >> k >> n >> w;
    res = k*(w+1)*w/2;
    if (res < n) cout << 0;
    else cout << res-n;
    return 0;
}