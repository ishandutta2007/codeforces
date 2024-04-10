#include <cstdio>
#include <algorithm>

int n,k,a[100001],ave,ans,mx,Last[100001],len[100001],nxt[100001],val[100001];
struct point{
	int sum,ord;
}b[100001];
bool cmp(point a,point b){return a.sum<b.sum||(a.sum==b.sum&&a.ord<b.ord);}
void solve(int l,int r,long long res=0){
	int len=(l<=r)?r-l+1:(r-l+1+n);
//	printf("solve %d %d %d %lld\n",l,r,len,res);
	if(len==1)return;
	if(len<=k){
		printf("%d ",l);
		for(int i=0;i<len;i++){
			printf("%d ",a[(i+l)%n]=1ll*res*(i==0)+ave);
		}
		for(int i=len;i<k;i++)
			printf("%d ",a[(i+l)%n]);
		putchar('\n');
		return;
	}
	long long sum=0;
	for(int i=0;i<k;i++)
		sum+=a[(i+l)%n];
//	printf("%d %d\n",sum,res+1ll*(k-1)*ave);
	if(sum>=res+1ll*(k-1)*ave){
		printf("%d ",l);
		for(int i=0;i<k-1;i++)
			printf("%d ",a[(i+l)%n]=1ll*res*(i==0)+ave);
		printf("%d ",a[(k-1+l)%n]=sum-res-1ll*(k-1)*ave);
		putchar('\n');
		solve((l+k-1)%n,r,0);
		return;
	}
	else{
		solve((l+k-1)%n,r,len*ave+res-(len-k+1)*ave-sum+a[(l+k-1)%n]);
		printf("%d ",l);
		for(int i=0;i<k;i++)
			printf("%d ",a[(i+l)%n]=1ll*res*(i==0)+ave);
		putchar('\n');
		return;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i),ave+=a[i];
	ave/=n;
	for(int i=0;i<n;i++){
		b[i].sum=a[i]-ave;
		if(i)b[i].sum+=b[i-1].sum;
		b[i].ord=i;
	}
	mx=(n-1+k-1-1)/(k-1);
	std::sort(b,b+n,cmp);
	for(int i=0;i<=n;i++)val[i]=0x7f7f7f7f;
	for(int i=n%(k-1);i<=n;i+=k-1)
		if(i)val[i]=(n-i)/(k-1);
	for(int i=1;i<=n;i++)val[i]=std::min(val[i],val[i-1]);
	for(int i=0,last=0;i<n;i++)
		if(i==n-1||b[i+1].sum!=b[i].sum){
			for(int j=i;j>=last;j--){
				int u=(b[j].ord+1)%(k-1);
				nxt[b[j].ord]=Last[u];
				if(Last[u])len[b[j].ord]=len[Last[u]];
				++len[b[j].ord];
//				printf("%d %d %d %d\n",b[j].ord,nxt[b[j].ord],len[b[j].ord],val[len[b[j].ord]]);
				if(mx>val[len[b[j].ord]]){
					mx=val[len[b[j].ord]];
					ans=b[j].ord;
				}
				Last[b[j].ord%(k-1)]=b[j].ord;
			} 
			for(int j=i;j>=last;j--)Last[b[j].ord%(k-1)]=0;
			last=i+1;
		}
	printf("%d\n",mx);
	if(mx<(n-1+k-1-1)/(k-1)){
		int p=0;
		for(int i=n%(k-1);i<=n;i+=k-1)
			if(val[i]==mx)p=i;
		for(int i=ans;p;i=nxt[i],--p){
//			printf("%d\n",i);
			solve((i==n-1)?0:(i+1),nxt[i]?nxt[i]:ans);
		}
	}
	else solve(0,n-1);
}