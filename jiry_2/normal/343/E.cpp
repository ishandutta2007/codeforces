#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct bian{
	int next,point,f;
}b[3000];
queue<int>Q;
int p[300],len,dst[300],w[300][300],sign,pd[300],n,m,A[300],inf=1e8,s,t,numans,B[3000];
vector<int>ans;
void ade(int k1,int k2,int k3){
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len; B[len]=b[len].f;
}
void add(int k1,int k2,int k3){
	ade(k1,k2,k3); ade(k2,k1,k3);
}
int change(int k1,int k2){
	if (k1==t||k2==0) return k2;
	int num=0;
	for (int i=p[k1];i!=-1;i=b[i].next){
		int j=b[i].point; 
		if (b[i].f&&dst[j]==dst[k1]+1){
			int k=change(j,min(b[i].f,k2));
			b[i].f-=k; b[i^1].f+=k; num+=k; k2-=k;
			if (k2==0) break;
		}
	}
	if (num==0) dst[k1]=-1; return num;
}
int bfs(){
	memset(dst,0xff,sizeof dst); dst[s]=0; while (!Q.empty()) Q.pop();
	memset(pd,0x00,sizeof pd); pd[s]=1; Q.push(s);
	while (!Q.empty()){
		int k=Q.front(); 
		for (int i=p[k];i!=-1;i=b[i].next){
			int j=b[i].point;
			if (b[i].f&&pd[j]==0){
				dst[j]=dst[k]+1; pd[j]=1; 
				if (j==t) return 1; Q.push(j); 
			}
		}
		Q.pop();
	}
	return pd[t];
}
int dinic(){
	for (int i=0;i<=len;i++) b[i].f=B[i];
	int num=0;
	while (bfs()) num+=change(s,inf);
	return num;
}
void dfss(int k){
	pd[k]=1;
	for (int i=p[k];i!=-1;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0&&b[i].f) dfss(j);
	}
}
void dfs(int k){
//	cout<<k<<endl;
	s=0; for (int i=1;i<=n;i++) if (A[i]==k){s=i; break;}
	t=0; for (int i=s+1;i<=n;i++) if (A[i]==k){t=i; break;}
	if (!t) return;
//	cout<<s<<" "<<t<<endl;
	int ans=dinic(); memset(pd,0x00,sizeof pd); dfss(s); //cout<<ans<<endl; for (int i=1;i<=n;i++) cout<<pd[i]<<" "; cout<<endl;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (pd[i]&&pd[j]==0){w[i][j]=min(w[i][j],ans); w[j][i]=min(w[j][i],ans);}
	sign++;
	for (int i=1;i<=n;i++) if (pd[i]&&A[i]==k) A[i]=sign; dfs(sign); dfs(k);
}
void findans(vector<int>S){
	if (S.size()==1){ans.push_back(S[0]); return;} int num=inf;
	for (int i=0;i<S.size();i++)
		for (int j=i+1;j<S.size();j++)
			num=min(w[S[i]][S[j]],num);
	memset(pd,0x00,sizeof pd);
	Q.push(S[0]); pd[S[0]]=1;
	while (!Q.empty()){
		int k=Q.front();
		for (int i=0;i<S.size();i++)
			if (pd[S[i]]==0&&w[k][S[i]]>num){Q.push(S[i]); pd[S[i]]=1;}
		Q.pop();
	}
	vector<int>S1,S2;
	for (int i=0;i<S.size();i++) if (pd[S[i]]) S1.push_back(S[i]); else S2.push_back(S[i]);
	findans(S1); findans(S2); numans+=num;
}
int main(){
	scanf("%d%d",&n,&m); len=-1; memset(p,0xff,sizeof p);
	memset(w,0x3f,sizeof w);
	for (int i=1;i<=m;i++){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); add(k1,k2,k3);
	}
	sign=0; dfs(0); 
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++) cout<<w[i][j]<<" "; cout<<endl;
//	}
	vector<int>S; numans=0;
	for (int i=1;i<=n;i++) S.push_back(i); findans(S);
	cout<<numans<<endl;
	for (int i=0;i<n;i++) cout<<ans[i]<<" "; cout<<endl; return 0;
}