#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < 3; i++){
        cin >> a;
        cur += a;
    }
    ans += (cur / 5) + (cur % 5 ? 1 : 0);
    cur = 0;

    for(int i = 0; i < 3; i++){
        cin >> a;
        cur += a;
    }
    ans += (cur / 10) + (cur % 10 ? 1 : 0);

    cin >> cur;
    cout << (ans > cur ? "NO" : "YES") << endl;
    return 0;
}