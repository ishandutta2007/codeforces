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
    int n, m;
      cin >> n >> m;
  //  n = m = 200000;
    vector<int> a(n);
    vector<int> c(m, 0);
    vector<int> s(m, 0);
    vector<set<int>> pos(m);
    for(int i = 0; i < n; ++i){
            cin >> a[i];
    //    a[i] = 0;
        ++c[a[i] % m];
        pos[a[i] % m].insert(i);
    }
    if(m == 1){
        cout << "0\n";
        for(int i = 0; i < n; ++i){
            if(i){
                cout << " ";
            }
            cout << a[i];
        }
        cout << endl;
        return 0;
    }
    s[0] = c[0] - n / m;
    ll mn = s[0];
    int idxmn = 0;
    for(int i = 1; i < m; ++i){
        s[i] = s[i - 1] + c[i] - n / m;
        if(mn > s[i]){
            mn = s[i];
            idxmn = i;
        }
    }
    vector<int> old(m, n), neu(m, n);
    vector<pii> vv;
    for(int i = 0; i < n; ++i){
        vv.push_back({(a[i] + m - idxmn - 1) % m, i});
    }
    sort(all(vv));
    int ptr1, ptr2;
    ptr1 = 0;
    for(int i = 0; i < n; ++i){
        while(vv[i].first >= ptr1){
            old[ptr1] = i;
            ++ptr1;
        }
    }
    neu = old;
    ll oper = 0;
    for(int i = (idxmn + 1) % m, j = 0; j < m; i = (i + 1) % m, ++j){
        neu[j + 1] -= (s[i] - mn);
        oper += (s[i] - mn);
    }
    ptr1 = 0, ptr2 = 0;
    for(int i = 0; i < n; ++i){
        while(old[ptr1] <= i && ptr1 < m){
            ++ptr1;
        }
        while(neu[ptr2] <= i && ptr2 < m){
            ++ptr2;
        }
        --ptr1;
        --ptr2;
        a[vv[i].second] += ptr2 - ptr1;
    }
    cout << oper << endl;
    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;


}