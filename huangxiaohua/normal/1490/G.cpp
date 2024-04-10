#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t,a[200500],m,ans[200500],it;
ll k,b,k2,res,k3;
struct sb{
	ll num;
	int id;
	bool operator<(const sb x)const{return (x.num==num)?id>x.id:num<x.num;}
}s[200500],tmp;

int main(){
	scanf("%d",&t);
	tmp.id=1145141919;
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			s[i].id=i;
			s[i].num=s[i-1].num+a[i];
		}
		b=s[n].num;
		sort(s+1,s+n+1);
		ans[n+1]=11451419;
		for(i=n;i>=1;i--){
			ans[i]=min(ans[i+1],s[i].id);
		}
		for(i=1;i<=m;i++){
			scanf("%lld",&k);
			res=0;
			if(b<=0){
				tmp.num=k;
				if(k>s[n].num){printf("-1 ");}
				else{
					it=lower_bound(s+1,s+n+1,tmp)-s;
					printf("%d ",ans[it]-1);
				}
			}
			else{
				k2=k-s[n].num;
				if(k2>0){
					k3=(k2/b);
					if(k2%b){k3++;}
					res=k3*n;
					k-=b*k3;
				}
				tmp.num=k;
				it=lower_bound(s+1,s+n+1,tmp)-s;
				printf("%lld ",res+ans[it]-1);
			}
		}
		puts("");
	}
}