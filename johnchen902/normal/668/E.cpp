#include <cstdio>
#include <bitset>
using namespace std;
namespace {
using Bool_2d = bitset<2000>[2000];
Bool_2d tc1, tc2;
int nodeof(int x, int n) {
    return x > 0 ? x - 1 : n - x - 1;
}
int read_int() {
    bool flag;
    int x;
    char c = getchar();
    if(c == '-') flag = true, x = 0;
    else flag = false, x = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
        x = x * 10 + c - '0';
    return flag ? -x : x;
}
void build_tc(Bool_2d &tc, int n) {
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            if(tc[i][k])
                tc[i] |= tc[k];
}
bool solvable(const Bool_2d &tc, int n) {
    for(int i = 0; i < n; i++)
        if(tc[i][i + n] && tc[i + n][i])
            return false;
    return true;
}
bool visited[2000];
void visit_point(const Bool_2d &tc, int x, int n) {
    visited[x] = true;
    for(int i = 0; i < 2 * n; i++)
        if(tc[x][i])
            visited[i] = true;
}
void solve(const Bool_2d &tc, int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i] && !visited[i + n])
            visit_point(tc, tc[i + n][i] ? i : i + n, n);
        putchar(visited[i] ? '1' : '0');
        putchar(' ');
    }
    putchar('\n');
}

}
int main() {
    int n, m1, m2;
    scanf("%d %d %d\n", &n, &m1, &m2);
    for(int i = 0; i < 2 * n; i++)
        tc1[i][i] = tc2[i][i] = true;
    for(int i = 0; i < m1; i++) {
        int sat1a = read_int();
        int sat1b = read_int();
        tc1[nodeof(-sat1a, n)][nodeof(sat1b, n)] = true;
        tc1[nodeof(-sat1b, n)][nodeof(sat1a, n)] = true;
    }
    for(int i = 0; i < m2; i++) {
        int sat2a = read_int();
        int sat2b = read_int();
        tc2[nodeof(-sat2a, n)][nodeof(sat2b, n)] = true;
        tc2[nodeof(-sat2b, n)][nodeof(sat2a, n)] = true;
    }
    build_tc(tc1, 2 * n);
    build_tc(tc2, 2 * n);
    bool solv1 = solvable(tc1, n);
    bool solv2 = solvable(tc2, n);
    if(solv1 && solv2) {
        for(int i = 0; i < n; i++)
            if(tc1[i + n][i] != tc2[i + n][i]) {
                auto &tc = tc1[i + n][i] ? tc2 : tc1;
                visit_point(tc, i + n, n);
                solve(tc, n);
                return 0;
            }
        for(int i = 0; i < n; i++)
            if(tc1[i][i + n] != tc2[i][i + n]) {
                auto &tc = tc1[i][i + n] ? tc2 : tc1;
                visit_point(tc, i, n);
                solve(tc, n);
                return 0;
            }
        for(int i = 0; i < 2 * n; i++)
            for(int j = 0; j < 2 * n; j++)
                if(tc1[i][j] != tc2[i][j]) {
                    auto &tc = tc1[i][j] ? tc2 : tc1;
                    visit_point(tc, i, n);
                    visit_point(tc, j < n ? j + n : j - n, n);
                    solve(tc, n);
                    return 0;
                }
        puts("SIMILAR");
    } else if(solv1) {
        solve(tc1, n);
    } else if(solv2) {
        solve(tc2, n);
    } else {
        puts("SIMILAR");
    }
}