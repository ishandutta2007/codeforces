#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn=100005;

int f[maxn];
int on[maxn];
int onf[maxn];
int nfact;

void fact(int n)
{
// 	cout << "fact " << n << endl;
	nfact=0;
	int maxi=sqrt(n)+3;
	for (int i=2;i<maxi;i++)
	{
		if (n%i==0)
		{
			f[nfact]=i;
			nfact++;
		}
		while (n%i==0) n=n/i;
	}
	if (n>1)
	{
		f[nfact]=n;
		nfact++;
	}
// 	for (int i=0;i<nfact;i++) cout << f[i] << ' ';
// 	cout << endl;
}

int main()
{
	int n,m;
	scanf("%d%d\n",&n,&m);
// 	pr.resize(0);
// 	for (int i=2;i<n;i++) if (!npr[i])
// 	{
// 		pr.push_back(i);
// 		for (int j=2*i;j<=n;j+=i) npr[j]=1;
// 	}
// 	cout << pr.size() << endl;
	for (int i=0;i<m;i++)
	{
		char ch;
		int d;
		scanf("%c%d\n",&ch,&d);
// 		cout << ch << ' ' << d << endl;
		fact(d);
		if (ch=='+')
		{
			if (on[d])
			{
				printf("Already on\n");
				continue;
			}
			bool can=true;
			int conf;
			for (int i=0;i<nfact;i++) if (onf[f[i]])
			{
// 				cout << "conf " << i << ' ' << f[i] << endl;
				can=false;
				conf=f[i];
			}
			if (can)
			{
				printf("Success\n");
				for (int i=0;i<nfact;i++) onf[f[i]]=d;
				on[d]=1;
			} else printf("Conflict with %d\n",onf[conf]);
		}
		if (ch=='-')
		{
			if (!on[d])
			{
				printf("Already off\n");
				continue;
			}
			for (int i=0;i<nfact;i++) onf[f[i]]=0;
			on[d]=0;
			printf("Success\n");
		}
	}
	return 0;
}