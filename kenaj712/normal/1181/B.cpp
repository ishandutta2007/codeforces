#include<bits/stdc++.h>
using namespace std;
int f(char a)
{
    return int(a)-48;
}
char inv(int a)
{
    return char(a+48);
}
string sum(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string c="";
    while(a.size()<b.size())
        a.push_back('0');
    while(b.size()<a.size())
        b.push_back('0');
    int pom,last=0;
    for(int x=0;x<a.size();x++)
    {
        pom=f(a[x])+f(b[x])+last;
        c+=inv(pom%10);
        last=pom/10;
    }
    if(last!=0)
        c+=inv(last);
    reverse(c.begin(),c.end());
    return c;
}
string mini(string a,string b)
{
    if(a.size()>b.size())
        return b;
    else if(b.size()>a.size())
        return a;
    else
        return min(a,b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int b=1e6,pom;
    string a,c="",d="",minik="";
    while(b--)
        minik+='9';
    cin>>b>>a;
    a.push_back('+');
    pom=b/2;
    while(a[pom]=='0')
        pom--;
    for(int x=0;x<b;x++)
    {
        if(x<pom)
            c+=a[x];
        else
            d+=a[x];
    }
    minik=mini(minik,sum(c,d));
    c="";
    d="";
    pom=b/2;
    while(a[pom]=='0')
        pom++;
    for(int x=0;x<b;x++)
    {
        if(x<pom)
            c+=a[x];
        else
            d+=a[x];
    }
    minik=mini(minik,sum(c,d));
    c="";
    d="";
    pom=b/2+1;
    while(a[pom]=='0')
        pom++;
    for(int x=0;x<b;x++)
    {
        if(x<pom)
            c+=a[x];
        else
            d+=a[x];
    }
    minik=mini(minik,sum(c,d));
    c="";
    d="";
    pom=b/2+1;
    while(a[pom]=='0')
        pom++;
    for(int x=0;x<b;x++)
    {
        if(x<pom)
            c+=a[x];
        else
            d+=a[x];
    }
    minik=mini(minik,sum(c,d));
    cout<<minik;
	return 0;
}