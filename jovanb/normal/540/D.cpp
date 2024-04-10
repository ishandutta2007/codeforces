#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld dp[105][105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int a1, b1, c1;
    cin >> a1 >> b1 >> c1;
    dp[a1][b1][c1] = 1;
    for(int a=a1; a>=0; a--){
        for(int b=b1; b>=0; b--){
            for(int c=c1; c>=0; c--){
                if(a == 0 && b == 0 && c == 0) continue;
                if(a > 0 && c > 0){
                    dp[a-1][b][c] += dp[a][b][c]*c*a / (c*a+a*b+b*c);
                }
                if(b > 0 && a > 0){
                    dp[a][b-1][c] += dp[a][b][c]*a*b / (c*a+a*b+b*c);
                }
                if(c > 0 && b > 0){
                    dp[a][b][c-1] += dp[a][b][c]*b*c / (c*a+a*b+b*c);
                }
            }
        }
    }
    ld s1=0;
    for(int i=1; i<=a1; i++){
        s1 += dp[i][0][0];
    }
    cout << s1 << " ";
    s1 = 0;
    for(int i=1; i<=b1; i++){
        s1 += dp[0][i][0];
    }
    cout << s1 << " ";
    s1 = 0;
    for(int i=1; i<=c1; i++){
        s1 += dp[0][0][i];
    }
    cout << s1;
    return 0;
}