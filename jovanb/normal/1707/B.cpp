#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector <int> novi;

void uradi(const vector <int> &vec, int &c0){
    novi.clear();
    if(vec.size() && c0) novi.push_back(vec[0]);
    if(c0) c0--;
    for(int i=1; i<vec.size(); i++){
        if(vec[i] == vec[i-1]) c0++;
        else novi.push_back(vec[i] - vec[i-1]);
    }
    sort(novi.begin(), novi.end());
}

void solve(){
    int n;
    cin >> n;
    vector <int> vec;
    int c0 = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x == 0) c0++;
        else vec.push_back(x);
    }
    novi = vec;
    while(novi.size() + c0 > 1){
        vec = novi;
        uradi(vec, c0);
        ///cout << c0 << " ";
        ///for(auto c : novi) cout << c << " ";
        ///cout << endl;
    }
    if(c0) cout << 0 << "\n";
    else cout << novi[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
5
0 0 0 8 13
*/