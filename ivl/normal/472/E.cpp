#include <cstdio>
#include <vector>
#define x first
#define y second
#include <algorithm>

using namespace std;

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

void imp(){
     printf("-1\n");
     exit(0);
}

int cnt[905];

int n, m;
int s[35][35];
int r[35][35];

vector < pair < int, int > > sol;
int x, y, cx, cy;
bool sim = false;
void set_start(int a, int b){
     x = a; y = b;
     if (sim) sol.push_back(make_pair(b, a));
     else sol.push_back(make_pair(a, b));
}
void mv(int dx, int dy){
     int nx = x + dx, ny = y + dy;
     swap(s[x][y], s[nx][ny]);
     if (sim) sol.push_back(make_pair(ny, nx));
     else sol.push_back(make_pair(nx, ny));
     x = nx;
     y = ny;
}
bool mat[35][35];
bool good(int x, int y){
     if (x == cx && y == cy) return false;
     if (x < 1 || x > n || y < 1 || y > m) return false;
     if (mat[x][y]) return false;
     return true;
}
int abs(int a){return (a < 0) ? -a : a;}
int mhd(int x1, int y1, int x2, int y2){
    return max(abs(x1 - x2), abs(y1 - y2));
}
void moveto(int a, int b){
     while (x != a || y != b){
           int dr = 0, ct = 1;
           for (int i = 0; i < 8; ++i){
               int nx = x + dx[i], ny = y + dy[i];
               if (!good(nx, ny)) continue;
               int nc = mhd(a, b, nx, ny) - mhd(x, y, a, b);
               if (nc < ct){ct = nc; dr = i;}
           }
           mv(dx[dr], dy[dr]);
     }
}
void simetr(){
     swap(x, y);
     swap(n, m);
     for (int i = 0; i <= 30; ++i) for (int j = 0; j <= 30; ++j) if (i < j){
         swap(s[i][j], s[j][i]);
         swap(r[i][j], r[j][i]);
         swap(mat[i][j], mat[j][i]);
     }
     sim = !sim;
}
pair < int, int > find(int val){
     for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (!mat[i][j] && (i != x || j != y)) if (s[i][j] == val) return make_pair(i, j);
}
void finish(){
     printf("%d\n", sol.size() - 1);
     printf("%d %d\n", sol[0].x, sol[0].y);
     for (int i = 1; i < sol.size(); ++i) printf("%d %d\n", sol[i].x, sol[i].y);
     exit(0);
}

void solve1(){ // n = 1
     int t1, t2;
     for (int i = 1; i <= m; ++i) if (s[1][i] != r[1][i]){t1 = i; break;}
     for (int i = m; i >= 1; --i) if (s[1][i] != r[1][i]){t2 = i; break;}
     bool c1 = true, c2 = true;
     for (int i = t1; i < t2; ++i) c1 &= (s[1][i] == r[1][i + 1]);
     c1 &= (r[1][t1] == s[1][t2]);
     for (int i = t2; i > t1; --i) c2 &= (s[1][i] == r[1][i - 1]);
     c2 &= (r[1][t2] == s[1][t1]);
     if (c1){
        set_start(1, t2);
        for (int i = 0; i < t2 - t1; ++i) mv(0, -1);
        finish();
     }
     if (c2){
        set_start(1, t1);
        for (int i = 0; i < t2 - t1; ++i) mv(0, 1);
        finish();
     }
     imp();
}

void trim_row(){ // n -> n-1
     
     for (int i = m; i >= 1; --i){
         pair < int, int > pt = find(r[n][i]);
         cx = pt.x;
         cy = pt.y;
         while (cy > i){
               moveto(cx, cy - 1);
               mv(0, 1);
               --cy;
         }
         while (cy < i){
               moveto(cx, cy + 1);
               mv(0, -1);
               ++cy;
         }
         while (cx != n){
               moveto(cx + 1, cy);
               mv(-1, 0);
               ++cx;
         }
         moveto(1, 1);
         mat[n][i] = true;
     }
     --n;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j){
        scanf("%d", s[i] + j);
        ++cnt[s[i][j]];
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j){
        scanf("%d", r[i] + j);
        if (--cnt[r[i][j]] == -1) imp();
    }
    if (n == 1) solve1();
    if (m == 1){simetr(); solve1();}
    pair < int, int > pt = find(r[1][1]);
    set_start(pt.x, pt.y);
    moveto(1, 1);
    while (n > 2) trim_row();
    simetr();
    while (n > 2) trim_row();
    simetr();
    moveto(1, 1);
    pt = find(r[1][2]);
    if (pt.x != 1 || pt.y != 2){moveto(1, 2); moveto(pt.x, pt.y); moveto(1, 1);}
    pt = find(r[2][2]);
    if (pt.x != 2 || pt.y != 2){moveto(2, 2); moveto(pt.x, pt.y); moveto(1, 1);}
    pt = find(r[2][1]);
    if (pt.x != 2 || pt.y != 1){moveto(2, 1); moveto(pt.x, pt.y); moveto(1, 1);}
    finish();
    
    return 0;
}