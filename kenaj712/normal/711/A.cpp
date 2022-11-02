#include<bits/stdc++.h>
using namespace std;
string tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    bool czy=false;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        if(tab[x][0]=='O'&&tab[x][1]=='O')
            czy=true;
        if(tab[x][3]=='O'&&tab[x][4]=='O')
            czy=true;
    }
    if(czy==false)
        cout<<"NO";
    else
    {
        cout<<"YES"<<'\n';
        czy=false;
        for(int x=0;x<a;x++)
        {
            if(czy==true)
                cout<<tab[x]<<'\n';
            else
            {
                if(tab[x][0]=='O'&&tab[x][1]=='O')
                {
                    czy=true;
                    tab[x][0]='+';
                    tab[x][1]='+';
                }
                else if(tab[x][3]=='O'&&tab[x][4]=='O')
                {
                    czy=true;
                    tab[x][3]='+';
                    tab[x][4]='+';
                }
                cout<<tab[x]<<'\n';
            }
        }
    }
	return 0;
}