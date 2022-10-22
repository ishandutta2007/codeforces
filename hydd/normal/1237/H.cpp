#include<bits/stdc++.h>
using namespace std;
int T,n,a[4],b[4],p[4100],q[4100],Ans[4100];
char s[4100],t[4100];
int hs(int x,int y){ return (x<<1)|y;}
void rev(int *a,int x){
	for (int i=0;i<x-i;i++) swap(a[i],a[x-i]);
	for (int i=0;i<=x;i++)
		if (a[i]==1||a[i]==2) a[i]^=3;
}	
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%s",s); scanf("%s",t);
		a[0]=a[1]=a[2]=a[3]=0;
		b[0]=b[1]=b[2]=b[3]=0;
		n=strlen(s); n>>=1;
		for (int i=0;i<n;i++){
			p[i]=hs(s[i<<1]-'0',s[i<<1|1]-'0');
			q[i]=hs(t[i<<1]-'0',t[i<<1|1]-'0');
			a[p[i]]++; b[q[i]]++;
		}
		if (a[0]!=b[0]||a[1]+a[2]!=b[1]+b[2]||a[3]!=b[3]){
			puts("-1");
			continue;
		}
		Ans[0]=-1;
		int ans=0;
		if (a[1]!=b[1]){
			int tmp1=a[1]-a[2],tmp2=b[1]-b[2];
			if (abs(tmp1)>abs(tmp2)){
				for (int i=0;i<n;i++)
					if (p[i]==1||p[i]==2){
						a[p[i]]--;
						a[p[i]^3]++;
						if (a[1]==b[1]){
							rev(p,i);
							Ans[++ans]=i;
							break;
						}
					}
			} else{
				for (int i=0;i<n;i++)
					if (q[i]==1||q[i]==2){
						b[q[i]]--;
						b[q[i]^3]++;
						if (a[1]==b[1]){
							rev(q,i);
							Ans[0]=i;
							break;
						}
					}				
			}
		}
		for (int i=0;i<n-1;i++)
			for (int j=i;j<n;j++)
				if (p[j]==q[i]){
					if (j>0) rev(p,j-1),Ans[++ans]=j-1;
					rev(p,j),Ans[++ans]=j;
					break;
				}
		if (n>1) rev(p,n-2),Ans[++ans]=n-2;
		for (int i=0;i<n-1;i++) assert(p[i]==q[i]);
		if (Ans[0]!=-1) Ans[++ans]=Ans[0];
		printf("%d\n",ans);
		if (ans){
			for (int i=1;i<ans;i++) printf("%d ",(Ans[i]+1)<<1);
			printf("%d\n",(Ans[ans]+1)<<1);
		} else putchar('\n');
	}
	return 0;
}