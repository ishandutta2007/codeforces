//  Codeforces Beta Round #3
//  Problem C

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

char ans[][110] = { "first", "second", "illegal", "the first player won", "the second player won", "draw" };
char koma[] = "X0";

char S[20][20];
char A[20], a[20];

#define ac(x,y,z) (a[x] == c && a[y] == c && a[z] == c)
bool win(int k) {
    char c = koma[k];
    return (ac(0, 1, 2) || ac(3, 4, 5) || ac(6, 7, 8) || ac(0, 3, 6) || ac(1, 4, 7) || ac(2, 5, 8) || ac(0, 4, 8) || ac(2, 4, 6));
}

int dfs(int n) {
//cout<<"dfs "<<n<<" "<<a<<endl;
    if (!strcmp(A, a)) {
        if (win(0)) return 3;
        if (win(1)) return 4;
        if (n == 9) return 5;
        return n % 2;
    }
    if (win(0)) return ~0;
    if (win(1)) return ~0;
    if (n == 9) return ~0;
    for (int i = 0; i < 9; ++i) if (a[i] == '.') {
        a[i] = koma[n % 2];
        int tmp = dfs(n + 1);
        if (~tmp) return tmp;
        a[i] = '.';
    }
    return ~0;
}

int main() {
    
    
    scanf("%s%s%s", S[0], S[1], S[2]);
    for (int i = 0; i < 9; ++i) {
        A[i] = S[i / 3][i % 3];
    }
    memset(a, '.', 9);
    
    int res = dfs(0);
    if (!~res) res = 2;
    puts(ans[res]);
    
    return 0;
}