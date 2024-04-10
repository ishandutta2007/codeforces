// program 316-G

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

struct Suffix {
    int Num, x;
};

int Get() {
    char c;
    while (c = getchar(), (c < '0' || c > '9') && (c != '-'))
        ;
    bool Flag = (c == '-');
    if (Flag) c = getchar();
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - 48;
        c = getchar();
    }
    return Flag ? -x : x;
}

void Output(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    int Len = 0, Data[10];
    while (x) {
        Data[Len++] = x % 10;
        x /= 10;
    }
    if (!Len) Data[Len++] = 0;
    while (Len--) putchar(Data[Len] + 48);
    putchar('\n');
}

const int Base = 19961021;
const int inf = 1000000000;

const int C = 11;
const int D = 17;
const int N = 100000;
const int M = 50000;
const int X = N + 5;
const int Y = M + 5;

int n;

string S[C];

long long Hash[C][Y];
long long Pow[Y];

Suffix SA[C][N];

int Height[C][N], Pos[C][M], Sum[C][X];
int ST[C][D][N], Log[X];

long long GetHash(int P, int x, int Len) {
    return Hash[P][x + Len] - Hash[P][x] * Pow[Len];
}

int LCP(Suffix A, Suffix B) {
    int Left = 0, Right = min(S[A.Num].size() - A.x, S[B.Num].size() - B.x);
    while (Left < Right) {
        int Mid = (Left + Right + 1) / 2;
        if (GetHash(A.Num, A.x, Mid) == GetHash(B.Num, B.x, Mid)) {
            Left = Mid;
        } else {
            Right = Mid - 1;
        }
    }
    return Left;
}

bool operator<(Suffix A, Suffix B) {
    int Len = LCP(A, B);
    if (B.x + Len == S[B.Num].size()) return false;
    if (A.x + Len == S[A.Num].size()) return true;
    return S[A.Num][A.x + Len] < S[B.Num][B.x + Len];
}

int GetMin(int T, int L, int R) {
    int P = Log[R - L + 1];
    return min(ST[T][P][L], ST[T][P][R - (1 << P) + 1]);
}

int Solve(int T, int L, int R) {
    if (L > R) return inf;
    if (R == S[0].size()) return -inf;
    int Len = R - L + 1, x = Pos[T][L];
    int Left = 0, Right = x;
    while (Left < Right) {
        int Mid = (Left + Right) / 2;
        if (GetMin(T, Mid + 1, x) >= Len) {
            Right = Mid;
        } else {
            Left = Mid + 1;
        }
    }
    int LB = Left;
    Left = x;
    Right = S[0].size() + S[T].size() - 1;
    while (Left < Right) {
        int Mid = (Left + Right + 1) / 2;
        if (GetMin(T, x + 1, Mid) >= Len) {
            Left = Mid;
        } else {
            Right = Mid - 1;
        }
    }
    int UB = Left;
    return Sum[T][UB + 1] - Sum[T][LB];
}

int main() {
    cin >> S[0];
    n = Get();
    static int LB[C], UB[C];
    for (int i = 1; i <= n; ++i) cin >> S[i] >> LB[i] >> UB[i];
    for (int i = 0; i <= n; ++i) {
        Hash[i][0] = 0;
        for (int j = 0; j < S[i].size(); ++j) {
            Hash[i][j + 1] = Hash[i][j] * Base + S[i][j];
        }
    }
    Pow[0] = 1;
    for (int i = 0; i < M; ++i) Pow[i + 1] = Pow[i] * Base;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < S[0].size(); ++j) SA[i][j] = (Suffix){0, j};
        for (int j = 0; j < S[i].size(); ++j) {
            SA[i][S[0].size() + j] = (Suffix){i, j};
        }
        int m = S[0].size() + S[i].size();
        sort(SA[i], SA[i] + m);
        for (int j = 0; j < m; ++j) {
            if (!SA[i][j].Num) Pos[i][SA[i][j].x] = j;
        }
        for (int j = 1; j < m; ++j) Height[i][j] = LCP(SA[i][j], SA[i][j - 1]);
        Sum[i][0] = 0;
        for (int j = 0; j < m; ++j) {
            Sum[i][j + 1] = Sum[i][j];
            if (SA[i][j].Num) ++Sum[i][j + 1];
        }
        for (int j = 0; j < m; ++j) ST[i][0][j] = Height[i][j];
        for (int j = 1; j < D; ++j) {
            for (int k = 0; k <= m - (1 << j); ++k) {
                ST[i][j][k] =
                    min(ST[i][j - 1][k], ST[i][j - 1][k + (1 << (j - 1))]);
            }
        }
    }
    for (int i = 1, j = 0; i <= N; ++i) {
        if ((1 << (j + 1)) <= i) ++j;
        Log[i] = j;
    }
    static int L[M], R[M];
    int Len0 = S[0].size();
    for (int i = 0, P = -1, Q = -1; i < Len0; ++i) {
        while (P < Len0) {
            bool Flag = true;
            for (int j = 1; j <= n; ++j) {
                if (Solve(j, i, P) > UB[j]) Flag = false;
            }
            if (Flag) break;
            ++P;
        }
        while (Q + 1 < Len0) {
            bool Flag = true;
            for (int j = 1; j <= n; ++j) {
                if (Solve(j, i, Q + 1) < LB[j]) Flag = false;
            }
            if (!Flag) break;
            ++Q;
        }
        L[i] = P;
        R[i] = Q;
    }
    static Suffix Data[M];
    for (int i = 0; i < Len0; ++i) Data[i] = (Suffix){0, i};
    sort(Data, Data + Len0);
    long long Ans = 0;
    for (int i = 0; i < Len0; ++i) {
        int Min = L[Data[i].x], Max = R[Data[i].x];
        Min = max(Min, Data[i].x);
        Max = min(Max, Len0 - 1);
        if (i) Min = max(Min, Data[i].x + LCP(Data[i], Data[i - 1]));
        Ans += max(Max - Min + 1, 0);
    }
    cout << Ans << endl;
    return 0;
}