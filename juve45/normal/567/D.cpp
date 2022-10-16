#include <bits/stdc++.h>

using namespace std;
int n, m, k, a, K;
vector <pair<int, int> > v;

bool check(int k)
{
    int ok=0;
    vector <int> h;
    h.push_back(0);
    for(int i=0;i<m;i++)
        if(v[i].second<=k)
        h.push_back(v[i].first);
    h.push_back(n+1);
    for(int i=0;i<=k;i++)
    {
        int hh=h[i+1]-h[i];
        //hh++;
        //hh++;
        hh/=a+1;
        ok+=hh;

    }if(ok>=K)
            return true;
        return false;

}

int bs(int st, int dr)
{

if(st==dr)
    return st;

else{

int m=(st+dr)/2;
if(check(m)==true)
{
    return bs(m+1, dr);
}
else return bs(st, m);
}

}



int main()
{
    cin>>n>>k>>a;
K=k;int f;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>f;
        v.push_back({f, i});
    }
    sort(v.begin(), v.end());

    if(check(m)==true)
    {
        cout<<"-1\n";
        return 0;
    }

    cout<<bs(1, m);

    return 0;
}