#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

vector<ll> p, a, b;
bool comp(int& o1, int& o2){
    if(p[o1] == p[o2]){
        return o1 < o2;
    }
    return p[o1] < p[o2];
}


int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    p.resize(n);
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        --b[i];
    }
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        v[i] = i;
    }
    sort(v.begin(), v.end(), &comp);
    vector<int> w[3];
    for(int i = 0; i < v.size(); ++i){
        if(a[v[i]] == b[v[i]]){
            w[a[v[i]]].push_back(v[i]);
        }else{
            w[a[v[i]]].push_back(v[i]);
            w[b[v[i]]].push_back(v[i]);
        }
    }
    int ptr[3] = {0, 0, 0};
    cin >> m;
    vector<ll> c(m);
    vector<char> mkd(n, 0);
    int cur;
    for(int i = 0; i < m; ++i){
        cin >> c[i];
        --c[i];
        if(i){
            cout << " ";
        }
        while(ptr[c[i]] < w[c[i]].size() && mkd[w[c[i]][ptr[c[i]]]]){
            ++ptr[c[i]];
        }
        if(ptr[c[i]] == w[c[i]].size()){
            cout << "-1";
        }else{
            cur = w[c[i]][ptr[c[i]]];
            mkd[cur] = 1;
            cout << p[cur];
        }
    }
    cout << endl;



    return 0;
}