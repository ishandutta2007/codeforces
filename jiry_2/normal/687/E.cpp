#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct bian{
	int next,point;
}b[6000];
int p[6000],n,m,len,pd[6000],in[6000],s[6000],head,dfs[6000],low[6000],num[6000],sign,now,w[6000],bo[6000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void dfs1(int k1){
	s[++head]=k1; pd[k1]=1; in[k1]=1; dfs[k1]=++sign; low[k1]=sign;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0){
			dfs1(j); low[k1]=min(low[k1],low[j]);
		} else if (in[j]) low[k1]=min(low[k1],dfs[j]);
	}
	if (low[k1]==dfs[k1]){
		now++;
		while (s[head+1]!=k1){
			in[s[head]]=0; num[s[head]]=now; head--;
		}
	}
}
queue<int>Q;
int get(int k){
	memset(bo,0x00,sizeof bo); 
	while (!Q.empty()) Q.pop(); Q.push(k);
	bo[k]=1;
	while (!Q.empty()){
		int k1=Q.front();
		for (int i=p[k1];i;i=b[i].next){
			int j=b[i].point;
			if (bo[j]==0){
				bo[j]=bo[k1]+1; Q.push(j);
			} else if (j==k) return bo[k1];
		}
		Q.pop();
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (;m;m--){
		int k1,k2; scanf("%d%d",&k1,&k2); ade(k1,k2);
	}
	for (int i=1;i<=n;i++) if (pd[i]==0) dfs1(i);
	memset(pd,0x00,sizeof pd);
	for (int k=1;k<=n;k++)
		for (int i=p[k];i;i=b[i].next){
			int j=b[i].point;
			if (num[k]!=num[j]) pd[num[k]]=1;
		}
	memset(w,0x3f,sizeof w);
	for (int i=1;i<=n;i++){
	//	cout<<i<<" "<<get(i)<<endl;
		w[num[i]]=min(w[num[i]],get(i));
	}
	int ans=n;
	for (int i=1;i<=now;i++)
		if (pd[i]==0&&w[i]){
			ans++; ans+=w[i]*998;
		}
	cout<<ans<<endl;
	return 0;
}