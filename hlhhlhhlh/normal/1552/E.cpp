#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m;
const int maxn=100010;
int a[maxn],ha[110],haa[110]; 
int i,j,k;
int num;
struct node{
	int w,l,r; 
}ans[maxn];
bool cmp(node a,node b){ return a.w<b.w; }
int main(){

	n=read(); m=read();
	for (i=1;i<=n*m;i++){
		a[i]=read();
	}
	while (1){
		
		memset(ha,0,sizeof(ha));
		for (i=1;i<=n*m;i++){
			
			if (ha[a[i]]==0) ha[a[i]]=i;
			else{
				if (haa[a[i]]==1) continue;
				num++;
				ans[num].w=a[i];
				ans[num].l=ha[a[i]];
				ans[num].r=i;
				haa[a[i]]=1;
				if (num==n){
					sort(ans+1,ans+num+1,cmp);
					for (j=1;j<=n;j++) printf("%d %d\n",ans[j].l,ans[j].r);
					return 0;
				}
				memset(ha,0,sizeof(ha));
			}
		}
		
	}

	return 0;
}