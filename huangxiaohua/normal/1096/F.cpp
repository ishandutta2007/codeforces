#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,pos[200500],a[200500],b[200500],sb[200500],it,f[200500];
ll res1,res2,res3,sb1,sb2,sb3,jc=1;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

void add(int x){
	for(;x<=n;x+=(-x&x)){f[x]++;}
}

int get(int x,int y=0){
	for(;x;x-=(-x&x)){y+=f[x];}return y;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);sb[i]=k;
		a[i]=a[i-1];
		if(k!=-1){pos[k]=i;}
		else{m++;a[i]++;}	
	}
	for(i=n;i>=1;i--){
		b[i]=b[i+1];
		if(sb[i]==-1){b[i]++;}
	}
	if(!m){goto aaa;}
	res1=m*1ll*(m-1)%M*ksm(4,M-2)%M;
	for(i=1;i<=n;i++){
		if(!pos[i]){it++;continue;}
		sb1=a[pos[i]];
		sb2=b[pos[i]];
		//printf("a%d %d %d %d\n",sb1,sb2,it,m);
		sb3=sb1*(m-it)+sb2*it;
		res2+=sb3;res2%=M;
	}
	res2=res2*ksm(m,M-2)%M;
	aaa:;
	for(i=n;i>=1;i--){
		if(!pos[i]){continue;}
		res3+=get(pos[i]);
		add(pos[i]);
	}
	//printf("%lld %lld %lld\n",res1,res2,res3);
	res3+=res2+res1;res3%=M;
	printf("%lld",res3);
}