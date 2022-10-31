#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,f[2050],g[2050],sb[100500],tmp,res[2050],x[2050],y[2050],ans[2050],mx,cost;
int r1,r2,r3;
struct SB{
	int a,c,id;
	bool operator<(const SB x)const{
		return c<x.c;
	}
}s[100500];

void get(int sb){
	int i,j,k;
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	r1=r2=f[0]*2;
	for(i=1;i<=n;i++){
		if((s[i].a&sb)==sb){
			for(j=1;j<=n;j++){
				if(i==j){continue;}
				//printf("%d %d\n",i,j);
				r1=min(r1,s[i].c+s[j].c);break;
			}break;
		}
	}
	for(i=1;i<=n;i++){
		f[s[i].a&sb]=g[s[i].a&sb]=min(f[s[i].a&sb],s[i].c);
	}
	for(i=510;i>0;i--){
		for(j=1;j<=9;j++){
			if(!(i&b(j))){
				g[i]=min(g[i],g[i+b(j)]);
			}
		}
	}
	for(i=1;i<511;i++){
		if((i|sb)!=sb){continue;}
		if(f[i]>1e9||g[sb^i]>1e9)continue;
		tmp=f[i]+g[sb^i];
		if(tmp<r2){
			r2=tmp;
			r3=i;
		}
	}
	int r4=r3;
	for(i=1;i<=n;i++){
		if(f[r3]==s[i].c&&(s[i].a&sb)==r3){r3=i;break;}
	}
	
	res[sb]=min(r1,r2);
	if(r1>2e9&&r2>2e9){
		return;
	}
	
	//printf("nmsl %d %d %d %d %d\n",sb,r1,r2,r3,r4);
	//printf("%d %d\n",s[r3].a,s[r3].c);
	if(r1<r2){
		for(i=1;i<=n;i++){
			if((s[i].a&sb)==sb){
				for(j=1;j<=n;j++){
					if(i==j){continue;}
					x[sb]=s[i].id;y[sb]=s[j].id;return;
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		if(r3==i){continue;}
		if((s[i].c+s[r3].c==r2)&&((s[i].a|s[r3].a)&sb)==sb){
			x[sb]=s[i].id;y[sb]=s[r3].id;return;
		}
	}
}

int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++){
		scanf("%d",&k);
		tmp=0;
		while(k--){
			scanf("%d",&j);tmp|=b(j);
		}
		sb[i]=tmp;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&s[i].c);
		scanf("%d",&k);
		tmp=0;
		while(k--){
			scanf("%d",&j);
			tmp|=b(j);
		}
		s[i].a=tmp;
		s[i].id=i;
	}
	sort(s+1,s+n+1);
	for(i=1;i<=511;i++){
		get(i);
		if(res[i]<=2e9){
			//printf("%d %d %d %d\n",i,res[i],x[i],y[i]);
		}
	}
	res[0]=s[1].a+s[2].a;
	x[0]=s[1].id;y[0]=s[2].id;
	
	for(i=1;i<=511;i++){
		if(res[i]>2e9){continue;}
		for(j=1;j<=m;j++){
			if((sb[j]&i)==sb[j]){
				ans[i]++;
			}
		}
		mx=max(mx,ans[i]);
	}
	cost=0x7fffffff;
	for(i=0;i<=511;i++){
		if(ans[i]==mx){
			cost=min(cost,res[i]);
		}
	}
	//cout<<cost<<' '<<mx<<endl;
	for(i=0;i<=511;i++){
		if(ans[i]==mx&&cost==res[i]){
			//cout<<i<<endl;
			printf("%d %d",x[i],y[i]);return 0;
		}
	}
}