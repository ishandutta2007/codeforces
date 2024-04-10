#include <bits/stdc++.h>

using namespace std;

int ile[1000007];
int ile_serio[1000007];
int cp[1000007];
bool jest[1000007];

bool sprawdz(int war, int n) {
    priority_queue<pair<int, int>> Q;
    for (int i = 1; i <= n; i++) {
        if (ile_serio[i] != 0) {
            ile[i] = ile_serio[i];
            Q.push({ile[i], i});
            jest[i] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i - war >= 1 && ile[cp[i - war]] > 0 && !jest[cp[i - war]]) {
            jest[cp[i - war]] = true;
            Q.push({ile[cp[i - war]], cp[i - war]});
        }
        if (Q.empty())
            return false;
        int a = Q.top().second;
        jest[a] = false;
        Q.pop();
        cp[i] = a;
        ile[a]--;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        memset(ile_serio, 0, sizeof(int) * (n + 7));
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            ile_serio[a]++;
        }
        int pocz = 0, kon = n;
        while (pocz != kon - 1) {
            int sr = (pocz + kon) / 2;
            if (sprawdz(sr, n))
                pocz = sr;
            else
                kon = sr;
        }
        printf("%d\n", pocz - 1);
    }
    return 0;
}