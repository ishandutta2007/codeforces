#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

int x[5];
int y[5];

void solve(){
    for(int i=0;i<3;i++) cin >> x[i] >> y[i];
    vector<int> wys;
    for(int i=0;i<3;i++) wys.pb(y[i]);
    sort(wys.begin(), wys.end());
    vector<tuple<int, int, int, int> > ans;

    vector<int> xx, yy;
    for(int i=0;i<3;i++){
        xx.pb(x[i]);
        yy.pb(y[i]);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());

    if(xx[0] != xx[2]) ans.pb(mt(xx[0], wys[1], xx[2], wys[1]));
    for(int i=0;i<3;i++){
        if(y[i] != wys[1]){
            ans.pb(mt(x[i], y[i], x[i], wys[1]));
        }
    }
    cout << ans.size() << "\n";
    for(auto [a,b,c,d] : ans){
        cout << a << " " << b << " " << c << " " << d << "\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}