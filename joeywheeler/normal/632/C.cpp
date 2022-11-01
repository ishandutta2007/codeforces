#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

bool cmp(string s, string t) {
    return s+t < t+s;
}

string a[50005];
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) cin >> a[i];
    sort(a,a+n,cmp);
    for (string x : a) cout << x;
    printf("\n");
}