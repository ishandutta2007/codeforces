#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[202020], b[202020];
vector<pii> frac;

ll gcd(ll a, ll b) {
    if (a<0) a = -a;
    if (b<0) b = -b;
    if (a*b==0) return a+b;
    if (a<b) return gcd(b, a);
    return gcd(b, a%b);
}
int main() {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int i=0; i<n; i++)
        scanf("%d", &b[i]);

    int g;
    int cnt = 0;
    int dsa = 0;
    int asd = 0;
    for (int i=0; i<n; i++) {
        if (a[i]!=0 && b[i]!=0) {
            if (b[i]<0) {
                a[i] = -a[i];
                b[i] = -b[i];
            }

            g = gcd(a[i], b[i]);
            frac.push_back(make_pair(a[i]/g, b[i]/g));
        }
        else if (a[i]==0 && b[i]==0) {
            dsa++;
            cnt++;
            asd++;
        }
        else if (b[i]==0) {
            asd++;
        }
    }

    sort(frac.begin(), frac.end());

    pii cur = make_pair(-1, -1);
    int cont = 0;
    int sz = frac.size();
    for (int i=0; i<sz; i++) {
        if (cur != frac[i]) {
            cont = 1;
            cur = frac[i];
        }
        else if (cur == frac[i]) {
            cont++;
        }
        cnt = max(cnt, dsa+cont);
    }

    printf("%d", max(cnt, asd));

}