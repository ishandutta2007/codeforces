#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct bian{
	int next,point;
	long long w;
}b[410000];
const int mo=1e9+7;
long long A[210000],w[110000];
int len,n,m,p[110000],pd[110000],size;
vector<int>go;
void ade(int k1,int k2,long long k3){
	b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1,int k2,long long k3){
	ade(k1,k2,k3); ade(k2,k1,k3);
}
void dfs(int k1){
	pd[k1]=1; size++; go.push_back(k1);
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]){
			if (k1<j) A[++len]=b[i].w^w[k1]^w[j];
		} else w[j]=w[k1]^b[i].w,dfs(j);
	}
}
int gauss(){
//	cout<<"asd"<<endl;
//	for (int i=1;i<=len;i++) cout<<A[i]<<" "; cout<<endl;
	int now=1,ans=1;
	for (int i=62;i>=0;i--){
		int where=0;
		for (int j=now;j<=len;j++) if (A[j]&(1ll<<i)) where=j;
		if (where==0) continue;
		ans=ans*2%mo;
		swap(A[now],A[where]);
		for (int j=now+1;j<=len;j++)
			if (A[j]&(1ll<<i)) A[j]^=A[now];
		now++;
	}
	len=now-1;
//	cout<<"fin"<<endl;
//	for (int i=1;i<=len;i++) cout<<A[i]<<" "; cout<<endl;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k1,k2; long long k3; scanf("%d%d%I64d",&k1,&k2,&k3);
		add(k1,k2,k3);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		if (pd[i]==0){
			size=0; len=0; go.clear();
			dfs(i); int k1=gauss();
		//	cout<<k1<<endl;
		//	for (int i=1;i<=len;i++) cout<<A[i]<<" "; cout<<endl;
			for (int now=0;now<=60;now++){
				int flag=0;
				for (int j=1;j<=len;j++) if (A[j]&(1ll<<now)) flag++;
				if (flag){
					ans=(ans+1ll*size*(size-1)/2%mo*k1%mo*(mo+1)/2%mo*((1ll<<now)%mo))%mo;
				//	cout<<ans<<endl;
					continue;
				}
				int num=0;
				for (int j=0;j<size;j++) if (w[go[j]]&(1ll<<now)) num++;
			//	cout<<now<<" "<<num<<" "<<size-num<<endl;
				ans=(ans+1ll*num*(size-num)%mo*k1%mo*((1ll<<now)%mo))%mo;
			//	cout<<ans<<endl;
			}
		}
	cout<<(ans+mo)%mo<<endl;
	return 0;
}