#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

//typedef long long ll;
//#define int ll

int n, m;
int p[300500];
int q[300500];
int used[300500];

bool check(int dk)
{
    for (int i=1; i<=n; i++)
        q[(i - dk + 2*n - 1)%n + 1] = i;

//    cout<<dk<<": ";
//    for (int j=1; j<=n; j++)
//        cout<<q[j]<<" ";
//    cout<<"\n";

    for (int i=1; i<=n; i++)
        used[i] = 0;
    int ans = 0;
    for (int i=1; i<=n; i++)
        if (!used[i])
    {
        int l = 0;
        int j = i;
        while (true)
        {
//            cout<<i<<" "<<j<<endl;
            used[j] = true;
            j = q[p[j]];
            l++;
            if (j==i)
                break;
        }
        ans += l-1;
//        cout<<l<<"\n";
    }
    return (ans<=m);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    int ___;
    cin>>___;
    for (int _ = 1; _ <= ___; _++)
    {
        cin>>n>>m;
        set<int> ans;
        for (int i=1; i<=n; i++)
            cin>>p[i];
        for (int i=1; i<=75; i++)
        {
            int j = (rand() * RAND_MAX + rand())%n + 1;

            if (check(j - p[j] + n) % n)
                ans.insert((j - p[j] + n)%n);
        }
        cout<<ans.size();
        for (int i : ans)
            cout<<" "<<i;
        cout<<"\n";
    }
}