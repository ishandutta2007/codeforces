#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
typedef long long LL;
const int maxn=1e5+5;
const ll mod=1e9+7;
int mindiv[maxn],phi[maxn],sum[maxn];
void getphi(){
	for (int i=1;i<maxn;i++){
		mindiv[i]=i;
	}
	for (int i=2;i*i<maxn;i++){
		if (mindiv[i]==i){
			for (int j=i*i;j<maxn;j+=i){
				mindiv[j]=i;
			}
		}
	}
	phi[1]=1;
	for (int i=2;i<maxn;i++){
		phi[i]=phi[i/mindiv[i]];
		if ((i/mindiv[i])%mindiv[i]==0){
			phi[i]*=mindiv[i];
		}
		else{
			phi[i]*=mindiv[i]-1;
		}
	}
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if (!b){
		x=a; y=0; return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
ll inv[maxn];
ll get_inv(ll n){
	ll x,y;
	exgcd(n,mod,x,y);
	return (x%mod+mod)%mod;
}
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
ll len[maxn];
double len2[maxn];vector<LL> p;
LL cal(LL n,LL m)
{
    p.clear();
    for(LL i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            p.push_back(i);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1) p.push_back(n);///n
    LL S=0;
    for(LL i=1;i<(1<<p.size());i++)///11<<
    {
        LL cnt=0;
        LL mul=1;
        for(LL j=0;j<p.size();j++)///
        {
            if(i&(1<<j))///1
            {
                cnt++;
                mul*=p[j];
            }
        }
        if(cnt&1)///
            S+=m/mul;
        else S-=m/mul;///
    }
    return m-S;///S1-mn1-mn
}
int main(){
	int i,j,m;
	ll t,ans;
	double t2,ans2;
	scanf("%d",&m);
	for (i=1;i<=m;i++) inv[i]=get_inv(i);
	len[1]=0; len2[1]=0;
	for (i=1;i<=m;i++){
		if (i!=1){
			t=(m/i*inv[m]%mod+mod)%mod;
			t2=(m/i+0.0)/m;
			len[i]=(len[i]+t)%mod*get_inv(1-t)%mod;
			len2[i]=(len2[i]+t2)/(1-t2);
		}
		for (j=i*2;j<=m;j+=i){
			len[j]=(len[j]+cal(j/i,m/i)*inv[m]%mod*(len[i]+1)%mod)%mod;
			len2[j]+=(cal(j/i,m/i)+0.0)/m*(len2[i]+1);
		}
	}
	ans=0; ans2=0;
	for (i=1;i<=m;i++){
		ans=ans+len[i];
		ans2=ans2+len2[i];
	}
	ans=ans%mod*inv[m]%mod;
	printf("%I64d\n",(ans+1+mod)%mod);
	return 0;
}