#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

multiset <int> coords;
multiset <int> raz;

int p[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> p[i];
        coords.insert(p[i]);
    }
    sort(p+1, p+1+n);
    for(int i=2; i<=n; i++){
        raz.insert(p[i] - p[i-1]);
    }
    if(raz.empty()) cout << 0 << "\n";
    else cout << *coords.rbegin() - *coords.begin() - *raz.rbegin() << "\n";
    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            coords.insert(x);
            auto gde = coords.find(x);
            if(gde != coords.begin()){
                auto g = gde;
                g--;
                raz.insert((*gde) - (*g));
            }
            auto d = gde;
            d++;
            if(d != coords.end()){
                raz.insert((*d) - (*gde));
            }
            if(gde != coords.begin() && d != coords.end()){
                auto pd = gde;
                pd--;
                raz.erase(raz.find((*d) - (*pd)));
            }
        }
        else{
            auto gde = coords.find(x);
            if(gde != coords.begin()){
                auto g = gde;
                g--;
                raz.erase(raz.find((*gde) - (*g)));
            }
            auto d = gde;
            d++;
            if(d != coords.end()){
                raz.erase(raz.find((*d) - (*gde)));
            }
            if(gde != coords.begin() && d != coords.end()){
                auto pd = gde;
                pd--;
                raz.insert((*d) - (*pd));
            }
            coords.erase(coords.find(x));
        }
        if(raz.empty()) cout << 0 << "\n";
        else cout << *coords.rbegin() - *coords.begin() - *raz.rbegin() << "\n";
    }
    return 0;
}