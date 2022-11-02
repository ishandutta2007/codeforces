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

char names[100][100] = {"S", "M", "L", "XL", "XXL"};

int main()
{
    int left[5];
    for (int i = 0; i < 5; ++i)
        cin >> left[i];
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        string s;
        cin >> s;
        int ind = -1;
        for (int j = 0; j < 5; ++j)
            if (s == names[j])
                ind = j;
        int opt = 1000, oind = -1;
        for (int j = 4; j >= 0; --j)
            if (left[j] && opt > abs(j - ind))
                opt = abs(j - ind), oind = j;
        left[oind]--;
        cout << string(names[oind]) << "\n";
    }
    return 0;
}