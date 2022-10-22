#include <bits/stdc++.h>
/*#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")*/

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return ((ll)a * b)%MOD;
}

int br[11][70][70];
int dp[70][70][70];

int koji(char c){
    if('a' <= c && c <= 'z') return c-'a';
    if('A' <= c && c <= 'Z') return 26 + (c-'A');
    return 52 + (c-'0');
}

int perm(int a, int b, int c, int d){
    if(a == b && b == c && c == d) return 1;
    if(a == b && b == c) return 4;
    if(b == c && c == d) return 4;
    if(a == b && c == d) return 6;
    if(a == b) return 12;
    if(b == c) return 12;
    if(c == d) return 12;
    return 24;
}

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int n;
    cin >> n;
    set <string> q;
    while(n--){
        string s;
        cin >> s;
        q.insert(s);
        reverse(s.begin(), s.end());
        q.insert(s);
    }
    for(auto s : q){
        br[s.size()][koji(s[0])][koji(s[s.size()-1])]++;
    }
    int res = 0;
    for(int sz=3; sz<=10; sz++){
        for(int i=0; i<62; i++){
            for(int j=i; j<62; j++){
                for(int k=j; k<62; k++){
                    dp[i][j][k] = 0;
                    for(int l=0; l<62; l++){
                        dp[i][j][k] = add(dp[i][j][k], mul(br[sz][i][l], mul(br[sz][j][l], br[sz][k][l])));
                    }
                }
            }
        }
        for(int i=0; i<62; i++){
            for(int j=i; j<62; j++){
                for(int k=j; k<62; k++){
                    for(int l=k; l<62; l++){
                        res = add(res, mul(perm(i, j, k, l), mul(dp[i][j][k], mul(dp[i][j][l], mul(dp[i][k][l], dp[j][k][l])))));
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}