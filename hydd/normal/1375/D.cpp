#include<bits/stdc++.h>
using namespace std;
int T,n,a[1100]; bool vis[1100];
int ans,Ans[2100];
int getmex(){
	for (int i=0;i<=n;i++) vis[i]=false;
	for (int i=0;i<n;i++) vis[a[i]]=true;
	for (int i=0;i<=n;i++)
		if (!vis[i]) return i;
	throw "error";
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		ans=0;
		while (true){
			int x=getmex();
			if (x==n){
				int pos=n;
				for (int i=0;i<n;i++)
					if (a[i]!=i) pos=i;
				if (pos==n) break;
				Ans[++ans]=pos,a[pos]=x;
			} else Ans[++ans]=x,a[x]=x;
		}
		printf("%d\n",ans);
		for (int i=1;i<=ans;i++) printf("%d ",Ans[i]+1);
		putchar('\n');
	}
	return 0;
}