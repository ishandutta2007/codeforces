#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1 << 21;
int a[maxn], mp[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int h, g;
        cin >> h >> g;
        for(int i = 1; i < (1 << h); i += 1){
            cin >> a[i];
            b[i] = a[i];
        }
        for(int i = (1 << h); i < (1 << (h + 1)); i += 1) a[i] = 0;
        vector<int> ans;
        for(int i = 1; i < (1 << h); i += 1) mp[a[i]] = i;
        sort(b + 1, b + (1 << h), greater<int>());
        int d = 0;
        for(int _ = 0; _ < (1 << h) - (1 << g); _ += 1){
            while(true){
                int x = b[d += 1];
                int i = mp[x];
                int p = i;
                vector<int> v;
                v.push_back(i);
                while(a[p * 2] or a[p * 2 + 1]) v.push_back(p = p * 2 + (a[p * 2 + 1] > a[p * 2]));
                if(p >= (1 << g)){
                    ans.push_back(i);
                    for(int j = 0; j + 1 < (int)v.size(); j += 1){
                        a[v[j]] = a[v[j + 1]];
                        mp[a[v[j]]] = v[j];
                    }
                    a[p] = 0;
                    break;
                }
            }
        }
        LL sum = 0;
        for(int i = 1; i < (1 << g); i += 1) sum += a[i];
        cout << sum << "\n";
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}