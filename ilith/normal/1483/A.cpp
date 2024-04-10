#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int sz[100003];
vector<int> a[100003];
vector<int> v[100003];
int ans[100003];
int cnt[100003];
int A[100003];
signed main()
{
    for(int T=read();T--;){
    	memset(A,0,sizeof(A));
    	int n=read(),m=read();
    	for(int i=1; i<=n; i++) a[i].clear(),cnt[i]=0;
    	for(int i=1; i<=m; i++)
    	{ans[i]=0;
    	v[i].clear();
    		sz[i]=read();
    		for(int j=1,x; j<=sz[i]; j++) 
    		{
    			x=read(),a[x].push_back(i);
    			v[i].push_back(x);
    		}
    	}
    	for(int i=1; i<=n; i++) if((int)a[i].size()<=(m-1)/2+1)
    	{
    		for(int j:a[i]) if(!ans[j]) ans[j]=i;
    	}
    	bool QAQ=0;
    	for(int i=1; i<=m; i++) if(!ans[i]&&sz[i]==1)
    	{
    		if(A[v[i][0]]<(m-1)/2+1) ++A[v[i][0]],ans[i]=v[i][0];
    		else 
    		{
    			QAQ=1;
    			break;
    		}
    	}
    	if(QAQ)
    	{
    		puts("NO");
    		continue;
    	}
    	for(int i=1; i<=m; i++) if(!ans[i])
    	{
    		int t=99999999,id=0;
    		for(int j:v[i]) if(A[j]<t) t=A[j],id=j;
    		if(t>=(m-1)/2+1||id==0) 
    		{
    			QAQ=1;
    			break;
    		}
    		ans[i]=id,++A[id];
    	}
    	if(QAQ)
    	{
    		puts("NO");
    		continue;
    	}
    	puts("YES");
    	for(int i=1; i<=m; i++) printf("%d ",ans[i]);
    	puts("");
    }
	return 0;
}