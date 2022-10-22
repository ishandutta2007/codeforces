#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n,m;
struct Question{
	int l,r;
}qu[Maxn+5];
char s[Maxn+5];
int f_max[Maxn+5],f_min[Maxn+5];
int b_max[Maxn+5],b_min[Maxn+5];
int pre_s[Maxn+5];
void solve(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int sum=0;
	f_max[0]=0;
	f_min[0]=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='+'){
			sum++;
		}
		else{
			sum--;
		}
		pre_s[i]=sum;
		f_max[i]=max(f_max[i-1],sum);
		f_min[i]=min(f_min[i-1],sum);
	}
	int all_sum=sum;
	sum=all_sum;
	b_max[n+1]=all_sum;
	b_min[n+1]=all_sum;
	for(int i=n;i>0;i--){
		if(s[i]=='+'){
			sum--;
		}
		else{
			sum++;
		}
		b_max[i]=max(b_max[i+1],sum);
		b_min[i]=min(b_min[i+1],sum);
	}
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		int num=pre_s[r]-pre_s[l-1];
		int ans_min=min(f_min[l-1],b_min[r+1]-num),ans_max=max(f_max[l-1],b_max[r+1]-num);
		printf("%d\n",(ans_max-ans_min+1));
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}