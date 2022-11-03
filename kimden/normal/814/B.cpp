#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a, b, c, d, e;
    int suma = 0, sumb = 0, sum = 0;
    a.resize(n);
    b.resize(n);
    d.resize(n + 1);
    e.resize(n + 1);
    for(int i = 0; i < n; ++i){
        sum += i + 1;
        cin >> a[i];
        suma += a[i];
        ++d[a[i]];
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        sumb += b[i];
        if(a[i] != b[i]){
            c.push_back(i);
        }
        ++e[b[i]];
    }
    int u1, v1, u2, v2;
    for(int i = 1; i <= n; ++i){
        if(d[i] == 0){
            u1 = i;
        }
        if(d[i] == 2){
            v1 = i;
        }
        if(e[i] == 0){
            u2 = i;
        }
        if(e[i] == 2){
            v2 = i;
        }
    }
    if(c.empty()){
        for(int i = 0; i < n; ++i){
            if(a[i] == v1){
                a[i] = u1;
                for(int j = 0; j < n; ++j){
                    if(j){
                        cout << " ";
                    }
                    cout << a[j];
                }
                cout << endl;
                return 0;
            }
        }
    }else{
        if(c.size() == 1){
            a[c[0]] = u1;
            for (int j = 0; j < n; ++j) {
                if (j) {
                    cout << " ";
                }
                cout << a[j];
            }
            cout << endl;
            return 0;
        }else {
            if (a[c[0]] == v1 && b[c[0]] == u1 && b[c[1]] == v2 && a[c[1]] == u2) {
                a[c[0]] = u1;
                for (int j = 0; j < n; ++j) {
                    if (j) {
                        cout << " ";
                    }
                    cout << a[j];
                }
                cout << endl;
                return 0;
            }
            if (a[c[1]] == v1 && b[c[1]] == u1 && b[c[0]] == v2 && a[c[0]] == u2) {
                a[c[1]] = u1;
                for (int j = 0; j < n; ++j) {
                    if (j) {
                        cout << " ";
                    }
                    cout << a[j];
                }
                cout << endl;
                return 0;
            }
        }
    }


    return 0;
}