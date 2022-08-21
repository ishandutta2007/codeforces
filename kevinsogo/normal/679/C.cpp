#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define N 1111


#define sort_uniq(vec) do {\
    sort((vec).begin(), (vec).end());\
    (vec).erase(unique((vec).begin(), (vec).end()), (vec).end());\
} while (0)

char word[N];
int grid[N][N];
int sgrid[N][N];
bool vis[N][N];
int added[N][N];
int n, k;

vector< pair<int,int> > rects;
int di[5] = {1, 0, -1, 0, 1};
int *dj = di + 1;

void init() {
    rects.clear();
}
void add_rect(int i, int j) {
    //**/ printf("adding %d %d\n", i, j);
    rects.push_back(make_pair(i, j));
}
int madded[N][N];
void traverse(int v) {
    //**/ printf("traversing %d\n", v);
    vector<int> is;
    vector<int> js;
    for (int a = 0; a < rects.size(); a++) {
        int i = rects[a].first;
        int j = rects[a].second;
        is.push_back(i);
        js.push_back(j);
        if (i >= k) is.push_back(i-k);
        if (j >= k) js.push_back(j-k);
    }
    is.push_back(-1);
    js.push_back(-1);
    sort_uniq(is);
    sort_uniq(js);
    map<int,int> iidx;
    map<int,int> jidx;
    for (int a = 0; a < is.size(); a++) iidx[is[a]] = a;
    for (int a = 0; a < js.size(); a++) jidx[js[a]] = a;
    for (int i = 0; i < is.size(); i++) {
        for (int j = 0; j < js.size(); j++) {
            madded[i][j] = 0;
        }
    }
    //**/ for (int a = 0; a < is.size(); a++) printf("%d ", is[a]); puts("");
    //**/ for (int a = 0; a < js.size(); a++) printf("%d ", js[a]); puts("");
    for (int a = 0; a < rects.size(); a++) {
        int i = rects[a].first;
        int j = rects[a].second;
        int I = i-k;
        int J = j-k;
        i = iidx[i];
        j = jidx[j];
        I = iidx[I];
        J = jidx[J];
        madded[i][j]++;
        madded[i][J]--;
        madded[I][j]--;
        madded[I][J]++;
        //**/ printf("adding %d %d %d %d\n", i, j, I, J);
    }
    for (int i = is.size()-1; i >= 0; i--) {
        for (int j = js.size()-1; j >= 0; j--) {
            if (i) madded[i-1][j] += madded[i][j];
            if (j) madded[i][j-1] += madded[i][j];
            if (i && j) madded[i-1][j-1] -= madded[i][j];
        }
    }
    //**/ for (int i = 0; i < is.size(); i++) {
    //**/     for (int j = 0; j < js.size(); j++) {
    //**/         printf("%3d ", madded[i][j]);
    //**/     }
    //**/     puts("");
    //**/ }
    for (int i = 1; i < is.size(); i++) {
        for (int j = 1; j < js.size(); j++) {
            if (madded[i][j]) {
                int i2 = is[i],   j2 = js[j];
                int i1 = is[i-1], j1 = js[j-1];
                added[i2][j2] += v;
                if (j1 >= 0) added[i2][j1] -= v;
                if (i1 >= 0) added[i1][j2] -= v;
                if (i1 >= 0 && j1 >= 0) added[i1][j1] += v;
            }
        }
    }
}


void fill_up(int si, int sj) {
    vector< pair<int,int> > queue;
    queue.push_back(make_pair(si, sj));
    init();
    vis[si][sj] = true;
    for (int f = 0; f < queue.size(); f++) {
        int i = queue[f].first;
        int j = queue[f].second;
        add_rect(i, j);
        //**/ printf("at %d %d\n", i, j);
        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                add_rect(ni, nj);
                if (!grid[ni][nj] && !vis[ni][nj]) {
                    vis[ni][nj] = true;
                    queue.push_back(make_pair(ni, nj));
                }
            }
        }
    }
    traverse(queue.size());
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        for (int j = 0; j < n; j++) {
            grid[i][j] = word[j] == 'X';
            sgrid[i+1][j+1] = grid[i][j] + sgrid[i+1][j] + sgrid[i][j+1] - sgrid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!grid[i][j] && !vis[i][j]) {
                // for(int I= 0; I <=n; I++) {
                //     for (int J=0; J<=n; J++) {
                //         added[I][J] = 0;
                //     }
                // }
                fill_up(i, j);
                // printf("fill %d %d\n", i, j);
                // for(int I= 0; I <=n; I++) {
                //     for (int J=0; J<=n; J++) {
                //         printf("%d ", added[I][J]);
                //     }
                //     puts("");
                // }
                // printf("hoy\n");
            }
        }
    }
    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i) added[i-1][j] += added[i][j];
            if (j) added[i][j-1] += added[i][j];
            if (i && j) added[i-1][j-1] -= added[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n-k; i++) {
        for (int j = 0; j <= n-k; j++) {
            int curr = added[i][j] + sgrid[i+k][j+k] - sgrid[i+k][j] - sgrid[i][j+k] + sgrid[i][j];
            // printf("%d ", added[i][j]);
            ans = max(ans, curr);
        }
        // puts("");
    }
    printf("%d\n", ans);
}