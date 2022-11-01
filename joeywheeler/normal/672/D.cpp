#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
int n; ll k;
ll c[500005];

int main() {
    scanf("%d%lld", &n, &k);
    FO(i,0,n) scanf("%lld", c+i);
    sort(c,c+n);
    reverse(c,c+n);
    // sub k from start
    ll cs = 0;
    FO(i,1,n+1) {
        cs += c[i-1];
        if (i == n || (cs - k) / i >= c[i]) {
            if (i == n) {
                if (cs % i == 0) {
                    printf("0\n");
                } else {
                    printf("1\n");
                }
                return 0;
            }
            // we done
            ll fs = cs-k;
            FO(j,0,fs%i) c[j] = fs / i + 1;
            FO(j,fs%i,i) c[j] = fs / i;
            break;
        }
    }
    //FO(i,0,n) printf("%lld ", c[i]);
    //printf("\n");
    // add k to end
    cs = 0;
    FO(i,1,n+1) {
        cs += c[n-i];
        //printf("cs=%lld\n", (cs+k+i-1)/i);
        if (i == n || (cs + k + i-1) / i <= c[n-i-1]) {
            if (i == n) {
                cs += k;
                if (cs % i == 0) {
                    printf("0\n");
                } else {
                    printf("1\n");
                }
                return 0;
            }
            //printf("i=%d\n", i);
            // we done
            ll fs = cs+k;
            FO(j,0,fs%i) c[n-1-j] = fs / i + 1;
            FO(j,fs%i,i) c[n-1-j] = fs / i;
            break;
        }
    }
    //FO(i,0,n) printf("%lld ", c[i]);
    //printf("\n");
    sort(c,c+n);
    printf("%lld\n", c[n-1]-c[0]);
}