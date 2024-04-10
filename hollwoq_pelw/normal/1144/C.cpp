#include <bits/stdc++.h>
using namespace std;

int n, x;
map<int, int> a;
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        a[x] ++;
    }
    vector<int> dec,inc;
    for (auto& [k, v]:a){
        if (v > 2) return cout << "NO", 0;
        inc.push_back(k);
        if (v == 2) dec.push_back(k);
    }
    cout << "YES\n";
    cout << inc.size() << endl;
    for (int i = 0; i < inc.size(); i++){
        cout << inc[i] << ' ';
    }
    cout << endl << dec.size() << endl;
    for (int i = dec.size()-1; i >= 0; i--){
        cout << dec[i] << ' ';
    }
    return 0;
}