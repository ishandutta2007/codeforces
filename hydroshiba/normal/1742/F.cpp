#define x firsts
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

lol s[2][26];

void init(){
    for(int i = 0; i < 26; ++i){
        s[0][i] = 0;
        s[1][i] = 0;
    }

    s[0][0] = 1;
    s[1][0] = 1;
}

void solve(){
    init();

    int q;
    cin >> q;

    while(q--){
        int t;
        lol num;
        string ss;

        cin >> t >> num >> ss;
        --t;

        for(char c : ss) s[t][int(c - 'a')] += num;

        int firsts, lastt;

        for(int i = 25; i > -1; --i) if(s[1][i]){
            lastt = i;
            break;
        }

        for(int j = 0; j < 26; ++j) if(s[0][j]){
            firsts = j;
            break;
        }

        if(firsts > lastt){
            cout << "NO\n";
            continue;
        }

        if(firsts < lastt){
            cout << "YES\n";
            continue;
        }

        if(firsts == lastt){
            lol nums = s[0][firsts], numt = s[1][lastt];

            if(nums < numt){
                bool seconds = 0;
                for(int i = firsts + 1; i < 26; ++i) seconds = seconds || bool(s[0][i]);

                if(seconds){
                    cout << "NO\n";
                    continue;
                }
                else{
                    cout << "YES\n";
                    continue;
                }
            }

            if(nums > numt){
                cout << "NO\n";
                continue;
            }

            if(nums == numt){
                bool seconds = 0;
                for(int i = firsts + 1; i < 26; ++i) seconds = seconds || bool(s[0][i]);

                bool secondt = 0;
                for(int i = lastt - 1; i > -1; --i) secondt = secondt || bool(s[1][i]);

                if(seconds){
                    cout << "NO\n";
                    continue;
                }

                if(secondt){
                    cout << "YES\n";
                    continue;
                }
                else{
                    cout << "NO\n";
                    continue;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}