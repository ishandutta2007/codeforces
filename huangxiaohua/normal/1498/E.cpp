#include<bits/stdc++.h>
using namespace std;

struct sb{
	int a,b;
}s[505];
bool cmp(sb x,sb y){return x.a<y.a;}
int i,j,k,n,m,t,sb,mx,mn,res,ans[2];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		s[i].a=k;s[i].b=i;
	}
	sort(s+1,s+n+1,cmp);
	for(i=1;i<=n;i++){
		j++;sb+=s[i].a;
		if((j*j-j)/2==sb){
			if(j>1){
				mx=mn=i;
				for(k=i;k>=i-j+1;k--){
					if(s[mx].a<=s[k].a){mx=k;}
					if(s[mn].a>s[k].a){mn=k;}
				}
				if(s[mx].a-s[mn].a>=res){res=s[mx].a-s[mn].a;ans[0]=s[mx].b;ans[1]=s[mn].b;}
			}
			for(k=i+1;k<=n;k++){s[k].a-=j;}
			j=sb=0;
		}
	}
	printf("! %d %d",ans[0],ans[1]);
}