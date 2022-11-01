#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=100005;
int n,a,b,c,X,Y,fc,cnt11,f[N],g[N];
char s[N];
bool use[N],ok[N];
LL solve(bool first0,bool ux,bool uy){
	LL cur=0,res=0;
	int rem11=cnt11,j=0,k=0,l=0;
	for(int i=0;i<fc;i++)g[i]=f[i]-1,use[i]=0;
	int gc=fc,x=0,y=0;
	if(ux&&X)x=X;
	else if(X>1)g[gc]=X-1,use[gc++]=1;
	if(uy&&Y)y=Y;
	else if(Y>1)g[gc]=Y-1,use[gc++]=1;
	for(int i=0;i<gc;i++)ok[i]=0;
	for(int i=first0;;i++){
		if(i&1){
			if(x)cur+=x==1?-c:a,x--;
			else if(y)cur+=y==1?-c:a,y--;
			else{
				while(j<gc&&!g[j])j++;
				if(rem11&&j<gc){
					g[j]--;
					cur+=a;
				}
				else{
					if(j<gc)res=std::max(res,cur+a);
					while(k<gc&&use[k])k++;
					if(k<gc&&!g[k]){
						use[k]=1;
						ok[k]=1;
						cur-=c;
					}
					else return res;
				}
			}
		}
		else{
			if(rem11){
				rem11--;
				cur+=b;
			}
			else{
				while(l<gc&&!ok[l])l++;
				if(l==gc)return res;
				ok[l]=0;
				cur+=b;
			}
		}
		res=std::max(res,cur);
	}
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
		for(int i=1;i<=n;i++)s[i]-='0';
		int l=1,r=n;
		while(l<=n&&s[l]==0)l++;
		if(l>n){
			if(n==1)puts("0");
			else printf("%d\n",a);
			continue;
		}
		while(s[r]==0)r--;
		int seg0=0;
		fc=cnt11=0;
		for(int i=l;i<=r;i++){
			if(s[i]&&s[i+1])cnt11++;
			if(!s[i]){
				seg0++;
				if(s[i+1]){
					f[fc++]=seg0;
				}
			}
			else{
				seg0=0;
			}
		}
		std::sort(f,f+fc);
		X=l-1,Y=n-r;
		LL ans=0;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++){
			ans=std::max(ans,solve(i,j,k));
		}
		printf("%lld\n",ans);
	}
}