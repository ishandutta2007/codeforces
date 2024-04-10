#include <cstring>
#include <iostream>
#include <deque>

using namespace std;

int N, M;
int A[102][10002], B[10002], D[102][10002];

inline int sum(int i, int x, int y)
{
    if (x > y) return 0;
    return A[i][y] - (x == 1 ? 0 : A[i][x - 1]);
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i][0];
        for (int j = 1; j <= A[i][0]; ++j)
        {
            cin >> A[i][j];
            if (j != 1) A[i][j] += A[i][j - 1];
        }
    }
    
    memset(D, -1, sizeof(D));
    
    for (int i = 0; i <= N; ++i)
        D[i][0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        memset(B, 0, sizeof(B));
        for (int j = 1; j <= A[i][0]; ++j)
            for (int k = 0; k <= j; ++k)
                B[j] = max(B[j], sum(i, 1, k) + sum(i, A[i][0] - (j - k) + 1, A[i][0]));
        for (int j = 1; j <= M; ++ j)
            for (int k = 0; k <= j && k <= A[i][0]; ++k)
                if (D[i - 1][j - k] != -1)
                    D[i][j] = max(D[i][j], D[i - 1][j - k] + B[k]);
    }
    cout << D[N][M];
}