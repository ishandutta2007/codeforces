#include <cstdio>
#include <algorithm>
using namespace std;

bool msg[100][100];
int cnt[100];
bool chose[100];

int main() {
    int m;
    scanf("%d\n", &m);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++)
            msg[i][j] = getchar() == '1';
        getchar();
    }
    for(int i = 0; i < m; i++)
        scanf("%d", cnt + i);
    int ncho = 0;
    for(int *p; (p = find(cnt, cnt + m, 0)) != cnt + m;) {
        int i = p - cnt;
        chose[i] = true;
        ncho++;
        for(int j = 0; j < m; j++)
            if(msg[i][j])
                cnt[j]--;
    }
    printf("%d\n", ncho);
    for(int i = 0; i < m; i++)
        if(chose[i])
            printf("%d ", i + 1);
}