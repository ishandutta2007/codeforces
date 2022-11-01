#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=300005;
int n,m,s[N],c[N],a[N],b[N];
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		for(int i=0;i<n;i++)c[i]=0;
		for(int i=1;i<=n;i++){
			int t=i-s[i];
			if(t<0)t+=n;
			c[t]++;
		}
		std::vector<int>ans;
		for(int i=0;i<n;i++) if(c[i]>=n/20-10){
			for(int j=1;j<=n;j++){
				a[j]=s[j+i>n?j+i-n:j+i];
			}
			for(int j=1;j<=n;j++)b[a[j]]=j;
			int cnt=0;
			for(int j=1;j<=n;j++) if(a[j]!=j){
				int k=b[j],x=a[j],y=a[k];
				std::swap(a[j],a[k]);
				std::swap(b[x],b[y]);
				cnt++;
			}
			if(cnt<=m)ans.push_back(i);
		}
		printf("%d ",(int)ans.size());
		for(int x:ans)printf("%d ",x);
		puts("");
	}
}