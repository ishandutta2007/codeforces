#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

//const ll mod = 1000000007;
//const ld eps = 1e-8;
const int MAXN = 200002;

int p[MAXN], b[MAXN];
bool mkd[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        p[i]--;
    }
    int bb = 0;
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        bb += b[i];
        bb %= 2;
    }
    int cur;
    int cyc = 0;
    for(int i = 0; i < n; i++){
        if(!mkd[i]){
            cyc++;
            cur = i;
            while (!mkd[cur]) {
//                cout << cur << " ";
                mkd[cur] = true;
                cur = p[cur];
            }
//            cout << endl;
        }
    }
    bb = 1 - bb;
    cout << ((cyc == 1 ? 0 : cyc) + bb) << endl;
    return 0;
}