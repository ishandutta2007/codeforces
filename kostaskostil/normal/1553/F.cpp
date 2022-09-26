#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 300500;
int f[nmax][2];
int mas[nmax][2];

void add(int pos, int val, int num)
{
    mas[pos][num]+=val;
    for (int i = pos; i < nmax; i|=(i+1))
        f[i][num] += val;
}

int get(int r, int num)
{
    int ans = 0;
    for (int i = r; i > 0; i&=(i+1), i--)
        ans += f[i][num];
    return ans;
}

int getlr(int l, int r, int num)
{
    return get(min(r, nmax-1), num) - get(l-1, num);
}

int n;
int a[nmax];
int C = 1500;
set<int> cur;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        //a[i] = rand() + 1;
    }

    int ans = 0;
    for (int i=1; i<=n; i++)
    {
        int m = i-1;

        ans += get(a[i], 1);
        ans += (m - get(a[i], 0)) * a[i];

        int g0 = get(1 * a[i] - 1, 0);
        int g1 = get(1 * a[i] - 1, 1);

        for (int k = 1; k * a[i] < nmax; k++)
        { /// c / a[i] = k
            int l = k * a[i];
            int r = (k + 1) * a[i] - 1;

            int gn0 = get(min(nmax-1, r), 0);
            int gn1 = get(min(nmax-1, r), 1);

            ans += (gn1 - g1) - k * a[i] * (gn0 - g0);
            g0 = gn0;
            g1 = gn1;
        }
        int last;
        g0 = -1;
        g1 = -1;
        for (int k = 1; ; k++)
        { /// a[i] / c = k
          /// a[i] / c = [k, k+1)
          /// c = a[i] / [k, k+1)
          /// l = (a[i] + 1 + k + 1 - 1) / (k + 1)
            int l = (a[i] + 1 + k + 1 - 1) / (k + 1);
            int r = a[i] / k;
//            cout<<"B "<<a[i]<<" "<<k<<" "<<l<<" "<<r<<"\n";

            if (k==1)
            {
                g0 = get(r, 0);
                g1 = get(r, 1);
            }
            int gn0 = get(l-1, 0);
            int gn1 = get(l-1, 1);
            ans += (g0 - gn0) * a[i] - k * (g1 - gn1);
//            ans += getlr(l, r, 0) * a[i] - k * getlr(l, r, 1);
            if (r <= C)
            {
                last = l-1;
                break;
            }
            g0 = gn0, g1 = gn1;
        }
//        cout<<last<<"\n";
        for (int j : cur)
//        for (int j=1; j<=last; j++)
        {
            if (j > last)
                break;
//            if (mas[j][1])
                ans+=a[i]%j;
        }

        cur.insert(a[i]);
        add(a[i], 1, 0);
        add(a[i], a[i], 1);

        cout<<ans<<" ";
    }
    cout<<"\n";
}