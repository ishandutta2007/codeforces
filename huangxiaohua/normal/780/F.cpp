#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,w;
ll len[66],res;
bitset<505> t1;

struct sb{
	bitset<505> b[505];
}z,f0[66],f1[66],dwz,f2;

sb operator *(sb x,sb y){
	int i,j;
	sb res;
	for(i=1;i<=n;i++){
		res.b[i].reset();
		for(j=1;j<=n;j++){
			z.b[i][j]=y.b[j][i];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			t1=x.b[i]&z.b[j];
			res.b[i][j]=(t1.count()>0);
		}
	}
	return res;
}

bool chk(sb &x){
	int i,it=0;
	for(i=1;i<=n;i++)it|=(x.b[i].count()>0);
	return it;
}

void get(sb s,int x,int y){
	if(x<0)return;
	sb s1=s*((!y)?f0[x]:f1[x]);
	if(chk(s1)){
		res+=len[x];
		get(s1,x,y^1);
	}
	else{
		get(s,x-1,y);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		dwz.b[i][i]=1;
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&j,&k,&w);
		if(!w)f0[0].b[j][k]=1;
		else f1[0].b[j][k]=1;
	}
	len[0]=1;
	for(i=0;i<=60;i++){
		f2=(dwz*f0[i])*f1[i];
		if(chk(f2)){
			f0[i+1]=f0[i]*f1[i];
			f1[i+1]=f1[i]*f0[i];
			len[i+1]=len[i]*2;
		}
		else{
			get(dwz,i,0);
			if(res>1e18) puts("-1");
			else printf("%lld",res);
			return 0;
		}
	}
	puts("-1");
}