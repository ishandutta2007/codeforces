#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
int pen[mn];
int a[mn],w[mn];
int num[mn],av[mn];
bool pr[mn];
ll ans=0;
struct comp{
	bool operator()(const int&a,const int&b)const{return 1LL*pen[a]*w[a]<1ll*pen[b]*w[b];}
};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	num[0]=m;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++)ans+=1LL*(pen[i]=(100-a[i]%100)%100)*w[i],num[i]=num[i-1]+pen[i];
	for(int i=1;i<=n;i++)num[i]/=100,num[i]=min(num[i],n);
	num[0]=0;
	priority_queue<int,vector<int>,comp>pq;
	for(int i=n;i>=1;i--){
		pq.push(i);
		for(int j=0;j<num[i]-num[i-1];j++){
			int x=pq.top();
			pq.pop();
			ans-=1LL*pen[x]*w[x];
			pr[x]=1;
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++){
		if(pr[i])printf("%d %d\n",a[i]/100,a[i]%100);
		else printf("%d %d\n",(a[i]+99)/100,0);
	}
}