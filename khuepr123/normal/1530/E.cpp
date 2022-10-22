/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n; string s;
int x, y, z, k;

int cnt[26];

void flick(){
    for1(i, 0, 25){
        while(cnt[i]--){
            cout << char(i + 'a');
        }
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        memset(cnt, 0, sizeof(cnt));
        cin >> s; n = s.size();
        sort(s.begin(), s.end());
        for(char c : s){
            cnt[c - 'a']++;
        }
        int sm = 0;
        vector<int> ord;
        for1(i, 0, 25){
            if(cnt[i] == 1){
                cout << char(i + 'a');
                cnt[i] = 0;
                flick();
                goto dumb;
            }
            if(cnt[i]){
                sm++;
                ord.pb(i);
            }
        }
        for1(i, 0, 25){
            if(cnt[i]){
                if(cnt[i] == n){
                    cout << s << endl;
                    goto dumb;
                }
                cnt[i] -= 2;
                n -= 2;
                if(cnt[i] <= n - cnt[i]){
                    vector<char> fk;
                    for(char c : s){
                        if(c - 'a' != i) fk.pb(c);
                    }
                    cout << char(i + 'a');
                    cout << char(i + 'a');
                    for(char c : fk){
                        cout << c;
                        if(cnt[i]){
                            cout << char(i + 'a');
                            --cnt[i];
                        }
                    }
                    cout << endl;
                    goto dumb;
                }
                else if(sm == 2){
                    cnt[i] += 2;
                    n += 2;
                    cout << char(i + 'a');
                    cnt[i]--;
                    for2(j, 25, 0){
                        while(cnt[j]--){
                            cout << char(j + 'a');
                        }
                    }
                    cout << endl;
                    goto dumb;
                }
                else{
                    cnt[i] += 2;
                    n += 2;
                    cout << char(i + 'a');
                    cnt[i]--;
                    cout << char(ord[1] + 'a');
                    cnt[ord[1]]--;
                    while(cnt[i]){
                        --cnt[i];
                        cout << char(i + 'a');
                    }
                    cout << char(ord[2] + 'a');
                    cnt[ord[2]]--;
                    flick();
                }
                goto dumb;
            }
        }
        dumb:;
    }
}