#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int a[N], n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = n - 1;
    int kl = 0, kr = 0;

    while (l <= r)
    {
        if (l < r)
        {
            if (a[l] < a[r])
            {
                a[r] -= a[l];
                ++kl, ++l;
                if (l == r) {++kr; break;}
            }
            else if (a[l] == a[r])
            {
                ++l, --r;
                ++kl, ++kr;
            }
            else
            {
                a[l] -= a[r];
                ++kr, --r;
                if (l == r) {++kl; break;}
            }
        }
        else
        {
            ++l, ++kl;
        }
    }

    cout << kl << " " << kr << "\n";

}