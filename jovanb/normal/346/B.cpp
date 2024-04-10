#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 100;

ll hsh1[MAXN+5];
ll hsh2[MAXN+5];
int dp[MAXN+5][MAXN+5][MAXN+5];
tuple <int, int, int> odakle[MAXN+5][MAXN+5][MAXN+5];

int pom[MAXN+5][26];

const ll P = 101;
const int MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string s1, s2, virus;
    cin >> s1 >> s2 >> virus;
    int n = s1.size();
    int m = s2.size();
    int v = virus.size();
    ll tp = 1;
    for(int i=1; i<=v; i++){
        hsh1[i] = (hsh1[i-1] + (tp*(virus[i-1] - 'A' + 1)))%MOD;
        tp = (tp*P)%MOD;
    }
    string pok = "";
    for(int i=0; i<v; i++){
        for(int j=0; j<26; j++){
            string x = pok;
            x += ('A' + j);
            for(int k=1; k<=i+1; k++){
                hsh2[k] = (hsh2[k-1]*P + ((x[i+1-k]) - 'A' + 1))%MOD;
            }
            for(int len=i+1; len>=1; len--){
                if(hsh2[len] == hsh1[len]){
                    pom[i][j] = len;
                    break;
                }
            }
        }
        pok += virus[i];
    }
    for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) for(int k=0; k<=v; k++) odakle[i][j][k] = make_tuple(-1, -1, -1);
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=0; k<v; k++){
                if(dp[i+1][j][k] < dp[i][j][k]){
                    dp[i+1][j][k] = dp[i][j][k];
                    odakle[i+1][j][k] = make_tuple(i, j, k);
                }
                if(dp[i][j+1][k] < dp[i][j][k]){
                    dp[i][j+1][k] = dp[i][j][k];
                    odakle[i][j+1][k] = make_tuple(i, j, k);
                }
                if(i < n && j < m && s1[i] == s2[j]){
                    if(dp[i+1][j+1][pom[k][s1[i] - 'A']] < dp[i][j][k] + 1){
                        dp[i+1][j+1][pom[k][s1[i] - 'A']] = dp[i][j][k] + 1;
                        odakle[i+1][j+1][pom[k][s1[i] - 'A']] = make_tuple(i, j, k);
                    }
                }
            }
        }
    }
    int mx = 0;
    for(int i=0; i<v; i++){
        mx = max(mx, dp[n][m][i]);
    }
    if(mx == 0){
        cout << mx << "\n";
        return 0;
    }
    int tr = 0;
    for(int i=0; i<v; i++){
        if(dp[n][m][i] == mx) tr = i;
    }
    tuple <int, int, int> tren = make_tuple(n, m, tr);
    stack <char> st;
    while(get<0>(tren) > 0 && get<1>(tren) > 0){
        tuple <int, int, int> kuda = odakle[get<0>(tren)][get<1>(tren)][get<2>(tren)];
        if(get<0>(kuda)+1 == get<0>(tren) && get<1>(kuda)+1 == get<1>(tren)) st.push(s1[get<0>(kuda)]);
        tren = kuda;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << "\n";
    return 0;
}