#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        set<int> s;
        for(int x; n; n -= 1){
            cin >> x;
            s.insert(x);
        }
        cout << s.size() << "\n";
    }
    return 0;
}