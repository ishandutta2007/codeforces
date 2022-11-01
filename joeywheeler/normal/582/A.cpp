#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int v[505*505];
vector<int> r;

multiset<int> s;

int main() {
    scanf("%d", &n);
    FO(i,0,n*n) {
        scanf("%d", &v[i]);
    }
    sort(v,v+n*n);
    reverse(v,v+n*n);
    FO(i,0,n*n) {
        int x = v[i];
        if (s.find(x) != s.end()) {
            s.erase(s.find(x));
        } else {
            for (int y : r) {
                s.insert(__gcd(x,y));
                s.insert(__gcd(x,y));
            }
            r.push_back(x);
        }
    }
    FO(i,0,n) printf("%d%c", r[i], " \n"[i+1==n]);
}