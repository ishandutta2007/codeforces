#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

const int oo = 1000000000;

int n;
int in[1005];

int sin[1005];
map < int, int > M;

vector < int > conn[1005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", in + i), sin[i] = in[i];
    sort(sin, sin + n);
    for (int i = 0; i < n; ++i) M[sin[i]] = i;
    bool sol = true;
    for (int i = 1; i < n; ++i){
        int a = min(M[in[i - 1]], M[in[i]]), b = max(M[in[i - 1]], M[in[i]]);
        for (int j = a + 1; j <= b - 1; ++j){
            for (int k = 0; k < conn[j].size(); ++k){
                if (conn[j][k] < a || conn[j][k] > b){
                   sol = false;
                   break;
                }
            }
        }
        if (!sol) break;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }
    if (!sol) printf("yes\n");
    else printf("no\n");
    return 0;
}