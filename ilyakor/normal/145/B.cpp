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

int main()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int g4 = -1, g7 = -1;
    int st = -1;

    if (abs(a3 - a4) > 1) {
        printf("-1\n");
        return 0;
    }

    if (a3 == a4 + 1) {
        g4 = a3, g7 = a3, st = 0;
    } else if (a4 == a3 + 1) {
        g4 = a4, g7 = a4, st = 1;
    } else {
        if (a3 + 1 <= a1)
            g4 = a3 + 1, g7 = a3, st = 0;
        else
            g4 = a3, g7 = a3 + 1, st = 1;
    }

    if (g4 > a1 || g7 > a2) {
        printf("-1\n");
        return 0;
    }

    while (g4 > 0 || g7 > 0) {
        if (st == 0) {
            --g4;
            while (a1 > g4) {
                printf("4");
                --a1;
            }           
        } else {
            if (g7 == 1) {
                for (int i = 0; i < a2; ++i)
                    printf("7");
                a2 = 0;
            } else {
                printf("7");
                --a2;
            }
            --g7;
        }
        st = 1 - st;
    }
    printf("\n");
    return 0;
}