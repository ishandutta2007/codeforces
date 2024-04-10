#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a);i<(b);i++)
#define sz(v) int(v.size())

using namespace std;

int n, a, b;
int r[1000005];

void ac(int i, int j) {
    fo(k,i+1,j) {
        swap(r[i], r[k]);
    }
}

int main() {
    scanf("%d %d %d", &n, &a, &b);
    fo(i,0,n) r[i] = i+1;
    fo(i,0,1000006) {
        if (a * i > n) break;
        if ((n - a*i) % b == 0) {
            int j = (n - (a*i)) / b;
            fo(t,0,i) {
                ac(t*a, (t+1)*a);
            }
            fo(t,0,j) {
                ac(n-(t+1)*b, n-t*b);
            }
            fo(t,0,n) printf("%d%c", r[t], " \n"[t+1==n]);
            return 0;
        }
    }
    printf("-1\n");
}