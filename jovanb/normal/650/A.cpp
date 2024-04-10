#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map <pair <ll, ll>, ll> brkord;
map <ll, ll> kordx;
map <ll, ll> kordy;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    pair <ll, ll> kord;
    ll br=0;
    int n;
    cin >> n;
    while(n--){
        cin >> kord.first >> kord.second;
        br += kordx[kord.first] + kordy[kord.second] - brkord[{kord.first, kord.second}];
        kordx[kord.first]++;
        kordy[kord.second]++;
        brkord[{kord.first, kord.second}]++;
    }
    cout << br;
    return 0;
}