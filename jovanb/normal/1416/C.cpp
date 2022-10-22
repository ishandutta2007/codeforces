#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int sol;
ll cnt;

void resi(int st, const vector <vector <int>> &vectors){
    ll t0 = 0, t1 = 0;
    vector <vector <int>> nv;
    for(auto vec : vectors){
        ll c0 = 0, c1 = 0;
        vector <int> zeroes;
        vector <int> ones;
        for(int i=0; i<vec.size(); i++){
            if((1 << st) & vec[i]){
                c1++;
                t1 += c0;
                ones.push_back(vec[i]);
            }
            else{
                c0++;
                t0 += c1;
                zeroes.push_back(vec[i]);
            }
        }
        if(zeroes.size()) nv.push_back(zeroes);
        if(ones.size()) nv.push_back(ones);
    }
    cnt += min(t0, t1);
    if(t0 > t1) sol += (1 << st);
    if(st == 0) return;
    resi(st-1, nv);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector <int> vec;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    vector <vector <int>> nv = {vec};
    resi(30, nv);
    cout << cnt << " " << sol << "\n";
    return 0;
}