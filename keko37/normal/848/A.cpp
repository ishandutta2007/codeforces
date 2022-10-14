#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n;

void rjesi (llint x, int pos) {
    if (x==0) return;
    llint i;
    for (i=1; i*(i+1)/2<=x; i++);
    for (int j=0; j<i; j++) cout << ((char) ('a'+pos));
    rjesi(x-i*(i-1)/2, pos+1);
}

int main () {
    cin >> n;
    if (n==0) {
        cout << "a";
        return 0;
    }
    rjesi(n, 0);
    return 0;
}