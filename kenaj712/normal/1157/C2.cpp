#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
vector<int> v;
string d="";
int f(int a,int b)
{
    int licz1=0,licz2=0;
    for(int x=a;x<=b;x++)
    {
        if(tab[x]>v.back()&&tab[x]>tab[x-1])
            licz1++;
        else
            break;
    }
    for(int x=b;x>=a;x--)
    {
        if(tab[x]>v.back()&&tab[x]>tab[x+1])
            licz2++;
        else
            break;
    }
    if(licz1>=licz2)
    {
        while(licz1--)
            d+='L';
    }
    else
    {
        while(licz2--)
            d+='R';
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    v.push_back(-1);
    int pocz=1,kon=a;
    while(0==0)
    {
        if(tab[pocz]<=v.back()&&tab[kon]<=v.back())
            break;
        if(tab[pocz]==tab[kon])
        {
            f(pocz,kon);
            break;
        }
        if((tab[pocz]<tab[kon]&&tab[pocz]>v.back())||tab[kon]<=v.back())
        {
            d+='L';
            pocz++;
            v.push_back(tab[pocz-1]);
        }
        else
        {
            d+='R';
            kon--;
            v.push_back(tab[kon+1]);
        }
    }
    cout<<d.size()<<'\n'<<d;
	return 0;
}