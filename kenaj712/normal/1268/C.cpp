#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int tree1[1000005];
long long tree2[1000005];
int gdzie[1000005];
int pot=(1<<18);
void ins1(int a)
{
    int pom=a+pot;
    while(pom!=0)
    {
        tree1[pom]++;
        pom/=2;
    }
}
void ins2(int a)
{
    int pom=a+pot;
    while(pom!=0)
    {
        tree2[pom]+=a;
        pom/=2;
    }
}
int check1(int a,int b)
{
    int l=a+pot,r=b+pot;
    int war=tree1[l];
    if(l!=r)
        war+=tree1[r];
    while(l/2!=r/2)
    {
        if(l%2==0)
            war+=tree1[l+1];
        if(r%2==1)
            war+=tree1[r-1];
        l/=2;
        r/=2;
    }
    return war;
}
long long check2(int a,int b)
{
    int l=a+pot,r=b+pot;
    long long war=tree2[l];
    if(l!=r)
        war+=tree2[r];
    while(l/2!=r/2)
    {
        if(l%2==0)
            war+=tree2[l+1];
        if(r%2==1)
            war+=tree2[r-1];
        l/=2;
        r/=2;
    }
    return war;
}
int bins_pocz(int a,int ile)
{
    int pocz=1,kon=a,sr;
    while(pocz!=kon)
    {
        sr=(pocz+kon)/2;
        if(check1(1,sr)>=ile)
            kon=sr;
        else
            pocz=sr+1;
    }
    return pocz;
}
int bins_koniec(int a,int ile)
{
    int pocz=1,kon=a,sr;
    while(kon-pocz>1)
    {
        sr=(pocz+kon)/2;
        if(check1(sr,a)>=ile)
            pocz=sr;
        else
            kon=sr;
    }
    while(pocz!=a+1 && check1(pocz,a)>=ile)
        pocz++;
    pocz--;
    return pocz;
}
long long ile_inwersji;
void sprawdz(int a,int ile)
{
    if(ile==1)
    {
        cout<<0<<" ";
        return;
    }
    ile_inwersji+=check1(gdzie[ile],a)-1;
    long long ile2=ile/2;
    long long war1=bins_pocz(a,ile2),war2=bins_koniec(a,ile2);
    long long xdd=-check2(1,war1)+check2(war2,a)-ile2*(ile2+1);
    if(ile%2==0)
        xdd+=ile2;
    cout<<xdd+ile_inwersji<<" ";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        gdzie[tab[x]]=x;
    }
    for(int x=1;x<=a;x++)
    {
        ins1(gdzie[x]);
        ins2(gdzie[x]);
        sprawdz(a,x);
    }
	return 0;
}