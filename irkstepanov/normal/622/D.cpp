#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

const int amax = (int)(1e6 + 10);

int main()
{

    //ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1 1\n");
        return 0;
    }

    vector<int> ans(2 * n);
    ans.back() = n;
    ans[0] = ans[n - 1] = 1;
    int l = 1, r = n - 2;
    for (int x = 3; x < n; x += 2) {
        ans[l] = ans[r] = x;
        ++l, --r;
    }

    if (n % 2 == 1) {
        ans[l] = n;
    }

    ans[n] = ans[n + n - 2] = 2;
    l = n + 1, r = n + n - 3;
    for (int x = 4; x < n; x += 2) {
        ans[l] = ans[r] = x;
        ++l, --r;
    }

    if (n % 2 == 0) {
        ans[l] = n;
    }

    for (int i = 0; i < 2 * n; ++i) {
        printf("%d ", ans[i]);
    }

}