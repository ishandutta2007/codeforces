#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct bian{
	int next,point;
}b[410000];
int n,p[210000],len,pd[210000],num[210000],w[210000],flag;
vector<int>ans;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void treedp(int k1,int k2){
	if (pd[k1]==-1) num[k1]=1,w[k1]=1; else num[k1]=0,w[k1]=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			treedp(j,k1);
			if (num[j]==0) continue;
			num[k1]+=num[j]; w[k1]^=1;
			if (w[j]==0) w[k1]^=1;
		}
	}
}
void getans(int k1,int k2){
	ans.push_back(k1);
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			if (num[j]==0) continue;
			getans(j,k1); ans.push_back(k1);
			if (w[j]==0) ans.push_back(j),ans.push_back(k1);
		}
	}
}
int main(){
	scanf("%d",&n); for (int i=1;i<=n;i++) scanf("%d",&pd[i]);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	treedp(1,0); 
	getans(1,0);
	if (w[1]==1){
		int k1=b[p[1]].point;
		ans.push_back(k1); ans.push_back(1); ans.push_back(k1);
	}
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}