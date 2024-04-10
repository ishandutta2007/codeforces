#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int>vec[200001];
int n,dis[200001],f[200001];
const int P=1000000007;
inline int add(int a,const int &b){return (a+=b,(a>=P)?a-P:a);}
struct point{
	int out,in;
}num[200001];
bool cmp(point a,point b){return a.in<b.in;}
inline void update(const int &x,const int &dis,const int &f){
	if(dis<::dis[x])::dis[x]=dis,::f[x]=f;
	else if(dis==::dis[x])::f[x]=add(::f[x],f);
}
inline int get(int x,int l){
	int r=n,mid,ans=n+1;
	while(l<=r){
		mid=(l+r)>>1;
		if(num[mid].in>=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&num[i].out,&num[i].in);
	std::sort(num+1,num+n+1,cmp);
	dis[0]=0x7f7f7f7f;
	for(int i=1;i<=n;i++){
		dis[i]=num[i].in;
		if(i==1)f[i]=1;
		if(i>1)update(i,dis[i-1]-num[i-1].in+num[i].in,f[i-1]);
		for(int k=0,now;k<vec[i].size();k++){
			now=vec[i][k];
			update(i,dis[now]-num[now].out+num[i].in,f[now]);
		}
		int j=get(num[i].out,i+1);
		if(j<=n)vec[j].push_back(i);
		else update(0,dis[i],f[i]);
	}
	printf("%d\n",f[0]);
}