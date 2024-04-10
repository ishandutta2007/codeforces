#include <cstdio>
using namespace std;

int noti[300000]; // noti list (app)
int notj[300000]; // noti list (n-th of app)
int tapp[300000]; // total noti by app
int uapp[300000]; // unread by app

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int ans = 0; // unread
    int m = 0;   // total noti
    int lastt = 0; // last op 3
    while(q--) {
        int op, x;
        scanf("%d %d", &op, &x);
        switch(op) {
        case 1:
            x--;
            ans++;
            noti[m] = x;
            notj[m] = tapp[x];
            m++;
            uapp[x]++;
            tapp[x]++;
            break;
        case 2:
            x--;
            ans -= uapp[x];
            uapp[x] = 0;
            break;
        case 3:
            if(lastt < x) {
                for(int i = lastt; i < x; i++) {
                    int y = noti[i];
                    if(notj[i] >= tapp[y] - uapp[y]) {
                        ans--;
                        uapp[y]--;
                    }
                }
                lastt = x;
            }
            break;
        }
        printf("%d\n", ans);
    }
}