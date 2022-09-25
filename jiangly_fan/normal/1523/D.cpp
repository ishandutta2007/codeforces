#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, p;
    cin >> n >> m >> p;
    vector<ULL> v;
    for(int i = 0; i < n; i += 1){
        string s;
        cin >> s;
        v.push_back(0);
        for(char c : s) v.back() = v.back() * 2 + (c - '0');
    }
    LL ans = 0;
    srand(time(0));
    for(int _ = 0; _ < 60; _ += 1){
        ULL x = v[(((ULL)rand() << 16) + rand()) % n];
        vector<int> b;
        for(int i = 0; i < m; i += 1) if((x >> i) & 1) b.push_back(i);
        vector<int> cnt(1 << b.size());
        for(ULL y : v){
            ULL z = x & y;
            int f = 0;
            for(int j = 0; j < (int)b.size(); j += 1) if((z >> b[j]) & 1) f |= 1 << j;
            cnt[f] += 1;
        }
        for(int i = 0; i < (int)b.size(); i += 1)
            for(int j = (1 << b.size()) - 1; j >= 0; j -= 1) if((j >> i) & 1)
                cnt[j ^ (1 << i)] += cnt[j];
        int pans = 0;
        for(int i = 0; i < (1 << (int)b.size()); i += 1) if(cnt[i] >= (n + 1) / 2)
            if(__builtin_popcount(pans) < __builtin_popcount(i)) pans = i;
        if(__builtin_popcountll(ans) < __builtin_popcount(pans)){
            ans = 0;
            for(int i = 0; i < (int)b.size(); i += 1) if((pans >> i) & 1) ans |= 1ULL << b[i];
            //cout << bitset<4>(x) << " " << bitset<4>(ans) << "\n";
        }
    }
    for(int i = m - 1; i >= 0; i -= 1) cout << ((ans >> i) & 1); 
    return 0;
}