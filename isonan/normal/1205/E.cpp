#include <cstdio>
#include <algorithm>
#include <vector>

int n,k;
const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int f[1000001],prime[1000001],top,cnt[1000001],mu[1000001],phi[1000001];
bool pri[1000001];
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
std::vector<int>Div[200001];
int get(int a,int b){
	int l=std::max(0,b-a-1),r=std::min(a,b-1);
	if(l>r)return 0;
	if(b-1<=r)return b==1?0:phi[b];
	int ans=0;
	for(int i=0,tem;i<Div[b].size();++i){
		tem=Div[b][i];
		if(tem>r)break;
		ans=add(ans,mul(mu[tem],(r/tem)-(l/tem)));
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
//	n=100000,k=1000000000;
	k%=P;
	mu[1]=phi[1]=1;
	for(int i=2;i<(n<<1);i++){
		if(!pri[i])prime[++top]=i,mu[i]=P-1,phi[i]=i-1;
		for(int j=1;j<=top&&i*prime[j]<(n<<1);j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
			mu[i*prime[j]]=P-mu[i];
		}
	}
	for(int i=1;i<(n<<1)-1;i++)
		for(int j=i;j<(n<<1)-1;j+=i)
			Div[j].push_back(i);
	k=qsm(k,P-2);
	int ans=0,v=1;
	for(int i=1;i<n;i++)
		for(int j=i;j<(n<<1)-1;j+=i)
			cnt[n-std::max(j-n,i)]=add(cnt[n-std::max(j-n,i)],get((n-1)/i,j/i));
	for(int i=0;i<n;i++)ans=add(ans,mul(cnt[i],v)),v=mul(v,k);
	printf("%d",ans);
}