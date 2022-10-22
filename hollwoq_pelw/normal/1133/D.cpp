#include <bits/stdc++.h>
using namespace std;

int n;
map<pair<int, int>, int> mp;
int main(){
    cin >> n;
    int a[n],b[n];
    int ans = 0, as = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++){
        if (a[i] == 0){
            if (b[i] == 0) ans ++;
            continue;
        }
        int m = __gcd(a[i], -b[i]);
        b[i] /= -m;
        a[i] /= m;
        if (a[i] < 0) b[i] *= -1; a[i] *= -1;
        mp[{b[i], a[i]}]++;
    }
    for (auto& [p, v]: mp){
        //cout << p.first << ' ' << p.second << "\n";
        as = max(as, v);
    }
    cout << as+ans;
    return 0;
}
/*
\||/     \||/     ?+==-==-== 
 |/       \|      ?|/         |
 ||   +   ||   |  |/   |      ++=   
 -|==???==|-  =+  |++==+==-=     
 ||   +   ||   |  |\   |      ++=
 |\       /|      ?|\         |
/||\     /||\     ?+==-==-== 
*/