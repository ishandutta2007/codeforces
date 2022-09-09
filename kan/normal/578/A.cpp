#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int main()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        printf("-1\n");
        return 0;
    }
    int k = (a - b) / 2 / b;
    cout.precision(20);
    cout << fixed << (double)(a + b) / 2 / (k + 1) << endl;
    return 0;
}