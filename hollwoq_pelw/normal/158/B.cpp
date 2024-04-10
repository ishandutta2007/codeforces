#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,s[] = {0,0,0,0};
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> k;
        s[k-1] ++;
    }
    int res = s[3]+s[2];
    s[3] = 0;
    if (s[0] > s[2]){
        s[0] -= s[2];
    }else {
        s[0] = 0;
    }
    s[2] = 2;
    res += (s[0]+s[1]*2+3)/4;
    cout << res;
}