#include <cstdio>
#include <algorithm>

int n,a[2000001],s[2000001];
int f[2000001],g[2000001];
long long ans=100000000000000000ll;
int cnt=0;
bool empty(int l,int r){
	// cnt++;
	// printf("empty %d %d %d %d\n",l,r,s[r],s[l-1]);
	if(l>2000000||r<1)return 1;
	if(r>2000000)r=2000000;
	if(l<1)l=1;
	return s[r]==s[l-1];
}
void check(int i,int j){
	long long k=1ll*j*j-i;
	// if(j<=3)printf("%lld %d\n",k,j);
	if(k<=0||k>=ans)return;
	for(int l=j,now=i;now>0&&l>=1;now-=(2*l-1),--l){
		// if(j<=3)printf("check %d %d\n",l,now);
		if(!empty(now-l+1,now-1))return;
	}
	for(int l=j+1,now=i+(j*2+1);;++l,now+=(2*l-1)){
		// if(j<=3)printf("check %d\n",l);
		if(!empty(now-l+1,now-1))return;
		if(now>2000000)break;
	}
	ans=k;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i),s[a[i]]=1;
	int j=1;
	for(int i=1;i<=2000000;++i){
		if(i==j*j){
			g[i]=i;
			++j;
		}
		else g[i]=g[i-1];
	}
	for(int i=2000000;i;--i){
		f[i]=j*j;
		if(i==(j-1)*(j-1))--j;
	}
	bool can=1;
	for(int i=1;i<=n;++i){
		// printf("%d %d %d\n",a[i],g[a[i]],f[a[i]]);
		if(a[i]-g[a[i]]>=f[a[i]]-a[i])can=0;
	}
	if(can){
		puts("0");
		return 0;
	}
	for(int i=1;i<=2000000;++i)s[i]+=s[i-1];
	// for(int i=1;i<=10;++i)printf("%d ",s[i]);
	for(int i=1;i<=2000000;++i)check(a[1],i);
	for(int i=2;i<=n;++i)
		for(int j=1;j<=a[i]-a[i-1];++j)
			check(a[i],j);
	printf("%lld\n",ans);
	// printf("%d\n",cnt);
}