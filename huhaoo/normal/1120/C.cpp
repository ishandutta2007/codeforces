/****************************************************************
	File name: 1120C.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 3/4/2019, 12:13:55 AM
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define N 100010
#define C 30
#define inf (15<<26)
int n,l[N],s[N][C],f[N],cnt,st,lst,r[N],w[N],siz[N],ans,g[N],a,b;
char c[N];
int main()
{
	n=read();
	a=read();
	b=read();
    scanf("%s",c+1);
    st=lst=++cnt;
	fr(i,1,n)
		g[i]=inf;
    fr(i,1,n)
    {
		g[i]=min(g[i],g[i-1]+a);
		int k=st;
		fr(j,i,n)
		{
			k=s[k][c[j]-'a'];
			if(!k)
				break;
			g[j]=min(g[j],g[i-1]+b);
		}
        int j=lst,np=++cnt,nq,p=0,q,o=c[i]-'a';
        siz[np]=1;l[np]=l[lst]+1;lst=np;
        while(j&&!s[j][o])
        {
            s[j][o]=np;
            j=f[j];
        }
        p=j;
        if(!p){f[np]=st;continue;}
        q=s[p][o];
        if(l[q]==l[p]+1){f[np]=q;continue;}
        nq=++cnt;f[nq]=f[q];l[nq]=l[p]+1;
        fr(i,0,25)s[nq][i]=s[q][i];
        f[np]=f[q]=nq;j=p;
        while(j&&s[j][o]==q)
        {
            s[j][o]=nq;
            j=f[j];
        }
    }
	printf("%d\n",g[n]);
    return 0;
}