#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
int tab[300010];
int rmq[2][25][300010];
int ju[25][300010];
short int lg[300010];
map<int,long long> wyn;
void rev(int n)
{
	for(int i=0;i<n-i+1;i++)
	{
		for(int j=0;j<25;j++)
		{
			swap(rmq[1][j][i],rmq[1][j][n-i+1]);
		}
	}
}
void build(bool r,int n)
{
	if(r)
		reverse(tab+1,tab+n+1);
	for(int i=n-1;i>=0;i--)
	{
		ju[0][i]=i+1;
		rmq[r][0][i]=tab[i+1];
		for(int j=1;(j<25)&&(ju[j-1][ju[j-1][i]]!=0);j++)
		{
			ju[j][i]=ju[j-1][ju[j-1][i]];
			rmq[r][j][i]=__gcd(rmq[r][j-1][i],rmq[r][j-1][ju[j-1][i]]);
		}
	}
	if(r)
	{
		reverse(tab+1,tab+n+1);
		rev(n);
	}
	return;
}
inline int gcd(int &p,int &k)
{
	return __gcd(rmq[0][lg[k-p+1]][p-1],rmq[1][lg[k-p+1]][k+1]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,a,pot,x,p,k,xd,s,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>tab[i];
	build(0,n);
	build(1,n);
	pot=2;
	j=1;
	i=1;
	while(i<=n)
	{
		while((i<=n)&&(i<pot))
		{
			lg[i]=j-1;
			i++;
		}
		j++;
		pot*=2;
	}
	for(i=1;i<=n;i++)
	{
		j=i;
		while(j<=n)
		{
			/*if(gcd(i,j)==2)
				cerr<<i<<" "<<j<<" "<<lg[j-i+1]<<" "<<rmq[0][lg[j-i+1]][i-1]<<" "<<rmq[1][lg[j-i+1]][j+1]<<"\n";*/
			x=i;
			p=j;k=n;
			xd=gcd(x,p);
			while(p<k)
			{
				s=(p+k+1)/2;
				//cerr<<x<<" "<<p<<" "<<k<<" "<<s<<"\n";
				if(gcd(x,s)!=xd)
					k=s-1;
				else
					p=s;
			}
			a=p;
			wyn[gcd(i,j)]+=a-j+1;
			j=a+1;
		}
	}
	//cerr<<gcd(1,3)<<" "<<lg[3]<<" "<<rmq[0][lg[3]][0]<<" "<<rmq[1][lg[3]][4];
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>a;
		if(wyn.find(a)!=wyn.end())
			cout<<wyn[a]<<"\n";
		else
			cout<<"0\n";
	}
	return 0;
}