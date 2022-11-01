#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[50005];

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);

    int s = 0, e = 1e9+5;
    int b = 1e9+5;
    while (s <= e) {
        int m = (s+e)/2;

        priority_queue<int> q;
        FO(i,0,n) q.push(a[i]);
        while (sz(q)) {
            int f = q.top();
            if (f == 0) break;

            int nm = 0;
            while (sz(q) && q.top() == f) {
                q.pop(); nm++;
            }

            int npsh = f > m ? nm : nm-1;
            f /= 2;
            FO(t,0,npsh) q.push(f);
        }

        if (sz(q)) {
            s = m+1;
        } else {
            b = m;
            e = m-1;
        }
    }

    int m = b;
    priority_queue<int> q;
    FO(i,0,n) q.push(a[i]);
    while (sz(q)) {
        int f = q.top();
        if (f == 0) break;

        int nm = 0;
        while (sz(q) && q.top() == f) {
            q.pop(); nm++;
        }

        if (f <= m) printf("%d ", f);

        int npsh = f > m ? nm : nm-1;
        f /= 2;
        FO(t,0,npsh) q.push(f);
    }
    printf("\n");
}