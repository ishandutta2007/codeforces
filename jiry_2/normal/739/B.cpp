#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long d[210000];
int p[210000],len,n,ans[210000],a[210000],s[210000],w[210000],head;
struct bian{
	int next,point,w;
}b[410000];
void ade(int k1,int k2,int k3){
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1,int k2,int k3){
	ade(k1,k2,k3); ade(k2,k1,k3);
}
void dfs(int k1,int k2){
	int l=0,r=head+1,an=0;
	while (l<r){
		int mid=l+r>>1;
		if (d[k1]-d[s[mid]]>a[k1]){
			an=mid; l=mid+1;
		} else r=mid;
	}
	s[++head]=k1; ans[k2]++; ans[s[an]]--;
//	cout<<"fa "<<k1<<" "<<k2<<" "<<s[an]<<endl;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			d[j]=d[k1]+b[i].w; dfs(j,k1); ans[k1]+=ans[j];
		}
	}
	head--;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,i,k2);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}