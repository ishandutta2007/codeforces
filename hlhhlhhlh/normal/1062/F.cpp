// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=600010;
int i,j,k;
int f1[maxn],f2[maxn],f3[maxn],th;
int n,m,x,y,ans;
int dp[2][maxn],a[maxn],ha[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void add(int x,int y){
	th++; f2[th]=y; f3[th]=f1[x]; f1[x]=th;
}
void solve(int th){
	int i,j,l=1,r=0;
	memset(ha,0,sizeof(ha));
	memset(a,0,sizeof(a));
	for (i=1;i<=n;i++){
		j=f1[i];
		while (j!=0){
			if (j%2==th){
				ha[f2[j]]++;
			}
			j=f3[j];
		}
	}
	for (i=1;i<=n;i++){
		if (ha[i]==0){
			r++; a[r]=i;
		}
	}
	while (l<=r){
		if (r-l==0){
			dp[th][a[l]]=n-r;
		}
		else{
			if (r-l==1){
				i=f1[a[l+1]];
				while (i!=0){
					if (i%2==th){
						if (ha[f2[i]]==1){
							dp[th][a[l]]=-1e9;
						}
					}
					i=f3[i];
				}
				if (dp[th][a[l]]!=-1e9) dp[th][a[l]]=n-r;
			}
			else{
				dp[th][a[l]]=-1e9;
			}
		}
		i=f1[a[l]];
		while (i!=0){
			if (i%2==th){
				ha[f2[i]]--;
				if (ha[f2[i]]==0){
					r++; a[r]=f2[i];
				}
			}
			i=f3[i];
		}
		l++;
	}
}
int main(){
	n=read(); m=read();
	for (i=1;i<=m;i++){
		x=read(); y=read();
		add(x,y); add(y,x);
	}
	solve(0);
	solve(1);
	for (i=1;i<=n;i++){
		if (dp[0][i]+dp[1][i]>=n-2){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}