#include<bits/stdc++.h>
using namespace std;
int tab[5];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    while(a--)
    {
        cin>>b;
        tab[b]++;
    }
    if(tab[2]!=0)
    {
        cout<<2<<" ";
        tab[2]--;
    }
    if(tab[1]!=0)
    {
        cout<<1<<" ";
        tab[1]--;
    }
    while(tab[2]!=0)
    {
        cout<<2<<" ";
        tab[2]--;
    }
    while(tab[1]!=0)
    {
        cout<<1<<" ";
        tab[1]--;
    }
	return 0;
}