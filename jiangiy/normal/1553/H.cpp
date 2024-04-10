#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=1050005;
int n,m,k,bit[N],ta[N>>1],ans[N>>1];
bool s[N];
int qmin(int x,int y){
	int t=x,b=bit[x],res=0;
	while(t<m){
		int u=y>>b&1;
		if(!s[t<<1|u])u^=1,res+=1<<b;
		t=t<<1|u;
		b--;
	}
	return res;
}
int qmax(int x,int y){
	int b=bit[x],mask=(1<<b+1)-1;
	return qmin(x,y^mask)^mask;
}
int main(){
	scanf("%d%d",&n,&k);
	m=1<<k;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		s[x+m]=1;
	}
	for(int i=0;i<m;i++)bit[i+m]=-1;
	for(int i=m-1;i;i--)s[i]=s[i<<1]|s[i<<1|1],bit[i]=bit[i<<1]+1;
	for(int i=0;i<m;i++)ans[i]=1e9;
	for(int i=1,ic=0;i<(1<<k);i<<=1,ic++){
		for(int j=0;j<i*2;j++)ta[j]=1e9;
		for(int j=0;j<(1<<k);j+=i*2){
			int a=j+m>>ic,b=j+m+i>>ic;
			if(!s[a]||!s[b])continue;
			for(int k=0;k<i;k++){
				ta[k]=std::min(ta[k],qmin(b,k)+(1<<ic)-qmax(a,k));
			}
			for(int k=0;k<i;k++){
				ta[k+i]=std::min(ta[k+i],qmin(a,k)+(1<<ic)-qmax(b,k));
			}
		}
		int mask=i*2-1;
		for(int j=0;j<m;j++)ans[j]=std::min(ans[j],ta[j&mask]);
	}
	for(int i=0;i<m;i++)printf("%d ",ans[i]);
	puts("");
}