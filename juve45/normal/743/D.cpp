#include<bits/stdc++.h>
#include<cstring>
#include <vector>
#define inf 100000000000000000LL

using namespace std;
vector <int> v[200100];
long long n,i,rez,complet[200100],use[200100],a[200100],ans[200100];
void dfs(long long x)
{
    use[x]=1;
    long long sum=0,maxim1,maxim2;
    ans[x]=-inf;
    for (int i=0; i<v[x].size(); i++)
        if (!use[v[x][i]])
        {
            dfs(v[x][i]);
            if (ans[v[x][i]]>ans[x]||i==0)
                ans[x]=ans[v[x][i]];
            sum+=complet[v[x][i]];
        }
    complet[x]=sum+a[x];
    ans[x]=max(ans[x],complet[x]);
    maxim1=-inf;
    maxim2=-inf;
    for (i=0; i<v[x].size(); i++)
        if (!use[v[x][i]])
        if (ans[v[x][i]]>maxim1)
            if (ans[v[x][i]]<=maxim2)
                maxim1=ans[v[x][i]];
            else
                maxim1=maxim2,maxim2=ans[v[x][i]];
    if (maxim1+maxim2>rez&&maxim1!=-inf)
        rez=maxim1+maxim2;
    use[x]=0;
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[i];
    for (i=2; i<=n; i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    rez=-inf*2;
    dfs(1);
    if (rez!=-inf*2)
    cout << rez << '\n';
    else
    cout << "Impossible\n";
}