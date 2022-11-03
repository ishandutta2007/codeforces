#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    set<int> s;
    int x;
    int mx = 0;
    for(int i = 0; i < 2 * n; ++i){
        cin >> x;
        if(s.count(x) > 0){
            s.erase(x);
        }else{
            s.insert(x);
        }
        mx = max(mx, (int)s.size());
    }
    cout << mx << endl;
    return 0;
}