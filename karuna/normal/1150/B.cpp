#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
pii cur;
bool field[51][51];
const pii dx[5] = {pii(0, 0), pii(1, 0), pii(0, 1), pii(-1, 0), pii(0, -1)};
pii fnd() {
    for (int i=cur.va; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (field[i][j] == false) {
                cur = pii(i, j);
                return pii(i+1, j);
            }
        }
    }
    return pii(-1, -1);
}
void print() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }
    return;
}
int main() {
    scanf("%d", &n);

    char c;
    for (int i=0; i<n; i++) {
        getchar();
        for (int j=0; j<n; j++) {
            scanf("%c", &c);
            if (c == '#') field[i][j] = true;
            else field[i][j] = false;
        }
    }

    cur = pii(0, 0);

    pii tmp;
    int a, b;
    bool flag = true;

    while (1) {
        tmp = fnd();
        if (tmp.va==-1) break;
        for (int i=0; i<5; i++) {
            a = tmp.va+dx[i].va;
            b = tmp.vb+dx[i].vb;
            if (a<0 || b<0 || a>=n || b>=n || field[a][b] == true) {
                flag = false;
                break;
            }
            else {
                field[a][b] = true;
            }
        }
        if (!flag) break;
      //  print();
    }

    if (flag) printf("YES");
    else printf("NO");
}