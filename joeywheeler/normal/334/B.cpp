#include <cstdio>
#include <algorithm>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int x[8], y[8];
int nx[8], ny[8];

int main() {
    FO(i,0,8) scanf("%d %d", x+i, y+i);
    FO(i,0,8) nx[i] = x[i], ny[i] = y[i];

    sort(x,x+8);
    sort(y,y+8);

    FO(i,0,7) if (x[i] == x[i+1]) x[i]=1<<30;
    FO(i,0,7) if (y[i] == y[i+1]) y[i]=1<<30;

    sort(x,x+8);
    sort(y,y+8);

    if (x[0] == (1<<30) || x[1] == (1<<30) || x[2] == (1<<30) || x[3] != (1<<30)) printf("ugly\n"); 
    else if (y[0] == (1<<30) || y[1] == (1<<30) || y[2] == (1<<30) || y[3] != (1<<30)) printf("ugly\n"); 
    else {
        bool seen[4][4] = {};
        FO(i,0,8) {
            int xi = 3, yi = 3;
            FO(j,0,3) if (nx[i] == x[j]) xi = j;
            FO(j,0,3) if (ny[i] == y[j]) yi = j;
            seen[xi][yi] = true;
        }
        FO(i,0,3) FO(j,0,3) {
            if (seen[i][j] != (i != 1 || j != 1)) {
                printf("ugly\n");
                return 0;
            }
        }
        printf("respectable");
    }

    return 0;
}