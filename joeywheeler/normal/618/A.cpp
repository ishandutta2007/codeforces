#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
vector<int> v;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x = 1;
        while (sz(v) && v.back() == x) {
            v.pop_back();
            x++;
        }
        v.push_back(x);
    }
    FO(i,0,sz(v)) printf("%d%c", v[i], " \n"[i+1==sz(v)]);
}