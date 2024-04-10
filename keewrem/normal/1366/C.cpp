#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T;
int N, M;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        int tab[N][M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> tab[i][j];
        int r = 0;
        for (int i = 0; i < ((N + M - 1)>>1); i++) {
            int s = 0;
            for (int k = min(N - 1, i); k >= 0 && i-k<M; k--) {
                s += tab[k][i - k];
                s += tab[N - 1 - k][M - 1 - i + k];
            }
        //    cout << "s "<<s<< "\n";
            r += min(s, 2*min({i,N-1,M-1,M+N-2-i}) + 2 - s);
        //    cout << "r "<<r<<"\n";
        }
        cout << r << "\n";
    }
    return 0;
}