#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n, h;
int a[1005];
multiset<int> now;

bool can(int index) {
    now.insert(a[index]);
    auto itr = now.begin();
    if((index % 2) == 0) itr++;
    int height = 0;
   // cerr << endl;
    //cerr << index << endl;
    while(true) {
        height += *itr;
        //cerr << *itr << endl;
        itr++;
        if(itr == now.end()) break;
        //cerr << " " << *itr << endl;
        itr++;
    }
    return (height <= h);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> h;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(!can(i)) {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}