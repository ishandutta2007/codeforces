#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct bian{
	int next,point;
}b[410000];
int p[210000],len,n,d[210000],pd[210000],f[210000],u[210000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int w[210000];
vector<int>num,A[210000];
void reduce(vector<int>&A){
	for (int i=0;i<A.size();i++) w[A[i]]=0;
	for (int i=0;i<A.size();i++) w[A[i]]++;
	num=A; A.clear();
	for (int i=0;i<num.size();i++) if (w[num[i]]) A.push_back(num[i]),w[num[i]]=0;
}
void dfs(int k1,int k2){
	d[k1]=-1; pd[k1]=0;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			dfs(j,k1);
		}
	}
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			if (d[j]==-1) f[k1]++; else A[k1].push_back(d[j]+1);
		}
	}
	reduce(A[k1]);
	if (f[k1]||A[k1].size()>1) d[k1]=-1;
	else if (A[k1].size()==0) d[k1]=0;
	else d[k1]=A[k1][0]; 
//	cout<<k1<<" "<<k2<<" "<<d[k1]<<" "<<f[k1]<<endl; 
}
int ans=1e9;
int get(vector<int>A,int k1,int k2,int k3,int flag){
//	cout<<"get "<<endl;
//	for (int i=0;i<A.size();i++) cout<<A[i]<<" "; cout<<endl;
//	cout<<k1<<" "<<k2<<" "<<k3<<endl;
	if (A.size()>2) return -1;
	if (flag!=1) A.push_back(k1); 
//	for (int i=0;i<A.size();i++) cout<<A[i]<<" "; cout<<endl; cout<<k3<<endl;
	reduce(A);
	if (k2==-1) k3--; else {
		int flag=0; k2++;
		for (int i=0;i<A.size();i++)
			if (A[i]==k2){
				A.erase(A.begin()+i); flag=1; break;
			}
		if (flag==0) A.push_back(k2);
	}
//	for (int i=0;i<A.size();i++) cout<<A[i]<<" "; cout<<endl;
//	cout<<k3<<endl;
	if (k3||A.size()>1) return -1;
	if (A.size()==0) return 1;
	return A[0]+1;
}
void dfs2(int k1,int k2){
//	cout<<"fa "<<k1<<" "<<k2<<" "<<u[k2]<<endl;
	if (k1==1){
		int num=0;
		for (int i=0;i<A[k1].size();i++) num+=A[k1][i];
		if (A[k1].size()<=2&&f[k1]==0) ans=min(ans,num);
	} else if (u[k2]==-1) return;
	else {
		int tot=1+A[k1].size(),num=u[k2];
		for (int i=0;i<A[k1].size();i++) num+=A[k1][i];
		for (int i=0;i<A[k1].size();i++)
			if (u[k2]==A[k1][i]){
				tot--; num-=u[k2]; break;
			}
		if (tot<=2&&f[k1]==0) ans=min(ans,num);
	}
	if (A[k1].size()>2) return;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			u[k1]=get(A[k1],u[k2],d[j],f[k1],k1);
			dfs2(j,k1);
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		add(k1,k2);
	}
	dfs(1,0);
	dfs2(1,0);
	if (ans>1e8) ans=-1;
	cout<<ans<<endl;
	return 0;
}