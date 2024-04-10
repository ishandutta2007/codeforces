#include<bits/stdc++.h>

long long n,m,p,P,k,phi,pri[61],top;
std::vector<long long>ans;
using namespace std;
bool vis[10000001];
#define rg register
#define RP(i,a,b) for(register int i=a;i<=b;++i)
#define DRP(i,a,b) for(register int i=a;i>=b;--i)
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
typedef long long ll;
typedef double db;
#define lll __int128
template<class type_name> inline type_name qr(type_name sample)
{
    type_name ret=0,sgn=1;
    char cur=getchar();
    while(!isdigit(cur))
        sgn=(cur=='-'?-1:1),cur=getchar();
    while(isdigit(cur))
        ret=(ret<<1)+(ret<<3)+cur-'0',cur=getchar();
    return sgn==-1?-ret:ret;
}

ll max_factor;

inline ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

inline ll qp(ll x,ll p,ll mod)
{
    ll ans=1;
    while(p)
    {
        if(p&1)
            ans=(lll)ans*x%mod;
        x=(lll)x*x%mod;
        p>>=1;
    }
    return ans;
}

inline bool mr(ll x,ll b)
{
    ll k=x-1;
    while(k)
    {
        ll cur=qp(b,k,x);
        if(cur!=1 && cur!=x-1)
            return false;
        if((k&1)==1 || cur==x-1)
            return true;
        k>>=1;
    }
    return true;
}

inline bool prime(ll x)
{
    if(x==46856248255981ll || x<2)
        return false;
    if(x==2 || x==3 || x==7 || x==61 || x==24251)
        return true;
    return mr(x,2)&&mr(x,61);
}

inline ll f(ll x,ll c,ll n)
{
    return ((lll)x*x+c)%n;
}

inline ll PR(ll x)
{
    ll s=0,t=0,c=1ll*rand()%(x-1)+1;
    int stp=0,goal=1;
    ll val=1;
    for(goal=1;;goal<<=1,s=t,val=1)
    {
        for(stp=1;stp<=goal;++stp)
        {
            t=f(t,c,x);
            val=(lll)val*abs(t-s)%x;
            if((stp%127)==0)
            {
                ll d=gcd(val,x);
                if(d>1)
                    return d;
            }
        }
        ll d=gcd(val,x);
        if(d>1)
            return d;
    }
}

inline void fac(ll x)
{
    if(x<=max_factor || x<2)
        return;
    if(prime(x))
    {
        max_factor=max_factor>x?max_factor:x;
        return;		
    }
    ll p=x;
    while(p>=x)
        p=PR(x);
    while((x%p)==0)
        x/=p;
    fac(x),fac(p);
}

int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	P=m,k=1;
	for(int i=59;i>1;i--){
//		printf("%d\n",i);
		long long x=round(pow((double)m,1.0/(double)i));
		long long tem=1;
		for(int j=1;j<=i;j++)tem*=x;
		if(tem==m){
			P=x;
			k=i;
			break;
		}
	}
	phi=(m/P)*(P-1);
//	printf("%lld %lld\n",P,k);
	if(gcd(m,p)>1){
		if(phi-1<n)puts("-1");
		else{
			for(long long i=2,cnt=0;i<m&&cnt<n;++i)
				if(gcd(m,i)==1){
					printf("%lld ",i);
					++cnt;
				}
		}
		return 0;
	}
	if(P==2){
		if(m<=10000000){
			long long tem=1;
			for(int i=1;i<=m;i++,tem=(lll)tem*p%m)
				vis[tem]=1;
			for(int i=1;i<m&&(int)ans.size()<n;i++)
				if(!vis[i]&&gcd(i,m)==1)ans.push_back(i);
			if((int)ans.size()<n)puts("-1");
			else for(int i=0;i<(int)ans.size();i++)printf("%lld ",ans[i]);
			return 0;
		}
		if(p%4==1){
			for(int i=0;i<n;i++)printf("%d ",(i<<2)+3);
			return 0;
		}
	}
	long long tem=phi;
	if(P==2)tem>>=1ll;
	for(long long last=-1,prod=1;tem>1;){
        srand((unsigned)time(NULL));
        max_factor=0;
        fac(tem);
        tem/=max_factor;
        if(last!=max_factor)last=max_factor,prod=1;
        pri[++top]=(prod*=last);
	}
	long long g=2;
	if(P==2)g=5;
	else{
		for(;;g++){
			bool cando=1;
			for(int i=1;i<=top;i++)if(qp(g,phi/pri[i],m)==1)cando=0;
			if(cando)break;
		}
	}
	long long v=1;
	for(int i=1;i<=top;i++)if(qp(p,phi/pri[i],m)==1)v=(v/gcd(v,pri[i]))*pri[i];
//	for(int i=1;i<phi;i++)printf("%d ",qp(g,i,m));putchar('\n');
	if((phi/v)*(v-1)<n)puts("-1");
	else{
		for(long long i=1,cnt=0;i<phi&&cnt<n;i++)
			if(i%v){
				printf("%lld ",qp(g,i,m));
				++cnt;
			}
	}
	return 0;
}