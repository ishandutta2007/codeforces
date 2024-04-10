#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200000
#define ll long long
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
bool cmp(int p,int q){
	return p>q;
}
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
ll lcm(int a,int b){
	return 1ll*a/gcd(a,b)*b;
}
int p[Maxn+5];
int n;
int x,a,y,b;
ll k;
ll sum[Maxn+5];
int main(){
	int t;
	read(t);
	int ans;
	ll now;
	int tmp_1,tmp_2,tmp_3;
	ll l;
	while(t--){
		read(n);
		for(int i=1;i<=n;i++){
			read(p[i]);
		}
		read(x),read(a);
		read(y),read(b);
		read(k);
		sort(p+1,p+1+n,cmp);
		if(x<y){
			swap(x,y);
			swap(a,b);
		}
		ans=-1;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+p[i];
		}
		l=lcm(a,b);
		for(int i=1;i<=n;i++){
			tmp_1=i/l;
			tmp_2=i/a-tmp_1;
			tmp_3=i/b-tmp_1;
			now=sum[tmp_1]/100*(x+y)+(sum[tmp_1+tmp_2]-sum[tmp_1])/100*x+(sum[tmp_1+tmp_2+tmp_3]-sum[tmp_1+tmp_2])/100*y;
			if(now>=k){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}