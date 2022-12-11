#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,m,I[1100000],pre[1100000],w1[1100000],w2[1100000],Key[1100000],num[1100000],a[1100000];
vector<int>A[110000];
const int mo=1e9+7;
const int mo1=1e9+7,key1=998244353;
const int mo2=1e9+9,key2=1e9+7;
void get(int mo,int key,int *w){
	for (int i=1;i<=m;i++) pre[i]=0,w[i]=0;
	Key[0]=1; for (int i=1;i<=n;i++) Key[i]=1ll*Key[i-1]*key%mo;
	for (int i=1;i<=n;i++){
		for (int j=0;j<A[i].size();j++) num[A[i][j]]=0; 
		for (int j=0;j<A[i].size();j++) num[A[i][j]]++;
		for (int j=0;j<A[i].size();j++){
			int k1=A[i][j];
			if (pre[k1]!=i){
				w[k1]=(1ll*w[k1]*Key[i-pre[k1]]+num[k1])%mo;
				pre[k1]=i;
			}
		}
	}
	for (int i=1;i<=m;i++)
		w[i]=1ll*w[i]*Key[n-pre[i]]%mo;
}
int compare(int k1,int k2){
	return w1[k1]<w1[k2]||(w1[k1]==w1[k2]&&w2[k1]<w2[k2]);
}
int main(){
	scanf("%d%d",&n,&m);
	I[0]=1; for (int i=1;i<=m;i++) I[i]=1ll*I[i-1]*i%mo;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); 
		for (;k1;k1--){
			int k2; scanf("%d",&k2); A[i].push_back(k2);
		}
	}
	get(mo1,key1,w1);
	get(mo2,key2,w2);
//	for (int i=1;i<=m;i++) cout<<w1[i]<<" "; cout<<endl;
//	for (int i=1;i<=m;i++) cout<<w2[i]<<" "; cout<<endl;
	for (int i=1;i<=m;i++) a[i]=i;
	sort(a+1,a+m+1,compare);
	int pre=1,ans=1;
	for (int i=2;i<=m+1;i++){
		if (i==m+1||w1[a[i]]!=w1[a[i-1]]||w2[a[i]]!=w2[a[i-1]]){
			ans=1ll*ans*I[i-pre]%mo;
			pre=i;
		}
	}
	cout<<ans<<endl;
}