#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map <pair <int, int>, char> edge;
set <pair <int, int>> isti;
set <pair <int, int>> svi;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    while(m--){
        char t;
        cin >> t;
        if(t == '+'){
            int a, b;
            char c;
            cin >> a >> b >> c;
            edge[{a, b}] = c;
            if(edge[{b, a}] == c) isti.insert({min(a, b), max(a, b)});
            if(edge[{b, a}] >= 'a' && edge[{b, a}] <= 'z') svi.insert({min(a, b), max(a, b)});
        }
        if(t == '-'){
            int a, b;
            cin >> a >> b;
            edge[{a, b}] = '-';
            isti.erase({min(a, b), max(a, b)});
            svi.erase({min(a, b), max(a, b)});
        }
        if(t == '?'){
            int x;
            cin >> x;
            x %= 2;
            if(x == 0) cout << ((isti.size() > 0) ? "YES\n" : "NO\n");
            else cout << ((svi.size() > 0) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}