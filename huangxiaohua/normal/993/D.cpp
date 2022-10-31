#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,ty,mx2,it,su,num[66];
double l,r,md,res=1e18,sum,f[66][66],g[66][66];

struct sb{
	int a,b,d;
	double c;
	bool operator<(const sb x)const{
		if(a==x.a){return c>x.c;}
		return a>x.a;
	}
}s[66];

bool chk(double md){
	int i,j,k;double res=0;
	sum=0;
	for(i=1;i<=n;i++){
		s[i].c=s[i].a-s[i].b*md;
		sum+=s[i].c;
	}
	sort(s+1,s+n+1);
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	it=0;
	for(i=1;i<=n;i++){
		if(s[i].a==s[i-1].a){it++;}
		else{it=1;}
		g[s[i].d][it]=g[s[i].d][it-1]+s[i].c;
	}
	su=0;
	//cout<<s[1].d<<endl;
	for(i=s[1].d-1;i>=1;i--){
		su+=num[i+1];
		for(j=0;j<=n;j++){
			for(k=0;k<=num[i];k++){
				if(k+j+j>su){continue;}
				f[i][k+j]=max({f[i][k+j],f[i+1][j]+g[i][k]});
			}
		}
	}
	
	for(i=0;i<=n;i++){
		res=max(res,f[1][i]);
	}
	//printf("a%lf %lf\n",md,sum-res);
	return (sum-res-1e-8)<=0;
}

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    	scanf("%d",&s[i].a);
	}
	for(i=1;i<=n;i++){
    	scanf("%d",&s[i].b);
	}
	sort(s+1,s+n+1);
	for(i=n;i>=1;i--){
		if(s[i].a!=s[i+1].a){it++;}
		s[i].d=it;
		num[it]++;
	}
	l=0;r=1e9;
	t=200;
	while(t--){
		md=(l+r)/2;
		if(chk(md)){r=md;res=min(res,md);}
		else{l=md;}
	}
	//printf("%.10lf\n",res*1000);
	res*=1000;
	printf("%lld",(ll)ceil(res));
}