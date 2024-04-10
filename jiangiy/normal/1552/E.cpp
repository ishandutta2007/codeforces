#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n,m,s[10005],c[105],l[105],r[105];
bool vis[105];
int main(){
	scanf("%d%d",&n,&m);
	int r=(n+m-2)/(m-1);
	for(int i=1;i<=n*m;i++)scanf("%d",s+i);
	int cur=0;
	while(cur<n*m){
		int i=cur+1,ok=0;
		while(i<=n*m){
			if(!vis[s[i]]&&++c[s[i]]==2)ok++;
			i++;
			if(ok==r)break;
		}
		i--;
		for(int j=1;j<=n;j++) if(c[j]>=2){
			for(int k=cur+1;k<=i;k++) if(s[k]==j){
				if(!l[j])l[j]=k;
				else::r[j]=k;
			}
			vis[j]=1;
		}
		for(int j=1;j<=n;j++)c[j]=0;
		cur=i;
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",l[i],::r[i]);
}