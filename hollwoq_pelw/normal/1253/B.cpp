#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    set<int> inday;
    set<int> outday;
    vector<int> res;
    int bef = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > 0){
            if (inday.count(a[i])) {cout << -1; return 0;}
            inday.insert(a[i]);
        }else{
            if (!inday.count(-a[i]) || outday.count(-a[i])) {cout << -1; return 0;}
            outday.insert(-a[i]);
        }
        if (inday.size() == outday.size()){
            res.push_back(i+1-bef);
            bef = i+1;
            inday.clear();
            outday.clear();
        }
    }
    if (inday.size() != outday.size()){cout << -1; return 0;}
    cout << res.size() << endl;
    for (int i:res) cout << i << ' ';
    return 0;
}