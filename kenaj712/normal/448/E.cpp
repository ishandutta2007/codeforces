#include<bits/stdc++.h>
using namespace std;
vector<long long> pol[10005];
vector<long long> v;
long long a,b;
int licz=0;
void rek(int c,int d)
{
    if(licz==1e5)
        return;
    if(c==0)
    {
        cout<<1<<" ";
        licz++;
        return;
    }
    if(d==b)
    {
        cout<<v[c]<<" ";
        licz++;
        return;
    }
    for(auto x:pol[c])
        rek(x,d+1);
}
long long duzo=1e5;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>a>>b;
    b=min(b,duzo);
    for(long long x=1;x*x<=a;x++)
    {
        if(a%x==0)
        {
            v.push_back(x);
        if(x*x!=a)
            v.push_back(a/x);
        }
    }
    sort(v.begin(),v.end());
    for(int x=0;x<v.size();x++)
        for(int y=0;y<=x;y++)
            if(v[x]%v[y]==0)
                pol[x].push_back(y);
    rek(v.size()-1,0);
	return 0;
}