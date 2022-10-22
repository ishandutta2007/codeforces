#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(n); i++)

int main(){
    ll n; cin >> n;
    map<string,ll> str;
    map<string,string> daihyou;
    rep(i,n){
        string s; cin >> s;
        ll t = s.size();
        set<string> se;
        for(ll i=1; i<=t; i++){
            rep(j,t-i+1){
                string ss = s.substr(j,i);
                if(se.find(ss) == se.end()){
                    se.insert(ss);
                    str[ss]++;
                }
                daihyou[ss] = s;
            }
        }
        se.clear();
    }
    ll q; cin >> q;
    while(q--){
        string x; cin >> x;
        if(str.find(x)!=str.end()) cout << str[x] << " " << daihyou[x] << endl;
        else cout << 0 << " " << "-" << endl;
    }
}