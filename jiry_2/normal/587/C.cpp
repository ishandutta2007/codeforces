#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct bian{
	int next,point;
}b[210000];
int father[110000][17],n,q,m,root[110000],p[110000],len,d[110000];
struct tree{
	int l,r,size;
}t[11000000];
vector<int>A[110000],ans;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int insert(int k1,int k2,int k3,int k4){
//	cout<<"insert "<<k1<<" "<<k2<<" "<<k3<<endl;
	len++; t[len]=t[k1]; t[len].size++; int now=len;
	if (k2==k3) return now;
	int mid=k2+k3>>1;
	if (mid>=k4) t[now].l=insert(t[k1].l,k2,mid,k4);
	else t[now].r=insert(t[k1].r,mid+1,k3,k4);
	return now;
}
void dfs(int k1,int k2){
	father[k1][0]=k2; d[k1]=d[k2]+1; root[k1]=root[k2];
	for (int i=0;i<A[k1].size();i++)
		root[k1]=insert(root[k1],1,m,A[k1][i]);
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2) dfs(j,k1);
	}
}
int getfather(int k1,int k2){
	if (d[k1]<d[k2]) swap(k1,k2);
	for (int i=16;i>=0;i--) if (d[k1]-d[k2]>=(1<<i)) k1=father[k1][i];
	if (k1==k2) return k1;
	for (int i=16;i>=0;i--) if (father[k1][i]!=father[k2][i]){
		k1=father[k1][i]; k2=father[k2][i];
	}
	return father[k1][0];
}
void getans(int k1,int k2,int k3,int k4,int k5,int k6,int k7){
	//cout<<"find "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<k6<<" "<<k7<<endl;
	if (k5==k6){
		int size=t[k1].size+t[k2].size-t[k3].size-t[k4].size;
	//	cout<<size<<" "<<k7<<endl;
		for (int i=1;i<=min(k7,size);i++) ans.push_back(k5);
	//	cout<<ans.size()<<endl;
		return;
	}
	int mid=k5+k6>>1;
	int size=t[t[k1].l].size+t[t[k2].l].size-t[t[k3].l].size-t[t[k4].l].size;
	if (size) getans(t[k1].l,t[k2].l,t[k3].l,t[k4].l,k5,mid,k7);
	if (size<k7) getans(t[k1].r,t[k2].r,t[k3].r,t[k4].r,mid+1,k6,k7-size);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	for (int i=1;i<=m;i++){
		int k1; scanf("%d",&k1); A[k1].push_back(i);
	}
	len=0; root[0]=0;
	dfs(1,0);
//	for (int i=1;i<=n;i++) cout<<t[root[i]].size<<" "; cout<<endl;
	for (int i=1;i<=16;i++)
		for (int j=1;j<=n;j++) father[j][i]=father[father[j][i-1]][i-1];
	for (;q;q--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		int k4=getfather(k1,k2); ans.clear();
		getans(root[k1],root[k2],root[k4],root[father[k4][0]],1,m,k3);
		printf("%d ",ans.size());
		for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); printf("\n");
	}
	return 0;
}