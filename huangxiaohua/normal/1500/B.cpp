#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,a[500500],b[500500],c[1005000],d[1005000],no;
ll k,sb,sb1,chk,res,ans,tmp;
vector<ll> v;

ll A[10],B[10],SB=1,r;
ll x,y;

void exgcd(ll a,ll b,ll c){
	if(!b){
		if(c%a){no=1;}
		else{x=c/a,y=0;no=0;}return;
	}
	exgcd(b,a%b,c);
	ll xx=y,yy=x-a/b*y;x=xx,y=yy;return;
}

ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}

ll mul(ll a,ll b,ll mod)
{
    ll res=0;
    while(b>0)
    {
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}

ll excrt(int n){
	ll t1=B[1],t2=A[1];
	ll tmp;
	for(int i=1;i<=n-1;i++){
		exgcd(t2,-A[i+1],B[i+1]-t1);
		tmp=t2;
		tmp=tmp*x+t1;
		t2=t2/gcd(t2,A[i+1])*A[i+1];
		tmp=tmp%t2+t2;
		tmp%=t2;
		t1=tmp;
	}
	return t1;
}

void get(){
	ll l=1,r=sb,md,tmp,ans=sb;
	while(l<=r){
		md=(l+r)>>1;
		tmp=upper_bound(v.begin(),v.end(),md)-v.begin();
		tmp=md-tmp;
		//printf("%d %d %d\n",md,tmp,chk);
		if(tmp>=chk){if(tmp==chk){
				ans=min(ans,md);
			}r=md-1;}
		else{
			
			l=md+1;
		}
	}
	res+=ans;
}

int main(){
	scanf("%d%d%lld",&n,&m,&k);
	
	
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]=i;
	}
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
		d[b[i]]=i;
	}
	sb=sb1=(ll)n*m/__gcd(n,m);
	for(i=1;i<=1000000;i++){
		if(c[i]&&d[i]){
			A[1]=n;B[1]=c[i];
			A[2]=m;B[2]=d[i];
			no=0;
			tmp=excrt(2);
			if(!tmp){tmp=sb;}
			//printf("%d %d %d %d %lld\n",n,B[1],m,B[2],tmp);
			if(no){continue;}
			v.push_back(tmp);
			sb1--;
		}
	}
	sort(v.begin(),v.end());
	//for(auto i:v){printf("%d ",i);}puts("");
	
	res+=(k/sb1)*sb;
	//printf("d%d\n",res);
	if((k%sb1)==0){
		res-=sb;
		chk=sb1;
	}
	else{
		chk=k%sb1;
	}
	get();
	printf("%lld",res);
}