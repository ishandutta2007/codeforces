#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
vector<pair<int,int>> v2;
int f(char a)
{
    return int(a)-97;
}
void simul()
{
    for(int x=1;x<v.size()-1;x++)
        v[x].first-=2;
    v[0].first--;
    v[v.size()-1].first--;
    for(auto x:v)
        if(x.first>0)
            v2.push_back(x);
    v=v2;
    v2.resize(0);
    int last=-1;
    for(auto x:v)
    {
        if(x.second!=last)
        {
            v2.push_back(x);
            last=x.second;
        }
        else
            v2[v2.size()-1].first+=x.first;
    }
    v=v2;
    v2.resize(0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    int start=0;
    for(int x=1;x<a.size();x++)
    {
        if(a[x]!=a[x-1])
        {
            v.push_back(make_pair(x-start,f(a[x-1])));
            start=x;
        }
    }
    v.push_back(make_pair(a.size()-start,f(a.back())));
    int licz=0;
    while(v.size()>1)
    {
        simul();
        licz++;
    }
    cout<<licz;

    return 0;
}