#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int suf(int a)
{
    int pom=a/2;
    if(pom+pom+1==a)
        return pom+1;
    else
        return pom;
}
int pod(int a)
{
    int pom=a/2;
    if(pom+pom+1==a)
        return pom;
    else
        return pom-1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    int licz=0;
    for(int x=0;x<a;x++)
        if(tab[x]%2==1||tab[x]%2==-1)
            licz++;
    licz/=2;
    for(int x=0;x<a;x++)
    {
        if(tab[x]%2==0)
            cout<<tab[x]/2<<'\n';
        else
        {
            if(licz==0)
                cout<<pod(tab[x]);
            else
            {
                licz--;
                cout<<suf(tab[x]);
            }
            cout<<'\n';
        }
    }
	return 0;
}