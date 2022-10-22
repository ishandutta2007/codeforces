#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s[1005];
int x[1005];

map <string, int> score;
map <string, int> fscore;

int mx = -1000000000;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> s[i] >> x[i];
        score[s[i]] += x[i];
    }
    for(auto c : score){mx = max(mx, c.second);}
    for(int i=1; i<=n; i++){
        fscore[s[i]] += x[i];
        if(score[s[i]] == mx && fscore[s[i]] >= mx){
            cout << s[i];
            return 0;
        }
    }
    return 0;
}