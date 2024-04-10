#include<bits/stdc++.h>
using namespace std;
int val(char a)
{
    return int(a)-97;
}
int zlicz[30];
bool pal(string a)
{
    string pom=a;
    reverse(pom.begin(),pom.end());
    if(a==pom)
        return true;
    else
        return false;
}
bool check(string a,int b)
{
    string pom="";
    for(int x=b;x<a.size()+b;x++)
        pom+=a[x%a.size()];
    if(pal(pom)==true&&pom!=a)
        return true;
    return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    for(int x=0;x<a.size();x++)
        zlicz[val(a[x])]++;
    int licz=0;
    for(int x=0;x<=27;x++)
        if(zlicz[x]>1)
            licz++;
    if(licz<2)
    {
        cout<<"Impossible";
        return 0;
    }
    for(int x=1;x<a.size();x++)
        if(check(a,x)==true)
        {
            cout<<1;
            return 0;
        }
    cout<<2;

	return 0;
}