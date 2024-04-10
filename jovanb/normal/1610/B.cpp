#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

int a[200005];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        if(a[i] != a[n-i+1]){
            vector <int> vec;
            for(int j=1; j<=n; j++) if(a[j] != a[i]) vec.push_back(a[j]);
            bool moze = 1;
            for(int i=0; i<vec.size(); i++) if(vec[i] != vec[vec.size()-1-i]) moze = 0;
            if(moze){
                cout << "YES\n";
                return;
            }
            vec.clear();
            for(int j=1; j<=n; j++) if(a[j] != a[n-i+1]) vec.push_back(a[j]);
            moze = 1;
            for(int i=0; i<vec.size(); i++) if(vec[i] != vec[vec.size()-1-i]) moze = 0;
            if(moze){
                cout << "YES\n";
                return;
            }
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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