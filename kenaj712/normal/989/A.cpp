#include<bits/stdc++.h>
using namespace std;
int tab[200][3];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    for(int x=0;x<a.size();x++)
    {
        if(a[x]=='A')
        {
            tab[x+1][0]=1;
            tab[x][0]=1;
            tab[x+2][0]=1;
        }
        if(a[x]=='B')
        {
            tab[x+1][1]=1;
            tab[x][1]=1;
            tab[x+2][1]=1;
        }
        if(a[x]=='C')
        {
            tab[x+1][2]=1;
            tab[x][2]=1;
            tab[x+2][2]=1;
        }
    }
    bool czy=false;
    for(int x=1;x<=a.size()+1;x++)
        if(tab[x][0]+tab[x][1]+tab[x][2]==3)
        czy=true;
    if(czy==true)
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}