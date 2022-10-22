#include <bits/stdc++.h>
using namespace std;
bool d(int n){
    set<int> s;
    while(n){
        if (s.count(n%10)) return false;
        s.insert(n%10);
        n /= 10;
    }
    return true;
}
int main(){
    int l,r;
    cin >> l >> r;
    int ans = -1;
    for (int i = l; i <= r; i ++){
        if (d(i)){
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}