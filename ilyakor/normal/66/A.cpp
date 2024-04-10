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

bool is_byte(string s)
{
    stringstream ss(s);
    ostringstream os;
    int x;
    ss >> x;
    if (x < -128 || x > 127) return false;
    os << x;
    return s == os.str();
}

bool is_short(string s)
{
    stringstream ss(s);
    ostringstream os;
    short x;
    ss >> x;
    os << x;
    return s == os.str();
}

bool is_int(string s)
{
    stringstream ss(s);
    ostringstream os;
    int x;
    ss >> x;
    os << x;
    return s == os.str();
}

bool is_long(string s)
{
    stringstream ss(s);
    ostringstream os;
    long long x;
    ss >> x;
    os << x;
    return s == os.str();
}

int main()
{
    string s;
    cin >> s;
    if (sz(s) > 25) {
        printf("BigInteger\n");
        return 0;
    }
    if (is_byte(s)) {
        printf("byte\n");
        return 0;
    }
    if (is_short(s)) {
        printf("short\n");
        return 0;
    }
    if (is_int(s)) {
        printf("int\n");
        return 0;
    }
    if (is_long(s)) {
        printf("long\n");
        return 0;
    }
    printf("BigInteger\n");
    return 0;
}