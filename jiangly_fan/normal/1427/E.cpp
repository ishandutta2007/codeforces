#include<bits/stdc++.h>
using namespace std;
using LL = long long;
vector<tuple<LL, char, LL>> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL x;
    cin >> x;
    ans.push_back({x, '+', x});
    LL y = x + x;
    LL z = y ^ x;
    ans.push_back({y, '^', x});
    LL f = x + z;
    ans.push_back({x, '+', z});
    int L = -1, R = -1;
    for(int i = 0; i <= 60; i += 1) if((f >> i) & 1){
        L = i;
        if(R == -1) R = i;
    }
    LL g = f;
    for(int i = 0; i < L - R; i += 1){
        ans.push_back({g, '+', g});
        g <<= 1;
    }
    LL b = g + f;
    ans.push_back({g, '+', f});
    ans.push_back({b, '^', f});
    b ^= f;
    ans.push_back({b, '^', g});
    b ^= g;
    LL a = x;
    while(a != 1 and b != 1){
        while(a >= b){
            LL c = b;
            while((c << 1) <= a){
                ans.push_back({c, '+', c});
                c <<= 1;
            }
            ans.push_back({a, '^', c});
            a ^= c;
        }
        if(a < b){
            LL c = a;
            while(__builtin_popcountll(c) > 1){
                while(c < b){
                    ans.push_back({c, '+', c});
                    c <<= 1;
                }
                ans.push_back({c, '^', b});
                c ^= b;
            }
            b = c;
        }
    }
    cout << ans.size() << endl;
    assert(ans.size() <= 100000);
    for(auto [x, y, z] : ans) cout << x << " " << y << " " << z << "\n";
    return 0;
}