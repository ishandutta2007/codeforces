#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define pb push_back

using namespace std;

typedef long long ll;
typedef vector <vector <ll> > matrix;
ll mod = 1000000007;

matrix operator * (const matrix &a, const matrix &b)
{
    int s1 = a.size(), s2 = b[0].size(), s3 = b.size();
    matrix ans(s1, vector <ll> (s2));
    for (int i = 0; i < s1; i++)
        for (int j = 0; j < s2; j++)
        for (int g = 0; g < s3; g++)
    {
        ans[i][j] += a[i][g] * b[g][j];
        if (ans[i][j] >= mod) ans[i][j] %= mod;
    }
    return ans;
}

matrix pw (const matrix &a, ll n)
{
    if (n == 0)
    {
        int s = a.size();
        matrix m(s, vector <ll> (s));
        for (int i = 0; i < s; i++)
            m[i][i] = 1;
        return m;
    }
    if (n == 1) return a;
    if (n % 2) return a * pw(a, n - 1);
    matrix t = pw(a, n / 2);
    return t * t;
}

int main()
{

    ll n;
    cin >> n;

    matrix a(2, vector <ll> (2));
    a[0][0] = 3;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 3;

    a = pw(a, n);
    cout << a[0][0];

}