#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 100000;

void solve(){
    int n;
    cin >> n;
    vector <int> p;
    vector <int> np;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(i%2) np.push_back(x);
        else p.push_back(x);
    }
    sort(np.begin(), np.end());
    sort(p.begin(), p.end());
    vector <int> vec;
    for(int i=0; i<np.size(); i++){
        vec.push_back(np[i]);
        if(i < p.size()) vec.push_back(p[i]);
    }
    for(int i=0; i<vec.size()-1; i++){
        if(vec[i] > vec[i+1]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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