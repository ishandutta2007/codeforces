#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    map<int, set<string>> srt;
    int gop = 53, mod = 2654435761;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        vector<int> cnt(26);
        for(auto&j:a[i]){
            ++cnt[j - 'a'];
        }
        unsigned long long val = 0;
        for(int j = 0; j < (int)cnt.size(); ++j){
            val *= gop; val %= mod;
            val += cnt[j]; val %= mod;
        }
        srt[val].insert(a[i]);
    }
    a.clear();
    for(auto&i:srt){
        for(auto&j:i.second){
            a.push_back(j);
        }
    }
    int ans = 0;
    vector<int> gr;
    for(int rep = 0; rep < 2; ++rep){
        reverse(a.begin(), a.end());
        vector<vector<int>> ha(n, vector<int>((int)a[0].size() + 1));
        for(int i = 0; i < n; ++i){
            unsigned long long val = 0;
            for(int j = (int)a[0].size() - 1; j >= 0; --j){
                val *= gop; val %= mod;
                val += (a[i][j] - '0'); val %= mod;
                ha[i][j] = val;
            }
        }
        vector<vector<int>> haf(n, vector<int>((int)a[0].size() + 1));
        for(int i = 0; i < n; ++i){
            unsigned long long val = 0;
            for(int j = 0; j < (int)a[0].size(); ++j){
                val *= gop; val %= mod;
                val += (a[i][j] - '0'); val %= mod;
                haf[i][j] = val;
            }
        }
        vector<map<int, int>> mp((int)a[0].size() + 1);
        int last = -1;
        vector<vector<pair<int, int>>> minu(n), plu(n);
        for(int i = 0; i < n;){
            vector<int> cnt(26);
            for(auto&j:a[i]){
                ++cnt[j - 'a'];
            }
            int j = i + 1;
            while(j < n){
                vector<int> cnt2(26);
                for(auto&k:a[j]){
                    ++cnt2[k - 'a'];
                }
                if(cnt != cnt2){
                    break;
                }
                ++j;
            }
            for(int k = i; k < j; ++k){
                int y = (int)a[k].size() - 1;
                for(int x = (int)a[k].size() - 1; x >= 0; --x){
                    if(x < (int)a[k].size() - 1 && a[k][x] > a[k][x + 1]){
                        y = x;
                    }
                    int l = last + 1, r = k, mid;
                    while(l < r){
                        mid = (l + r) >> 1;
                        if(!x || haf[mid][x - 1] == haf[k][x - 1]){
                            r = mid;
                        }
                        else{
                            l = mid + 1;
                        }
                    }
                    if(haf[l][x] != haf[k][x]){
                        if(l > last + 1) minu[l - 1].push_back({y + 1, ha[k][y + 1]});
                        for(int bit = 20; bit >= 0; --bit){
                            if(l + (1 << bit) <= k && haf[l + (1 << bit)][x] != haf[k][x]){
                                l += (1 << bit);
                            }
                        }
                        plu[l].push_back({y + 1, ha[k][y + 1]});
                    }
                }
                for(int x = 0; x <= (int)a[k].size(); ++x){
                    ++mp[x][ha[k][x]];
                }
            }
            if(rep) gr.push_back(j - i);
            i = j; last = j - 1;
            for(int r = 0; r <= (int)a[0].size(); ++r) mp[r].clear();
        }
        for(int i = 0; i < n; ){
            vector<int> cnt(26);
            for(auto&j:a[i]){
                ++cnt[j - 'a'];
            }
            int j = i + 1;
            while(j < n){
                vector<int> cnt2(26);
                for(auto&k:a[j]){
                    ++cnt2[k - 'a'];
                }
                if(cnt != cnt2){
                    break;
                }
                ++j;
            }
            for(int k = i; k < j; ++k){
                for(int x = 0; x <= (int)a[k].size(); ++x){
                    ++mp[x][ha[k][x]];
                }
                for(auto&r:minu[k]){
                    ans -= mp[r.first][r.second];
                }
                for(auto&r:plu[k]){
                    ans += mp[r.first][r.second];
                }
            }
            i = j;
            for(int r = 0; r <= (int)a[0].size(); ++r) mp[r].clear();
        }
    }
    int ans3 = 0;
    for(auto&i:gr){
        ans3 += i * (i - 1) / 2;
    }
    ans += (ans3 - ans) * 2;
    int ans2 = 0;
    for(auto&i:gr){
        ans2 += 1337 * i * (n - i);
    }
    ans += ans2 / 2;
    cout << ans << '\n';
    return 0;
}