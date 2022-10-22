#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;
int n;

int cnt[26];

void print(int g){
    char x = g + 'a';
    cout << x;
}

void solve(){
    cin >> s;
    n = s.size();
    for(int i=0; i<26; i++) cnt[i] = 0;
    for(auto c : s) cnt[c - 'a']++;
    int ima = 0;
    for(int i=0; i<26; i++){
        if(cnt[i]) ima++;
    }
    if(ima == 1){
        cout << s << "\n";
        return;
    }
    vector <int> vec;
    for(int i=0; i<26; i++) if(cnt[i]) vec.push_back(i);
    if(ima >= 3){
        for(int i=0; i<26; i++){
            if(cnt[i] == 1){
                print(i);
                cnt[i]--;
                for(auto x : vec){
                    while(cnt[x] > 0){
                        cnt[x]--;
                        print(x);
                    }
                }
                cout << "\n";
                return;
            }
        }
        /// Res = 1
        int p = vec[0];
        int d = vec[1];
        int t = vec[2];
        /// Moze li aa
        if(n - cnt[p] >= cnt[p]-2){
            print(p);
            print(p);
            cnt[p] -= 2;
            vector <int> sled;
            for(auto x : vec){
                if(x == p) continue;
                while(cnt[x] > 0){
                    sled.push_back(x);
                    cnt[x]--;
                }
            }
            for(auto c : sled){
                print(c);
                if(cnt[p] > 0){
                    print(p);
                    cnt[p]--;
                }
            }
            cout << "\n";
            return;
        }
        /// Ne moze
        print(p);
        cnt[p]--;
        print(d);
        cnt[d]--;
        while(cnt[p] > 0){
            print(p);
            cnt[p]--;
        }
        print(t);
        cnt[t]--;
        for(auto x : vec){
            while(cnt[x] > 0){
                cnt[x]--;
                print(x);
            }
        }
        cout << "\n";
        return;
    }
    int a = vec[0];
    int b = vec[1];
    if(cnt[a] == 1){
        print(a);
        while(cnt[b] > 0){
            print(b);
            cnt[b]--;
        }
        cout << "\n";
        return;
    }
    if(cnt[b] == 1){
        print(b);
        while(cnt[a] > 0){
            print(a);
            cnt[a]--;
        }
        cout << "\n";
        return;
    }
    /// Moze li aa?
    if(cnt[b] >= cnt[a]-2){
        print(a);
        print(a);
        cnt[a] -= 2;
        while(cnt[a] > 0){
            print(b);
            cnt[b]--;
            print(a);
            cnt[a]--;
        }
        while(cnt[b] > 0){
            print(b);
            cnt[b]--;
        }
        cout << "\n";
        return;
    }
    print(a);
    cnt[a]--;
    while(cnt[b] > 0){
        print(b);
        cnt[b]--;
    }
    while(cnt[a] > 0){
        print(a);
        cnt[a]--;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}