#include <algorithm>
    #include <iostream>
    #include <cstring>
    #include <cstdlib>
    #include <string>
    #include <cstdio>
    #include <cmath>
    #include <map>
    #include <set>
    #include <queue>
    #define f first
    #define s second
    #define mp make_pair
    #define ll long long
     
    using namespace std;
    
    int r, s, p;
    double ansr, anss, ansp;
    double dp[105][105][105];
    
    int main(){
        cin >> r >> s >> p;
        dp[r][s][p] = 1.0;
        
        for (int i = r; i >= 0; --i) {
            for (int j = s; j >= 0; --j) {
                for (int k = p; k >= 0; --k) {
                    double pp = i * j + i * k + j * k;
                    if (pp == 0)
                        continue;
                    if (i > 0)
                        dp[i - 1][j][k] += dp[i][j][k] * i * k / pp;
                    if (j > 0)
                        dp[i][j - 1][k] += dp[i][j][k] * i * j / pp;
                    if (k > 0)
                        dp[i][j][k - 1] += dp[i][j][k] * j * k / pp;
                }
            }    
        }
        
        for (int i = 1; i < 105; i++) {
            ansr += dp[i][0][0];
            anss += dp[0][i][0];
            ansp += dp[0][0][i];
        }
        
        printf("%.12lf %.12lf %.12lf\n", ansr, anss, ansp);
        return 0;
    }