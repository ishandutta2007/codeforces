#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string a;
    cin >> a;
    N = a.length();
    int k;
    cin >> k;
    int pocz = 0;
    int coile = N/k;
    int kon = N/k-1;
    if (N%k)
    {
        printf("NO");
        return 0;
    }
    for (int g = 0;g < k;g++)
    {
        for (int i = pocz,j = kon;i < j;i++,j--)
        {
            if (a[i] != a[j])
            {
                printf("NO");
                return 0;
            }
        }
        pocz = kon+1;
        kon = pocz+coile-1;
    }
    printf("YES");

    return 0;
}