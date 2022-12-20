#include<cstdio>
const int maxn=1000010,maxm=1000010;
int n,m;
struct edge{int to;edge*next;}E[maxm],*fir[maxn];
bool rea[maxn];
int del[maxn],Q[maxn],k;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		E[i]=(edge){b,fir[a]};fir[a]=E+i;
	}
	for(int i=1;i<=n;i++)if(!del[i])
		for(edge*e=fir[del[i]=i];e;e=e->next)if(!del[e->to])del[e->to]=i;
	for(int i=n;i;i--)if(del[i]==i&&!rea[i])
		for(edge*e=fir[Q[k++]=i];e;e=e->next)rea[e->to]=1;
	printf("%d\n",k);
	while(k--)printf("%d%c",Q[k]," \n"[!k]);
    return 0;
}