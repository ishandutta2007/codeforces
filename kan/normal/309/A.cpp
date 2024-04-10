#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1000005;

int n, l, t;
int a[maxn * 3];

int main()
{
    scanf("%d%d%d", &n, &l, &t);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) a[i + n] = a[i] + l;
    for (int i = 0; i < n; i++) a[i + 2 * n] = a[i] + 2 * l;
    int klaps = (2 * t) / l;
    int dist = (2 * t) % l;
    int left;
    for (int i = n - 1; i >= 0; i--) if (a[n] - a[i] > dist)
    {
	left = i + 1;
	break;
    }
    int right;
    for (int i = n; i < 3 * n; i++) if (a[i] - a[n] > dist)
    {
	right = i - 1;
	break;
    }
    double answer = (double)(klaps * (double)n * (n - 1)) / 2;
    for (int i = n; i < 2 * n; i++)
    {
	while (a[i] - a[left] > dist) left++;
	while (a[right + 1] - a[i] <= dist) right++;
	answer += (double)(i - left + right - i) / 4;
    }
    cout.precision(20);
    cout << answer / 2 << endl;
    return 0;
}