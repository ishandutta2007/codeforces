#include <bits/stdc++.h>
using namespace std;

int ans[16] = {0, 1, 0, 1, 0, 0, 0, 1,
               1, 1, 0, 0, 1, 1, 0, 1};
int main(){
    int x = 0;
    for(int i=0; i<4; i++){
        int t;
        cin >> t;
        x |= (t << i);
    }
    cout << ans[x];
}