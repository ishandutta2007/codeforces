#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define np make_pair
#define pb push_back
#define fi first
#define se second

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << "YES\n";
    cout << 22 << " ";
    vector<pair<ii, int>> vc;
    for(int i = 2; i <= 21; i++){
        vc.pb(np(np(1, i), 1));
        for(int j = 2; j < i; j++){
            vc.pb(np(ii(j, i), (1 << (j - 2))));
        }
    }
    int l, r;
    int cur;
    cin >> cur >> r;
    int adder = cur;
    r = r - cur;
    cur = 0;
    vc.pb(np(np(1, 22), adder));
    for(int i = 2; i <= 21; i++){
        if(r & (1 << (i - 2))){
            vc.pb(np(np(i, 22), adder + cur));
            cur = cur + (1 << (i - 2));
        }
    }
    cout << vc.size() << endl;
    for(auto i : vc){
        cout << i.fi.fi << " " << i.fi.se << " " << i.se << endl;
    }
}