#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct info{
    ll res = 0;
    string pocetak = "";
    string zavrsetak = "";
};

map <string, info> val;

info mrg(info a, info b){
    info res;
    res.res = a.res + b.res;
    res.pocetak = a.pocetak + b.pocetak;
    res.zavrsetak = a.zavrsetak + b.zavrsetak;
    while(res.pocetak.size() >= 4) res.pocetak.pop_back();
    while(res.zavrsetak.size() >= 4) res.zavrsetak.erase(0, 1);
    int sza = a.zavrsetak.size();
    int szb = b.pocetak.size();
    if(sza >= 3 && szb >= 1){
       if(a.zavrsetak[sza-3] == 'h' && a.zavrsetak[sza-2] == 'a' && a.zavrsetak[sza-1] == 'h' && b.pocetak[0] == 'a') res.res++;
    }
    if(sza >= 2 && szb >= 2){
        if(a.zavrsetak[sza-2] == 'h' && a.zavrsetak[sza-1] == 'a' && b.pocetak[0] == 'h' && b.pocetak[1] == 'a') res.res++;
    }
    if(sza >= 1 && szb >= 3){
        if(a.zavrsetak[sza-1] == 'h' && b.pocetak[0] == 'a' && b.pocetak[1] == 'h' && b.pocetak[2] == 'a') res.res++;
    }
    return res;
}

void solve(){
    int ops;
    cin >> ops;
    ll res = 0;
    val.clear();
    while(ops--){
        string s;
        cin >> s;
        string znak;
        cin >> znak;
        if(znak == ":="){
            string str;
            cin >> str;
            info tr;
            tr.pocetak = str;
            tr.zavrsetak = str;
            string treba = "haha";
            for(int i=0; i<str.size(); i++){
                for(int j=0; j<4; j++){
                    if(i+j >= str.size() || str[i+j] != treba[j]) break;
                    if(j == 3) tr.res++;
                }
            }
            val[s] = tr;
        }
        else{
            string a;
            cin >> a;
            string b;
            cin >> b;
            cin >> b;
            val[s] = mrg(val[a], val[b]);
        }
        res = val[s].res;
    }
    cout << res << "\n";
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