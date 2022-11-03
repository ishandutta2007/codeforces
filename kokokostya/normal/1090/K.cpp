#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = (int)1e9;
const ll md = (ll)1e9 + 7, inf64 = (ll)1e18;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    int n;

    cin >> n;

    map< pair< string, int >, vector< int > > a;

    for(int i = 0;i < n;i++) {
        string s, t;
        cin >> s >> t;
        int mask = 0;
        for(char c : t) {
            mask |= (1 << (c - 'a'));
        }
        while(!s.empty() && ((1 << (s.back() - 'a')) & mask)) {
            s.pop_back();
        }
        a[{s,mask}].push_back(i);
    }

    cout << (int)a.size() << "\n";

    for(auto pr : a) {
        vector< int > &ar = pr.second;
        cout << (int)ar.size() << " ";
        for(int x : ar) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}