#include <bits/stdc++.h>
using namespace std;

bool bio[1000005];

int main(){

    int n;
    cin >> n;
    int x;
    cin >> x;
    vector <int> res;
    int pref = 0;
    bio[0] = 1;
    for(int i=1; i<(1<<n); i++){
        if(bio[i^x]) continue;
        bio[i] = 1;
        res.push_back(i^pref);
        pref = i;
    }
    cout << res.size() << "\n";
    for(auto c : res) cout << c << " ";
    return 0;
}