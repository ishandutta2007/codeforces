#include<cstdio>
#include<cstring>
#include<vector>

#define LIMIT 200

int len[600000];
int x[600000];
std::vector<int> a[600000];
std::vector<int> b;
int d[2000][2000];

int encode(char *s)
{
	int r=0;
    while(*s)
	{
		r*=27;
		r+=*s-'a'+1;
		s++;
	}
	return r;
}

char s[100000];
char t[10];
char p[10];
char q[10];

int main()
{
	int res;
	int st,en;
	int	i,j,k,l,n,m;
	scanf("%s%d",s,&m);
	n=strlen(s);
	for(i=1;i<=4;i++)for(j=i;j<=n;j++)
	{
		strncpy(t,s+j-i,i);
		t[i]=0;
		a[encode(t)].push_back(j);
		len[encode(t)]=i;
	}
	for(i=0;i<600000;i++)if(a[i].size()>LIMIT)
	{
		x[i]=b.size();
		b.push_back(i);
	}
	for(i=0;i<b.size();i++)for(j=0;j<b.size();j++)
	{
		d[i][j]=2e9;
        for(k=0;k<a[b[i]].size();k++)
		{
			l=std::lower_bound(a[b[j]].begin(),a[b[j]].end(),a[b[i]][k])-a[b[j]].begin();
			if(l>0)
			{
				st=n+1;
				en=-1;
				if(a[b[i]][k]-len[b[i]]<st)st=a[b[i]][k]-len[b[i]];
				if(a[b[i]][k]>en)en=a[b[i]][k];
				if(a[b[j]][l-1]-len[b[j]]<st)st=a[b[j]][l-1]-len[b[j]];
				if(a[b[j]][l-1]>en)en=a[b[j]][l-1];
				if(en-st<d[i][j])d[i][j]=en-st;
			}
			if(l<a[b[j]].size())
			{
				st=n+1;
				en=-1;
				if(a[b[i]][k]-len[b[i]]<st)st=a[b[i]][k]-len[b[i]];
				if(a[b[i]][k]>en)en=a[b[i]][k];
				if(a[b[j]][l]-len[b[j]]<st)st=a[b[j]][l]-len[b[j]];
				if(a[b[j]][l]>en)en=a[b[j]][l];
				if(en-st<d[i][j])d[i][j]=en-st;
			}
		}
	}
	while(m--)
	{
		scanf("%s%s",p,q);
		i=encode(p);
		j=encode(q);
        if(a[i].empty()||a[j].empty())puts("-1");
        else
		{
			res=2e9;
            if(a[i].size()<=LIMIT)
			{
				for(k=0;k<a[i].size();k++)
				{
					l=std::lower_bound(a[j].begin(),a[j].end(),a[i][k])-a[j].begin();
					if(l>0)
					{
						st=n+1;
						en=-1;
						if(a[i][k]-len[i]<st)st=a[i][k]-len[i];
						if(a[i][k]>en)en=a[i][k];
						if(a[j][l-1]-len[j]<st)st=a[j][l-1]-len[j];
						if(a[j][l-1]>en)en=a[j][l-1];
						if(en-st<res)res=en-st;
					}
					if(l<a[j].size())
					{
						st=n+1;
						en=-1;
						if(a[i][k]-len[i]<st)st=a[i][k]-len[i];
						if(a[i][k]>en)en=a[i][k];
						if(a[j][l]-len[j]<st)st=a[j][l]-len[j];
						if(a[j][l]>en)en=a[j][l];
						if(en-st<res)res=en-st;
					}
				}
			}
			else if(a[j].size()<=LIMIT)
			{
				for(k=0;k<a[j].size();k++)
				{
					l=std::lower_bound(a[i].begin(),a[i].end(),a[j][k])-a[i].begin();
					if(l>0)
					{
						st=n+1;
						en=-1;
						if(a[j][k]-len[j]<st)st=a[j][k]-len[j];
						if(a[j][k]>en)en=a[j][k];
						if(a[i][l-1]-len[i]<st)st=a[i][l-1]-len[i];
						if(a[i][l-1]>en)en=a[i][l-1];
						if(en-st<res)res=en-st;
					}
					if(l<a[i].size())
					{
						st=n+1;
						en=-1;
						if(a[j][k]-len[j]<st)st=a[j][k]-len[j];
						if(a[j][k]>en)en=a[j][k];
						if(a[i][l]-len[i]<st)st=a[i][l]-len[i];
						if(a[i][l]>en)en=a[i][l];
						if(en-st<res)res=en-st;
					}
				}
			}
			else res=d[x[i]][x[j]];
			printf("%d\n",res);
		}
	}
	return 0;
}