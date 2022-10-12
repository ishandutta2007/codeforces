#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back

ll n;

int main()
{
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "Mahmoud";
    }
    else
    {
        cout << "Ehab";
    }
}