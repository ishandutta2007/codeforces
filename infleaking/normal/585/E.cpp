#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10,mo=1e9+7;
int cnt[N],la[N],s[N],p[N/10],p1,n,miu[N],M;
long long pw[N],ans;
bool flag[N];
vector<int> q;
void dfs(int x,int p,int w){
	if (x==q.size()){
		s[p]+=w;
		return;
	}
	dfs(x+1,p,w);
	dfs(x+1,p*q[x],w);
}
int main(){
	cin>>n;
	pw[0]=1;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
		pw[i]=pw[i-1]*2%mo;
	}M=1e7;
	for (int i=2;i<=M;i++){
		if (!flag[i]){
			p[++p1]=i;
			miu[i]=-1;
			la[i]=i;
		}
		for (int j=1;j<=p1;j++){
			int x=i*p[j];
			if (x>M)break;
			flag[x]=1;
			la[x]=p[j];
			if (i%p[j]==0){
				miu[x]=0;
				break;
			}
			miu[x]=-miu[i];
		}
	}
	for (int i=M;i>1;i--){
		if (!cnt[i])continue;
		int x=i,y=1;
		while (x>1){
			y*=la[x];
			int z=la[x];
			while (x%z==0)x/=z;
		}
		if (y<i)cnt[y]+=cnt[i],cnt[i]=0;
		else {
			q.clear();
			for (;y>1;y/=la[y])q.push_back(la[y]);
			dfs(0,1,cnt[i]);
		}
	}
	for (int i=2;i<=M;i++)
		ans=(ans-miu[i]*(pw[s[i]]-1)*(n-s[i]))%mo;
	cout<<(ans%mo+mo)%mo<<endl;
}