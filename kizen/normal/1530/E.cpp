#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector<int> cnt(26);
        for(auto&i:s){
            ++cnt[i - 'a'];
        }
        vector<pair<int, int>> a;
        int f = 1, p = -1;
        for(int i = 0; i < 26; ++i){
            if(cnt[i]){
                a.push_back({i, cnt[i]});
                if(cnt[i] > 1) f = 0;
                else if(p == -1) p = i;
            }
        }
        if(p != -1){
            cout << (char)(p + 'a');
            for(auto&i:a){
                if(i.first == p) --i.second;
                while(i.second--) cout << (char)(i.first + 'a');
            }
        }
        else if(f || (int)a.size() == 1){
            for(auto&i:a){
                while(i.second--) cout << (char)(i.first + 'a');
            }
        }
        else{
            if(a[0].second >= 2 && (int)s.size() - a[0].second >= a[0].second - 2){
                cout << (char)(a[0].first + 'a') << (char)(a[0].first + 'a');
                int pos = 1;
                for(int i = 3; i <= a[0].second; ++i){
                    while(a[pos].second == 0) ++pos;
                    cout << (char)(a[pos].first + 'a');
                    --a[pos].second;
                    cout << (char)(a[0].first + 'a');
                }
                while(true){
                    while(pos < (int)a.size() && a[pos].second == 0) ++pos;
                    if(pos >= (int)a.size()) break;
                    cout << (char)(a[pos].first + 'a');
                    --a[pos].second;
                }
            }
            else{
                cout << (char)(a[0].first + 'a') << (char)(a[1].first + 'a');
                --a[0].second, --a[1].second;
                if(!a[0].second){
                    for(auto&i:a){
                        while(i.second--) cout << (char)(i.first + 'a');
                    }
                }
                else{
                    if((int)a.size() == 2){
                        while(a[1].second--) cout << (char)(a[1].first + 'a');
                        while(a[0].second--) cout << (char)(a[0].first + 'a');
                    }
                    else{
                        while(a[0].second--) cout << (char)(a[0].first + 'a');
                        cout << (char)(a[2].first + 'a'); --a[2].second;
                        while(a[1].second--) cout << (char)(a[1].first + 'a');
                        for(int i = 2; i < (int)a.size(); ++i){
                           while(a[i].second--) cout << (char)(a[i].first + 'a');
                        }
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}