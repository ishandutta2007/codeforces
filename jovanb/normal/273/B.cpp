#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int MOD;

unordered_map <int, int> br1;
unordered_map <int, int> br2;
vector <int> vec;

ll a[100005];
ll b[100005];

ll res=1;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
        if(a[i] == b[i]) br2[a[i]]++;
        else {br1[a[i]]++; br1[b[i]]++;}
        vec.push_back(a[i]);
        vec.push_back(b[i]);
    }
    cin >> MOD;
    for(auto c : vec){
        if(br1[c] <= 0 && br2[c] <= 0) continue;
        ll tren=0;
        while(br1[c]--){
            res = ((tren+1)*res)%MOD;
            tren++;
        }
        while(br2[c]--){
            res = ((((tren+1)*(tren+2)/2)%MOD)*res)%MOD;
            tren += 2;
        }
    }
    cout << res;
    return 0;
}