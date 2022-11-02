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

const int maxn = 1000;

char buf[maxn];

int main()
{
    gets(buf);
    int n = strlen(buf);
    vector<string> v;
    string cur;
    for (int i = 0; i < n; ++i) {
        if (buf[i] == ' ') {
            if (sz(cur) && cur != " ")
                v.pb(cur);
            cur = " ";
            continue;
        }
        if (buf[i] == ',') {
            if (sz(cur))
                v.pb(cur);
            cur = "";
            v.pb(",");
            continue;
        }
        if (sz(cur) && isdigit(cur[0]) && !isdigit(buf[i])) {
            v.pb(cur);
            cur = "";
        }
        if (sz(cur) && cur == " ") {
            v.pb(cur);
            cur = "";
        }
        cur += buf[i];
        if (cur == "...") {
            v.pb(cur);
            cur = "";
        }
    }
    if (sz(cur))
        v.pb(cur);
    for (int i = 0; i < sz(v); ++i) {
        int next = i + 1;
        while (next < sz(v) && v[next] == " ") ++next;
        if (v[i] == ",") {
            printf(",");
            if (next < sz(v))
                printf(" ");
            continue;
        }
        if (v[i] == "...") {
            int prev = i - 1;
            while (prev >= 0 && v[prev] == " ") --prev;
            if (prev >= 0 && v[prev] != ",")
                printf(" ");
            printf("...");
            continue;
        }
        if (isdigit(v[i][0])) {
            cout << v[i];
            if (next < sz(v) && isdigit(v[next][0]))
                printf(" ");
            continue;
        }
    }
    printf("\n");
    return 0;
}