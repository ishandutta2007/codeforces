#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    string s;
    int n;
    cin >> s >> n;
    if(s.length() < n){
        cout << "impossible" << endl;
        return 0;
    }
    set<char> w;
    for(char& c: s){
        w.insert(c);
    }
    cout << max(0, n - (int)w.size()) << endl;
}