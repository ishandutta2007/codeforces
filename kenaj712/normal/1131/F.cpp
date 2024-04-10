#include<bits/stdc++.h>
using namespace std;
int lider[300005];
int kier[300005][2];
int jump[300005];
int rev[300005];
int f(int a)
{
    if(lider[a]!=a)
        lider[a]=f(lider[a]);
    return lider[a];
}
void u(int a,int b)
{
    jump[kier[f(a)][1]]=kier[f(b)][0];
    rev[kier[f(b)][0]]=kier[f(a)][1];
    kier[f(b)][0]=kier[f(a)][0];
    lider[f(a)]=f(b);
}
void pre(int a)
{
    for(int x=1;x<=a;x++)
    {
        lider[x]=x;
        kier[x][0]=x;
        kier[x][1]=x;
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d;
    cin>>a;
    pre(a);
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        u(c,d);
    }
    int pom;
    for(int x=1;x<=a;x++)
        if(jump[x]==0)
            pom=x;
    for(int x=0;x<a;x++)
    {
        cout<<pom<<" ";
        pom=rev[pom];
    }
	return 0;
}