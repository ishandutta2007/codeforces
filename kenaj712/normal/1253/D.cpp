#include<bits/stdc++.h>
using namespace std;
int maks[1000005];
int lider[1000005];
int f(int a)
{
    if(lider[a]!=a)
        lider[a]=f(lider[a]);
    return lider[a];
}
void u(int a,int b)
{
    if(f(a)>f(b))
        lider[f(b)]=f(a);
    else
        lider[f(a)]=f(b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        lider[x]=x;
    while(b--)
    {
        cin>>c>>d;
        u(c,d);
    }
    int licz=0;
    for(int x=1;x<a;x++)
    {
        if(f(x)>x&&f(x)!=f(x+1))
        {
            u(x,x+1);
            licz++;
        }
    }
    cout<<licz;
	return 0;
}