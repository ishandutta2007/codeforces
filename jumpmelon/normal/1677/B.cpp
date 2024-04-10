#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
int Col[MAXN + 5], AnsR[MAXN + 5];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n, m, ansc = 0;
        scanf("%d%d", &n, &m);
        memset(Col, 0, sizeof(int[m]));
        memset(AnsR, 0, sizeof(int[m]));
        int curr = 0;
        queue<int> QR;
        for (int i = 0; i < m; i++)
            QR.push(0);
        for (int i = 0; i < n * m; i++) {
            char x;
            scanf(" %c", &x);
            if (x == '1') {
                if (!Col[i % m]++)
                    ansc++;
                curr++;
            }
            QR.push(x - '0');
            if (QR.front() == 1)
                curr--;
            QR.pop();
            if (curr)
                AnsR[i % m]++;
            printf("%d%c", ansc + AnsR[i % m], i + 1 < n * m ? ' ' : '\n');
        }
    }
    return 0;
}