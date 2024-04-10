#include<bits/stdc++.h>
#include<cstring>
#include <vector>

using namespace std;

vector <long long> v[200010];
long long n,i,d[200010],drum[200010],r[200010],p[200010],a[200010],c[200010];

long long cb(long long u, long long pp, long long x)
{
    long long m;
    long long st,dr;
    st=u;dr=pp;
    while (st<dr)
    {
        m=(st+dr)/2;
        if (d[x]-d[drum[m]]>a[x])
            st=m+1;
        else
            dr=m;
    }
    return st;
}

void dfs(long long x, long long poz)
{
    long long ans;
    drum[poz]=x;
    d[x]=d[p[x]]+c[x];
    ans=cb(1,poz,x);

    //cout << "d " << x << ' ' << drum[ans] << " asf - " << d[x] << '\n';
    r[p[x]]++;
    r[p[drum[ans]]]--;
    for (long long i=0; i<v[x].size(); i++)
        dfs(v[x][i],poz+1),r[x]+=r[v[x][i]];
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[i];
    for (i=2; i<=n; i++)
        cin >> p[i] >> c[i],v[p[i]].push_back(i);
    dfs(1,1);
    for (i=1; i<=n; i++)
        cout << r[i] << ' ';
}