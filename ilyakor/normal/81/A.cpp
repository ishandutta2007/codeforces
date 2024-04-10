#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

char buf[1000 * 1000];

int main()
{
    scanf("%s", buf);
    vector<char> v;
    for (int i = 0; buf[i]; ++i) {
        char c = buf[i];
        if (sz(v) && v[sz(v) - 1] == c) {
            v.pop_back();
        } else
            v.pb(c);
    }
    for (int i = 0; i < sz(v); ++i)
        printf("%c", v[i]);
    printf("\n");
    return 0;
}