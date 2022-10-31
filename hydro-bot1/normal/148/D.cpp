// Hydro submission #63202f2432ae6c3198c9c5ca@1663053605364
#include <bits/stdc++.h>
using namespace std;
// A  i  j  
double f[1005][1005];
int w, b;
// a / b
double p(int a, int b)
{
    return 1.0 * a / b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> w >> b;
    for (int i = 1; i <= w; i++)
        f[i][0] = 1;
    for (int i = 0; i <= b; i++)
        f[0][i] = 0;
    for (int i = 1; i <= w; i++)
        for (int j = 1; j <= b; j++)
        {
            //
            f[i][j] = p(i, i + j);
            //B
            if (j >= 2)
                f[i][j] += p(j, i + j) *
                           p(j - 1, i + j - 1) *
                           p(i, i + j - 2) *
                           f[i - 1][j - 2];
            //B
            if (j >= 3)
                f[i][j] += p(j, i + j) *
                           p(j - 1, i + j - 1) *
                           p(j - 2, i + j - 2) *
                           f[i][j - 3];
        }
    cout << fixed << setprecision(10) << f[w][b] << "\n";
    return 0;
}

/*

WB
ABA
AB
 B 
A
 */