#include<bits/stdc++.h>
using namespace std;
int lider[1000005];
int licz[1000005];
int f(int a)
{
    if(lider[a]!=a)
        lider[a]=f(lider[a]);
    return lider[a];
}
void u(int a,int b)
{
    lider[f(a)]=f(b);
}
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	int a,b,c,d;
	cin>>a>>b;
	for(int x=1;x<=a;x++)
        lider[x]=x;
	while(b--)
    {
        cin>>c;
        while(c--)
        {
            cin>>d;
            v.push_back(d);
        }
        for(auto x:v)
            u(v[0],x);
        v.resize(0);
    }
    for(int x=1;x<=a;x++)
        licz[f(x)]++;
    for(int x=1;x<=a;x++)
        cout<<licz[f(x)]<<" ";

	return 0;
}