#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100005;

int T;
int n, x;
char str[Maxn];
long my[Maxn];

void Get()
{
    long res = 0;
    for (int i = 0; i < n; i++) {
        long nd = x - my[i];
        if (my[n] == 0) {
            if (nd == 0) {cout << -1; return;}
        } else if (nd % my[n] == 0) {
            nd /= my[n];
            if (nd >= 0) res++;
        }
    }
    cout << res;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> x >> str;
        my[0] = 0;
        for (int i = 0; i < n; i++)
            my[i + 1] = my[i] + (str[i] == '0'? 1: -1);
        Get();
        cout << "\n";
    }
    return 0;
}