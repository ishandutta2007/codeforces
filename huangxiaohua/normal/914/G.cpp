#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
#define M 1000000007

const int N=(1<<19)+10,p=1000000007;
struct FWT{
	int n=17,a[N],b[N],ta[N],tb[N],i,j;
	void FWTxor(int a[],long long type){
	    int i,j,k,x,y;
	    for(i=1;i<=n;i++)
	    for(j=0;j<(1<<n);j+=1<<i)
	    for(k=0;k<(1<<i-1);k++)
	    x=(a[j|k]+a[j|(1<<i-1)|k])*type%p,
	    y=(a[j|k]-a[j|(1<<i-1)|k]+p)*type%p,
	    a[j|k]=x,a[j|(1<<i-1)|k]=y;
	}
	void FWTand(int a[],long long type)
	{
	    int i,j,k;
	    for(i=1;i<=n;i++)
	    for(j=0;j<(1<<n);j+=1<<i)
	    for(k=0;k<(1<<i-1);k++)
	    (a[j|k]+=(a[j|(1<<i-1)|k]*type+p)%p)%=p;
	}
	void FWTor(int a[],int type)
	{
	    int i,j,k;
	    for(i=1;i<=n;i++)
	    for(j=0;j<(1<<n);j+=1<<i)
	    for(k=0;k<(1<<i-1);k++)
	    (a[j|(1<<i-1)|k]+=(a[j|k]*type+p)%p)%=p;
	}
	void work_xor(){
		memcpy(ta,a,sizeof a);memcpy(tb,b,sizeof b);
	    FWTxor(ta,1);FWTxor(tb,1);
	    for(i=0;i<(1<<n);i++)ta[i]=(long long)ta[i]*tb[i]%p;
	    FWTxor(ta,(p+1)>>1);
	}
	
	void work_and(){
		memcpy(ta,a,sizeof a);memcpy(tb,b,sizeof b);
	    FWTand(ta,1);FWTand(tb,1);
	    for(i=0;i<(1<<n);i++)ta[i]=(long long)ta[i]*tb[i]%p;
	    FWTand(ta,-1);
	}
	
	void work_or(){
	    memcpy(ta,a,sizeof a);memcpy(tb,b,sizeof b);
	    FWTor(ta,1);FWTor(tb,1);
	    for(i=0;i<(1<<n);i++)ta[i]=(long long)ta[i]*tb[i]%p;
	    FWTor(ta,-1);
	}
}fwt;

int i,j,k,n,m,t;
ll a[5005000],b[500500],f1[500500],f2[500500],fb[500500];
ll su(ll a,ll b){
	a+=b;return (a>=M)?a-M:a;
}

void get(int x,int y){
	for(int i=y;;i=(i-1)&y){
		f1[x+i]=su(f1[x+i],b[x]*b[i]%M);
		if(!i)break;
	}
}

int main(){
	fb[0]=0;fb[1]=1;
	for(i=2;i<=300000;i++){
		fb[i]=su(fb[i-1],fb[i-2]);
	}
    cin.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>a[i];
    	b[a[i]]++;
    	
    	fwt.a[a[i]]++;
		fwt.b[a[i]]++;
	}
	fwt.work_xor();
	
	for(i=0;i<b(18);i++){
		f1[i]=b[i]*fb[i]%M;
		f2[i]=fwt.ta[i]*fb[i]%M;
		fwt.a[i]=f1[i];
		fwt.b[i]=f2[i];
	}
	fwt.work_and();
	
	memset(f1,0,sizeof(f1));
	for(i=0;i<b(18);i++){
		f2[i]=fwt.ta[i];
	}
	
	for(i=0;i<b(18);i++){
		k=(131071^i);
		get(i,k);
	}
	
	for(i=0;i<b(18);i++){
		f1[i]=f1[i]*fb[i]%M;
		fwt.a[i]=f1[i];
		fwt.b[i]=f2[i];
	}
	
	fwt.work_and();
	
	ll res=0;
	for(i=1;i<=17;i++){
		res+=fwt.ta[b(i)];
	}
	cout<<res%M;
}