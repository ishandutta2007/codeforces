#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back

vector<int> a, ans;

int main ()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    int i = 0;
    while (i < n && a[i] > 0)
    {
        ans.pb(a[i]);
        i++;
    }


    while (i < n && a[i] == 0)
        i++;
    int fixpos;
    if ((n - i) % 2 == 0)
        fixpos = i;
    else
        fixpos = i + 1;
    for (int j = n - 1; j >= fixpos; j--)
        ans.pb(a[j]);

    if (ans.size() == 0)
        cout << a.front();
    else
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    return 0;
}