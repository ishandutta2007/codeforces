#include<bits/stdc++.h>

using namespace std;

const int MAXN = 300;

int n, m, k, t;
vector <int> v;

void ubaci (int x) {
    //cout << "ubacujem" << endl;
    int lim = v.size();
    vector <int> res;
    for (int i=0; i<x-1; i++) res.push_back(v[i]);
    res.push_back(0);
    for (int i=x-1; i<lim; i++) res.push_back(v[i]);
    v = res;
}

int nadi (vector <int> vv) {
    for (int i=0; i<vv.size(); i++) {
        if (vv[i] == 1) return i+1;
    }
    return -1;
}

void razdvoji (int ind) {
    //cout << "razdvajam" << endl;
    vector <int> a, b;
    for (int i=0; i<v.size(); i++) {
        if (i < ind) a.push_back(v[i]); else b.push_back(v[i]);
    }
    if (nadi(a) != -1) v = a; else v = b;
}

int main () {
    cin >> n >> k >> m >> t;
    for (int i=1; i<=n; i++) {
        v.push_back(i == k);
    }
    for (int i=0; i<t; i++) {
        int tip, ind;
        cin >> tip >> ind;
        if (tip == 1) {
            ubaci(ind);
        } else {
            razdvoji(ind);
        }
        cout << v.size() << " " << nadi(v) << endl;
        //for (auto x : v) cout << x; cout << endl;
    }
    return 0;
}