#include <cstdio>
#include <queue>

using namespace std;

int leader[105];
bool seen[105];
int points[105][2];
int n;

int gl(int i) {
    if (i == leader[i]) return i;
    else return leader[i] = gl(leader[i]);
}

void u(int a, int b) {
    leader[gl(a)] = gl(b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        leader[i] = i;
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (points[i][0] == points[j][0] || points[i][1] == points[j][1]) u(i, j);
        }
    }
    int dg = 0;
    for (int i = 0; i < n; i++) {
        if (!seen[gl(i)]) {
            seen[gl(i)] = true;
            dg++;
        }
    }
    printf("%d\n", dg - 1);
}