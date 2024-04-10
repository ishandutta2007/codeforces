#include <bits/stdc++.h>
#define DMAX 100005
using namespace std;

multiset <int> ms[7];
int sol[7];
int n, m, k;
int a[7][DMAX], maxk;
int ii, jj;

void solve()
{
    int i=1;
    int j=1;
    ii=i;
    jj=j;
    while(i<=n)
    {
        int kk=0;
        for(int w=1; w<=m; w++)
        {
            ms[w].insert(a[w][i]);
            kk += *ms[w].rbegin();
        }

        while(kk>k && j<=i)
        {
            kk=0;
            for(int w=1; w<=m; w++)
            {
                ms[w].erase(a[w][j]);
                kk+=*ms[w].end();
            }
            j++;
        }
        if(maxk<i-j+1)
        {
            for(int w=1; w<=m; w++)
                sol[w]=*ms[w].rbegin();
            maxk=i-j+1;
            ii=i;jj=j;
        }

        i++;
    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[j][i];

    solve();
    for(int i=1;i<=m;++i)
        cout<<sol[i]<<" \n"[i==m];

    return 0;
}