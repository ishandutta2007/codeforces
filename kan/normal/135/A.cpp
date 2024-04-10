#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    if (n==1)
    {
        if (a[n]==1) cout << 2;
        else cout << 1;
        return 0;
    }
    cout << 1 << ' ';
    if (a[n]==1) a[n-1]=2;
    for (int i=1;i<n;i++) cout << a[i] << ' ';
    return 0;
}