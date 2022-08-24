//  Codeforces Beta Round #1
//  Problem B

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

const int L = 26;

char S[110], T[110];

void tr(int x) {
    string str = "";
    for (; x; ) {
        str = (char)('A' + --x % L) + str;
        x /= L;
    }
    printf("%s", str.c_str());
}
int rt() {
    int ret = 0;
    for (char *p = S; isalpha(*p); ++p) {
        ret = ret * L + (*p - 'A') + 1;
    }
    return ret;
}

int main() {
    int a, b;
    
    for (int TC = in(); TC--; ) {
        scanf("%s", S);
        strcpy(T, S);
        for (char *p = T; *p; ++p) {
            if (isalpha(*p)) *p = ' ';
        }
        if (sscanf(T, "%d%d", &a, &b) == 1) {
            printf("R%dC%d\n", a, rt());
        } else {
            tr(b);
            printf("%d\n", a);
        }
    }
    
    return 0;
}