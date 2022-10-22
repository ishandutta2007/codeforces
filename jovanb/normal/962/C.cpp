#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string n;
ll r;
ll maxres = 0;

void brut(ll tren, ll pos, ll cif){
    ll nes;
    if(pos == r-1){
        if(n[pos] == '0'){
            if(cif != 0){
                ll x = tren*10;
                nes = sqrtl(x);
                if(nes*nes == x) maxres = max(maxres, cif+1);
                nes = sqrtl(tren);
                if(nes*nes == tren) maxres = max(maxres, cif);
            }
        }
        else{
            ll x = tren*10+(n[pos]-'0');
            nes = sqrtl(x);
            if(nes*nes == x) maxres = max(maxres, cif+1);
            nes = sqrtl(tren);
            if(nes*nes == tren) maxres = max(maxres, cif);
        }
        return;
    }
    if(!(n[pos] == '0' && cif == 0)) brut(tren*10+(n[pos]-'0'), pos+1, cif+1);
    brut(tren, pos+1, cif);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    r = n.size();
    brut(0, 0, 0);
    if(maxres == 0) cout << -1;
    else cout << r-maxres;
    return 0;
}