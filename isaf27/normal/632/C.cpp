#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 50001;

string s[MAX_N];
int n;

bool cmpnew(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> n;
    getline(cin, s[0]);
    for (int i = 0; i < n; i++)
        getline(cin, s[i]);
    sort(s, s + n, cmpnew);
    for (int i = 0; i < n; i++)
        cout << s[i];
    return 0;
}