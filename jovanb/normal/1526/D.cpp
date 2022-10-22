#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll par[5][5];
int ima[5];
int perm[5];

char koji[] = {'A', 'N', 'T', 'O'};

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    ima[0] = ima[1] = ima[2] = ima[3] = 0;
    for(int i=0; i<=3; i++){
        for(int j=0; j<=3; j++){
            par[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        if(s[i] == 'A'){
            ima[0]++;
            par[1][0] += ima[1];
            par[2][0] += ima[2];
            par[3][0] += ima[3];
        }
        if(s[i] == 'N'){
            ima[1]++;
            par[0][1] += ima[0];
            par[2][1] += ima[2];
            par[3][1] += ima[3];
        }
        if(s[i] == 'T'){
            ima[2]++;
            par[0][2] += ima[0];
            par[1][2] += ima[1];
            par[3][2] += ima[3];
        }
        if(s[i] == 'O'){
            ima[3]++;
            par[0][3] += ima[0];
            par[1][3] += ima[1];
            par[2][3] += ima[2];
        }
    }
    ll res = 0;
    string sol = "";
    for(int i=0; i<=3; i++) perm[i] = i;
    do{
        ll tr = 0;
        for(int i=0; i<=3; i++){
            for(int j=0; j<i; j++){
                tr += par[perm[i]][perm[j]];
            }
        }
        res = max(res, tr);
    } while(next_permutation(perm, perm+4));
    for(int i=0; i<=3; i++) perm[i] = i;
    string rs = "";
    do{
        ll tr = 0;
        for(int i=0; i<=3; i++){
            for(int j=0; j<i; j++){
                tr += par[perm[i]][perm[j]];
            }
        }
        if(res == tr){
            for(int i=0; i<=3; i++){
                while(ima[perm[i]]){
                    ima[perm[i]]--;
                    rs += koji[perm[i]];
                }
            }
            cout << rs << "\n";
            return;
        }
    } while(next_permutation(perm, perm+4));
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