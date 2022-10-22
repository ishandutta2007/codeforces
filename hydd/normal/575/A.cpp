#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll k; ll p,n,m,s[51000],Log2[51000];
ll cnt; ll tmp[110000];
map<ll,ll> _s;
char Getchar(){
    static char now[1<<20],*S,*T;
    if (T==S){
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
ll read(){
    ll x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
struct Matrix{
	ll v[2][2];
	Matrix operator*(const Matrix &a) const{
		Matrix res;
		for (ll i=0;i<=1;i++)
			for (ll j=0;j<=1;j++){
				res.v[i][j]=0;
				for (ll k=0;k<=1;k++)
					res.v[i][j]+=v[i][k]*a.v[k][j];
				res.v[i][j]%=p;
			}
		return res;
	}
} I,b[51000][18],ans;
Matrix qpow(Matrix x,ll a){
    Matrix res=I;
    while (a){
        if (a&1) res=res*x;
        x=x*x; a>>=1;
    }
    return res;
}
ll getS(ll x){
	if (_s.count(x)) return _s[x];
	return s[(x+n)%n];
}
Matrix getM(ll x){
	Matrix res;
	res.v[0][0]=0; res.v[0][1]=getS(x-1);
	res.v[1][0]=1; res.v[1][1]=getS(x);
	return res;
}
Matrix query(ll l,ll r){
	if (l>r) return I;
	ll k=Log2[r-l+1];
	return b[l][k]*query(l+(1<<k),r);
}
int main(){
	I.v[0][0]=1; I.v[0][1]=0;
	I.v[1][0]=0; I.v[1][1]=1;
	k=read(); p=read(); n=read();
	for (ll i=0;i<n;i++) s[i]=read()%p;
	Log2[0]=-1;
	for (ll i=1;i<=n;i++) Log2[i]=Log2[i>>1]+1;
	m=read(); ll x,y;
	while (m--){
		x=read(); y=read();
		_s[x]=y;
		tmp[++cnt]=x; tmp[++cnt]=x+1;
	}
	for (ll i=0;i<n;i++) b[i][0]=getM(i);
	for (ll j=1;(1<<j)<n;j++)
		for (ll i=0;i+(1<<j)-1<n;i++)
			b[i][j]=b[i][j-1]*b[i+(1<<(j-1))][j-1];

	sort(tmp+1,tmp+cnt+1,greater<ll>());
	cnt=unique(tmp+1,tmp+cnt+1)-tmp-1;
	ans=I;
	for (ll p=0;p<k;){
		if (tmp[cnt]==p+1){
			ans=ans*getM(p+1);
			p++; cnt--;
		} else{
			ll l=p+1,r=k;
//			prllf("%lld %lld\n",l,r);
			if (cnt&&tmp[cnt]<=k) r=tmp[cnt]-1;
			if (l/n==r/n) ans=ans*query(l%n,r%n);
			else{
				ans=ans*query(l%n,n-1);
				ans=ans*qpow(query(0,n-1),r/n-l/n-1);
				ans=ans*query(0,r%n);
			}
			p=r;
		}
	}
	printf("%lld\n",ans.v[1][0]);
	return 0;
}