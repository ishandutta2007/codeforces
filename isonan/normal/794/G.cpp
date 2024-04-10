#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

int n,clen,dlen,ca,cb,da,db,cque,dque;
int invmul[600001],_mul[600001],f[600001],g[600001],prime[600001],top,phi[600001];
char c[300001],d[300001];
bool pri[300001];
const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int get_same(){
	int tot=1;
	if(clen!=dlen)return 0;
	for(int i=1;i<=clen;i++)
		if(c[i]=='A'&&d[i]=='B')return 0;
		else if(c[i]=='B'&&d[i]=='A')return 0;
		else if(c[i]=='?'&&d[i]=='?')tot=mul(tot,2);
	return tot;
}
int C(int n,int m){return mul(mul(_mul[n],invmul[m]),invmul[n-m]);}
inline int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
int get(){
	for(int i=1;i<=n;i++)f[i]=qsm(n/i,2);
	for(int i=n;i;i--)
		for(int j=i+i;j<=n;j+=i)
			f[i]=sub(f[i],f[j]);
	int ans=0;
	for(int i=1;i<=n;i++)ans=add(ans,mul(qsm(2,i),f[i]));
	return ans;
}
signed main(){
	scanf("%s%s%I64d",c+1,d+1,&n);
	clen=strlen(c+1);
	dlen=strlen(d+1);
	int cnt=get_same(),ans=0;
	ans=add(ans,mul(cnt,qsm(sub(qsm(2,n+1),2),2)));
	_mul[0]=_mul[1]=invmul[0]=invmul[1]=1;
	for(int i=2;i<=clen+dlen;i++)_mul[i]=mul(_mul[i-1],i);
	for(int i=2;i<=clen+dlen;i++){
		invmul[i]=mul(P-P/i,invmul[P%i]);
		invmul[i]=mul(P-P/i,invmul[P%i]);
	}
	for(int i=2;i<=clen+dlen;i++)invmul[i]=mul(invmul[i],invmul[i-1]);
	for(int i=1;i<=clen;i++)
		if(c[i]=='A')++ca;
		else if(c[i]=='B')++cb;
	for(int i=1;i<=dlen;i++)
		if(d[i]=='A')++da;
		else if(d[i]=='B')++db;
	cque=clen-ca-cb;
	dque=dlen-da-db;
	for(int i=-dque;i<=cque;i++){
		int Da=ca+i-da,Db=clen-dlen-Da,cn=C(cque+dque,dque+i);
		if(Da*Db>0ll)continue;
		else if(Da==0ll||Db==0ll){
			if(Da+Db!=0ll)continue;
			cn=sub(cn,cnt);
			ans=add(ans,mul(cn,get()));
		}
		else{
			(Da<0ll)?Da=-Da:Db=-Db;
			int __gcd=gcd(Da,Db);
			Da/=__gcd,Db/=__gcd;
			int len=std::min(n/Da,n/Db);
			ans=add(ans,mul(cn,sub(qsm(2,len+1),2)));
		}
	}
	printf("%I64d\n",ans);
}