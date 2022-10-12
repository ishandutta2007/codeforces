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
#include <unordered_map>

using namespace std;

typedef long long ll;
#define pb push_back
#define sz size()

ll n, s;

signed main()
{
    cin >> n >> s;
    cout << s / n + (s % n > 0);
}