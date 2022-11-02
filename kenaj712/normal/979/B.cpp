#include<bits/stdc++.h>
using namespace std;
int tab[257];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a,b,c;
    int a1=0,b1=0,c1=0,d;

    cin>>d>>a>>b>>c;
    int pom=0;
    for(int x=0;x<a.size();x++)
    {
        tab[int(a[x])]++;
        pom++;
    }

    for(int x=0;x<257;x++)
    {
         a1=max(a1,tab[x]);
         tab[x]=0;
    }
    for(int x=0;x<a.size();x++)
        tab[int(b[x])]++;
    for(int x=0;x<257;x++)
    {
         b1=max(b1,tab[x]);
         tab[x]=0;
    }
    for(int x=0;x<a.size();x++)
        tab[int(c[x])]++;
    for(int x=0;x<257;x++)
    {
         c1=max(c1,tab[x]);
         tab[x]=0;
    }
    if(d!=1||a1!=pom)
        a1=min(pom,a1+d);
    else
        a1=max(1,a1-1);
    if(d!=1||b1!=pom)
    b1=min(pom,b1+d);
    else
        b1=max(1,b1-1);
     if(d!=1||c1!=pom)
    c1=min(pom,c1+d);
    else
        c1=max(1,c1-1);
    // cout<<a1<<" "<<b1<<" "<<c1<<'\n';
    if(a1+b1+c1-max(a1,max(b1,c1))-min(a1,min(b1,c1))==max(a1,max(b1,c1)))
        cout<<"Draw";
    else if(a1>c1&&a1>b1)
        cout<<"Kuro";
    else if(b1>c1)
        cout<<"Shiro";
    else
        cout<<"Katie";



	return 0;
}