#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include<vector>
#include <ctime>
#include <algorithm>
using namespace std;
struct bian{
	int next,point;
}b[410000];
int n,p[210000],len,size[210000],where,now,A[210000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
	size[k1]=1; int num=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			dfs(j,k1); num=max(num,size[j]); size[k1]+=size[j];
		}
	}
	num=max(num,n-size[k1]);
	A[k1]=num;
}
struct atom{
	int x,y,aim;
	void print(){
		printf("%d %d %d\n",x,y,aim);
	}
};
vector<atom>ans;
int pre=0;
int getans(int k1,int k2,int aim,int root){
	if (root!=k1){
		ans.push_back((atom){aim,pre,k1});
		ans.push_back((atom){k1,k2,root});
		pre=k1;
	}
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2) getans(j,k1,aim,root);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		add(k1,k2);
	}
	int m=0; dfs(1,0);
	for (int now=1;now<=n;now++)
		if (A[now]<=n/2)
			for (int i=p[now];i;i=b[i].next){
				int j=b[i].point; pre=j;
				//cout<<"fa "<<now<<" "<<j<<" "<<A[j]<<endl;
				if (A[j]>n/2){
					getans(j,now,now,j); ans.push_back((atom){now,pre,j});
				}
			}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<ans.size();i++) ans[i].print();
	return 0;
}