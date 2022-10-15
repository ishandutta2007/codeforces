#include<bits/stdc++.h>
using namespace std;
vector<int> bn[100100];
vector<int> bun[100100];
int pn[100100];
int paint[100100];
int a[100100];
int b[100100];
int c[100100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
        	bn[i].clear();
        	bun[i].clear();
			pn[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			paint[i]=0;
		}
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
        	cin>>b[i];
        	if(a[i]==b[i])
        		bun[b[i]].push_back(i);
        	else	bn[b[i]].push_back(i);
		}
		for(int i=1;i<=m;i++)
		{
			cin>>c[i];
			if((int)(bn[c[i]].size()))
			{
				paint[i]=bn[c[i]][min(pn[c[i]],(int)(bn[c[i]].size())-1)];
				pn[c[i]]++;
			}
		}
		if(!paint[m])
		{
			if((int)(bun[c[m]].size()))
				paint[m]=bun[c[m]][0];
			else
			{
				puts("NO");
				continue;
			}
		}
		bool f=true;
		for(int i=1;i<=n;i++)
			if(pn[i]<(int)(bn[i].size()))
			{
				f=false;
				break;
			}
		if(!f)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=m;i++)
			if(paint[i])
				cout<<paint[i]<<" ";
			else	cout<<paint[m]<<" ";
		puts("");
    }
    return 0;
}