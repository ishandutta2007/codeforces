#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
pair<long long,long long> tab[200010];
long long gcd(long long a,long long b)
{
	while(b>0)
	{
		swap(a,b);
		b%=a;
	}
	return a;
}
inline long long ilo(pair<long long,long long> a,pair<long long,long long> b,pair<long long,long long> sr)
{
	a.fi-=sr.fi;
	a.se-=sr.se;
	b.fi-=sr.fi;
	b.se-=sr.se;
	return abs(a.fi*b.se-a.se*b.fi);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(10);
	int n,i,j;
	long long pom,pole,kra,pot,mian;
	double ws,w;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>tab[i].fi>>tab[i].se;
		tab[n+i]=tab[i];
	}
	if(n<=50)
	{
		pot=1;
		for(i=1;i<=n;i++)
			pot*=2;
		mian=pot-1-n-((n*(n-1))/2);
		pot/=4;
	}
	else
	{
		ws=1+n+((n*(n-1))/2);
		for(i=1;i<=n-2;i++)
			ws/=2;
		ws=(double)4-ws;
		ws=((double)1)/ws;
	}
	w=0;
	for(i=1;i<=min(30,n-3);i++)
	{
		if(n<=50)
		{
			ws=((double)(pot-n+i))/mian;
			pot/=2;
		}
		for(j=1;j<=n;j++)
		{
			pole=abs(ilo(tab[i+j],tab[i+j+1],tab[j]));
			kra=gcd(abs(tab[i+j].fi-tab[j].fi),abs(tab[i+j].se-tab[j].se))+gcd(abs(tab[i+j].fi-tab[i+j+1].fi),abs(tab[i+j].se-tab[i+j+1].se))+gcd(abs(tab[i+j+1].fi-tab[j].fi),abs(tab[i+j+1].se-tab[j].se));
			pom=((pole-kra)/2)+gcd(abs(tab[i+j+1].fi-tab[j].fi),abs(tab[i+j+1].se-tab[j].se));
			//cerr<<pole<<" "<<kra<<" "<<pom<<"\n";
			w+=ws*pom;
		}
		if(n>50)
			ws/=2;
	}
	pole=0;
	for(i=2;i<n;i++)
		pole+=abs(ilo(tab[i],tab[i+1],tab[1]))-gcd(abs(tab[i].fi-tab[i-1].fi),abs(tab[i].se-tab[i-1].se));
	pole-=gcd(abs(tab[n].fi-tab[n-1].fi),abs(tab[n].se-tab[n-1].se));
	pole-=gcd(abs(tab[n].fi-tab[1].fi),abs(tab[n].se-tab[1].se));
	pole/=2;
	pole++;
	w=(double)pole-w;
	cout<<w;
	return 0;
}