#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int a[200005];

int t[200005], r[200005];

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,n) scanf("%d", a+i);
    FO(i,0,m) scanf("%d %d", t+i, r+i);
    multiset<int> o;
    multiset<int> v;
    FO(i,0,m) o.insert(r[i]);
    int X = *o.rbegin();
    FO(i,0,X) v.insert(a[i]);
    FO(i,0,m) {
        int x = r[i];
        o.erase(o.find(x));
        int y = o.empty() ? 0 : *o.rbegin();
        if (t[i] == 1) {
            for (int j = x-1; j >= y; j--) {
                a[j] = *v.rbegin();
                v.erase(v.find(a[j]));
            }
        } else {
            for (int j = x-1; j >= y; j--) {
                a[j] = *v.begin();
                v.erase(v.find(a[j]));
            }
        }
    }
    FO(i,0,n) printf("%d%c", a[i], " \n"[i+1==n]);
}