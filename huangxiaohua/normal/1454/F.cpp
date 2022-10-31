#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l2[200500],ml[200500],mr[200500],a[200500],st[200500][22],l,r,md,sb;
int chk(int l,int r){int k=l2[r-l+1];return min(st[l][k],st[r-(1<<k)+1][k]);}

int main(){
	scanf("%d",&t);l2[0]=-1;
	for(i=1;i<=200000;i++){l2[i]=l2[i>>1]+1;}
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ml[i]=max(ml[i-1],a[i]);
			st[i][0]=a[i];
		}
		mr[n+1]=0;
		for(i=n;i>=1;i--){
			mr[i]=max(mr[i+1],a[i]);
		}
		for(j=1;j<=19;j++){
			for(i=1;i+(1<<j)-1<=n;i++){
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
		for(i=1;i<=n-2;i++){
			l=i+1;r=n-1;
			while(l<=r){
				md=(l+r)/2;
				sb=chk(i+1,md);
				if(sb>ml[i]&&mr[md+1]<ml[i]){break;}
				if(sb<ml[i]&&mr[md+1]>ml[i]){break;}
				if(sb>ml[i]||mr[md+1]>ml[i]){l=md+1;continue;}
				if(sb==ml[i]&&mr[md+1]==ml[i]){printf("YES\n%d %d %d\n",i,md-i,n-md);goto aaa;}
				else{r=md-1;}
			}
		}
		puts("NO");
		aaa:;
	}
}