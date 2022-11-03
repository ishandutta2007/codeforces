#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int k;
    cin >> k;
    vector<int> v;
    for(int i = 0; i < 1000; ++i){
        v.push_back((i * (i + 1)) / 2);
    }
    vector<int> w;
    do{
        while(v.back() > k){
            v.pop_back();
        }
        w.push_back(v.size());
        k -= v.back();
    }while(k);
    for(int i = 0; i < w.size(); ++i){
        for(int j = 0; j < w[i]; ++j){
            cout << char('a' + i);
        }
    }
    cout << endl;



}