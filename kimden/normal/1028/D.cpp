#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll mod = 1'000'000'007;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    set<int> unk;
    set<int> buy;
    set<int> sell;
    vector<int> x(n);
    vector<string> s(n);
    map<int, int> mp;
    ll ans = 1;
    for(int i = 0; i < n; ++i){
        cin >> s[i] >> x[i];

        if(s[i] == "ADD"){
            if(!buy.empty() && -*buy.begin() > x[i]){
                buy.insert(-x[i]);
                mp[x[i]] = 1;
            }else if(!sell.empty() && *sell.begin() < x[i]){
                sell.insert(x[i]);
                mp[x[i]] = 2;
            }else{
                unk.insert(x[i]);
            }
        }else{
            int z = mp[x[i]];
            if(z == 0){
                ans = (ans * 2) % mod;
                unk.erase(x[i]);
                if(!buy.empty() && -*buy.begin() > x[i]){
                    cout << 0 << endl;
                    return 0;
                }
                if(!sell.empty() && *sell.begin() < x[i]){
                    cout << 0 << endl;
                    return 0;
                }
                for(auto p: unk){
                    if(p < x[i]){
                        buy.insert(-p);
                        mp[p] = 1;
                    }else{
                        sell.insert(p);
                        mp[p] = 2;
                    }
                }
                unk.clear();
            }else if(z == 1){
                if(-*buy.begin() > x[i]){
                    cout << 0 << endl;
                    return 0;
                }
                if(!sell.empty() && *sell.begin() < x[i]){
                    cout << 0 << endl;
                    return 0;
                }
                for(auto p: unk){
                    if(p < x[i]){
                        buy.insert(-p);
                        mp[p] = 1;
                    }else{
                        sell.insert(p);
                        mp[p] = 2;
                    }
                }
                unk.clear();
                buy.erase(-x[i]);
            }else{
                if(*sell.begin() < x[i]){
                    cout << 0 << endl;
                    return 0;
                }
                if(!buy.empty() && -*buy.begin() > x[i]){
                    cout << 0 << endl;
                    return 0;
                }
                for(auto p: unk){
                    if(p < x[i]){
                        buy.insert(-p);
                        mp[p] = 1;
                    }else{
                        sell.insert(p);
                        mp[p] = 2;
                    }
                }
                unk.clear();
                sell.erase(x[i]);
            }
        }
    }
    ans = (ans * ((ll)unk.size() + 1)) % mod;
    cout << ans << endl;
}