#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>

using namespace std;

int n, k;
int p1[500000], p2[500000];
int cnt[500000];
int c2;
int la[500000];
vector<char> s;

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int r = 0;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> p1[i];
    for (int i = 0; i < n; i++) cin >> p2[i];
    for (int i = 0; i < n; i++)
    {
        cnt[p1[i]]++;
        cnt[p2[i]]++;
        if (cnt[p1[i]] == 2) c2++;
        if (cnt[p2[i]] == 2) c2++;
        if (p1[i] == p2[i]) c2--;
        if (c2 == i + 1)
        {
            la[i] = 1;
            r++;
        }
    }
    if (r < k)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    char c = 'a';
    for (int i = 0; i < n; i++)
    {
        s[p1[i] - 1] = c, s[p2[i] - 1] = c;
        if (c != 'z' && la[i] == 1)
            c++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
}