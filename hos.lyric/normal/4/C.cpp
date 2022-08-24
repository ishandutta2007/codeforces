//  Codeforces Beta Round #4
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

map<string,int> nums;
char buf[110];

int main() {
    string str;
    
    for (int nu = atoi(gets(buf)); nu--; ) {
        str = gets(buf);
        if (nums.count(str)) {
            printf("%s%d\n", buf, ++nums[str]);
        } else {
            nums[str] = 0;
            puts("OK");
        }
    }
    
    return 0;
}