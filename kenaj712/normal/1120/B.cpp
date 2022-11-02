#include<bits/stdc++.h>
using namespace std;
int conv(char a)
{
    return int(a)-48;
}
vector<pair<int,int>> v;
int tab[1000005];
int tab2[1000005];
int tab3[1000005];
int ile;
void rek(int a,int c)
{
    if(ile>1e5)
        return;
    if(c==-1)
    {
        if(tab[a+1]==0)
            rek(a+1,1);
        if(ile>1e5)
            return;
        tab[a]--;
        tab[a+1]--;
        ile++;
        if(ile>1e5)
        return;
        cout<<a<<" "<<-1<<'\n';
    }
    else
    {
        if(tab[a+1]==9)
            rek(a+1,-1);
        if(ile>1e5)
            return;
        tab[a]++;
        tab[a+1]++;
        ile++;
        if(ile>1e5)
        return;
        cout<<a<<" "<<1<<'\n';
    }
    if(ile>1e5)
        return;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    char znak;
    long long licz=0;
    for(int x=1;x<=a;x++)
    {
        cin>>znak;
        tab[x]=conv(znak);
        if(x%2==1)
            licz+=tab[x];
        else
            licz-=tab[x];
        tab3[x]=tab[x];
    }
    for(int x=1;x<=a;x++)
    {
        cin>>znak;
        tab2[x]=conv(znak);
        if(x%2==1)
            licz-=tab2[x];
        else
            licz+=tab2[x];
    }
    if(licz!=0)
    {
        cout<<-1;
        return 0;
    }
    licz=0;
    int pom;
    for(int x=1;x<=a;x++)
    {
        pom=tab[x]-tab2[x];
        tab[x+1]-=pom;
        licz+=abs(pom);
        tab[x]=tab3[x];
    }
    cout<<licz<<'\n';
    for(int x=1;x<=a;x++)
    {
        if(ile>1e5)
            return 0;
        while(tab[x]>tab2[x])
        {
            if(ile>1e5)
                return 0;
            rek(x,-1);
        }

        while(tab[x]<tab2[x])
        {
            if(ile>1e5)
                return 0;
            rek(x,1);
        }

    }
	return 0;
}