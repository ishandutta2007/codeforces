//CF24D
#include<bits/stdc++.h>
using namespace std;
long double guass[1001][1002] , qw[1002][1002];
int main(){
    int N , M , i , j;
    scanf("%d%d%d%d" , &N , &M , &i , &j);
    if(i == N)
        cout << fixed << setprecision(10) << 0.0000;
    else    if(M == 1)
        cout << fixed << setprecision(10) << 2.0 * (N - i);
    else{
        for(int k = N - 1 ; k >= i ; k--){
            guass[1][2] = guass[M][M - 1] = 1.0/3;
            guass[M][M] = guass[1][1] = -2.0/3;
            guass[M][M + 1] = -1 - qw[k + 1][M] / 3;
            guass[1][M + 1] = -1 - qw[k + 1][1] / 3;            
            for(int m = 2 ; m < M ; m++){
                guass[m][m - 1] = guass[m][m + 1] = 0.25;
                guass[m][m] = -0.75;
                guass[m][M + 1] = -1 - qw[k + 1][m] / 4;    
            }
            for(int m = 1 ; m < M ; m++){
                double times = guass[m + 1][m] / guass[m][m];
                guass[m + 1][m] -= guass[m][m] * times;
                guass[m + 1][m + 1] -= guass[m][m + 1] * times;
                guass[m + 1][M + 1] -= guass[m][M + 1] * times;
            }
            for(int i = M ; i ; i--)
                qw[k][i] = (guass[i][M + 1] - qw[k][i + 1] * guass[i][i + 1]) / guass[i][i];
        }
        cout << fixed << setprecision(10) << qw[i][j];
    }
    return 0;
}