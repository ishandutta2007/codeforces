#include <bits/stdc++.h>

using namespace std;

typedef long double ftype;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    const int maxx = 128;
    ftype A[maxx][maxx];
    memset(A, 0, sizeof(A));
    ftype p[x + 1];
    for(int i = 0; i <= x; i++)
        cin >> p[i];
    for(int i = 0; i < maxx; i++)
        for(int j = 0; j < maxx; j++)
            A[i][j] = (((i ^ j) <= x) ? p[i ^ j] : 0);
    ftype B[maxx][maxx];
    memset(B, 0, sizeof(B));
    for(int i = 0; i < maxx; i++)
        B[i][i] = 1;
    ftype C[maxx][maxx];
    for(int i = 0; i < 31; i++)
    {
        if((n >> i) & 1)
        {
            memset(C, 0, sizeof(C));
            for(int i = 0; i < maxx; i++)
                for(int j = 0; j < maxx; j++)
                    for(int k = 0; k < maxx; k++)
                        C[i][j] += A[i][k] * B[k][j];
            memcpy(B, C, sizeof(C));
        }
        memset(C, 0, sizeof(C));
        for(int i = 0; i < maxx; i++)
            for(int j = 0; j < maxx; j++)
                for(int k = 0; k < maxx; k++)
                    C[i][j] += A[i][k] * A[k][j];
        memcpy(A, C, sizeof(C));
    }
    cout << fixed << setprecision(9) << 1. - B[0][0] << "\n";
	return 0;
}