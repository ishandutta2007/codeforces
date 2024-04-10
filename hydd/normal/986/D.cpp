#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int BASE=100;
const int Mod=998244353;
const int G=3;
const int invG=(Mod+1)/3;
typedef vector<ll> poly;
int rev[6100000];
int *GPow[2][23];
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
inline int getinv(int x){ return qpow(x,Mod-2);}
inline int add(int x,int y){ return x+y>=Mod?x+y-Mod:x+y;}
inline int dec(int x,int y){ return x-y<0?x-y+Mod:x-y;}
void NTT(poly &a,int len,int inv){
	a.resize(len);
	for (int i=0;i<len;++i)
		if (i<rev[i]) swap(a[i],a[rev[i]]);
	int w=0;
	for (int mid=1;mid<len;mid<<=1){
		w++;
		for (int i=0;i<len;i+=(mid<<1)){
			int *buf=GPow[inv][w];
			for (int j=0;j<mid;j++,++buf){
				int x=a[i+j],y=a[i+j+mid]*(*buf)%Mod;
				a[i+j]=add(x,y); a[i+j+mid]=dec(x,y);
			}
		}
	}
	if (inv==1){
		ll tmp=getinv(len);
		for (int i=0;i<len;++i) a[i]=a[i]*tmp%Mod;
	}
}
void polymul(poly a,poly b,poly &c){
	int bit=0,len=1;
	while (len<(int)a.size()+(int)b.size()) bit++,len<<=1;
	for (int i=0;i<len;++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	NTT(a,len,0); NTT(b,len,0);
	
	c.resize(len);
	for (int i=0;i<len;++i) c[i]=a[i]*b[i]%Mod;
	NTT(c,len,1);
}
void polysqr(poly a,poly &b){
	int bit=0,len=1;
	while (len<(int)a.size()+(int)a.size()) bit++,len<<=1;
	for (int i=0;i<len;++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	NTT(a,len,0);
	
	b.resize(len);
	for (int i=0;i<len;++i) b[i]=a[i]*a[i]%Mod;
	NTT(b,len,1);
}
poly f,g;
struct BigInt{
	poly s;
	BigInt(int num=0){
		s.clear();
		if (!num) s.push_back(0);
		while (num) s.push_back(num%BASE),num/=BASE;
	}
	BigInt(string st){
		s.clear();
		reverse(st.begin(),st.end());
		if (st.size()&1) st+='0';
		for (int i=0;i<(int)st.size();i+=2)
			s.push_back((st[i]-'0')+(st[i+1]-'0')*10);
		clr();
	}
	void clr(){
		while (s.size()>1&&!s.back()) s.pop_back();
	}
	BigInt operator*(int x) const{
		BigInt c; c.s.clear();
		f=s; f.resize(s.size()+3);
		for (int i=0;i<(int)f.size();++i) f[i]=f[i]*x;
		for (int i=0;i<(int)f.size();++i){
			if (f[i]>=BASE) f[i+1]+=f[i]/BASE,f[i]%=BASE;
			c.s.push_back(f[i]);
		}
		c.clr();
		return c;
	}
	void operator*=(const BigInt& a){
		polymul(s,a.s,f);
		f.resize(f.size()+3);
		s.clear();
		for (int i=0;i<(int)f.size();++i){
			if (f[i]>=BASE) f[i+1]+=f[i]/BASE,f[i]%=BASE;
			s.push_back(f[i]);
		}
		clr();
	}
	void sqr(){
		polysqr(s,f);
		s.clear();
		for (int i=0;i<(int)f.size();++i){
			if (f[i]>=BASE) f[i+1]+=f[i]/BASE,f[i]%=BASE;
			s.push_back(f[i]);
		}
		clr();
	}
	bool operator<=(const BigInt& a) const{
		if (s.size()!=a.s.size()) return s.size()<a.s.size();
		for (int i=s.size()-1;i>=0;--i)
			if (s[i]!=a.s[i]) return s[i]<a.s[i];
		return 1;
	}
};
const double LOG3=log(3);
const double LOG3_10=log(10)/LOG3;
int p; BigInt pow3p;
const int pw[]={1,3,9,27,81,243,729};
BigInt pow3(int a){
	BigInt res=1,x=3;
	while (a){
		if (a&1) res*=x;
		x.sqr(); a>>=1;
	}
	return res;
}
void init(){
	for (int p=1;p<=22;++p){
		GPow[0][p]=new int[(1<<p)+1];
		GPow[1][p]=new int[(1<<p)+1];
		int tmp0=qpow(G,(Mod-1)/(1<<p)); ll now0=1;
		int tmp1=qpow(invG,(Mod-1)/(1<<p)); ll now1=1;
		for (int i=0;i<(1<<p);++i){
			GPow[0][p][i]=now0; GPow[1][p][i]=now1;
			now0=now0*tmp0%Mod; now1=now1*tmp1%Mod;
		}
	}
}
BigInt calc(int k){
	if (k<=2) return k;
	if (k%3==0) return pow3p*pw[k/3-p];
	if (k%3==1) return pow3p*(pw[k/3-1-p]*4);
	return pow3p*(pw[k/3-p]*2);
}
int main(){
	init();
	string s;
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>s;
	BigInt n=s;
	int l=3*((s.size()-1)*LOG3_10+log(s[0]-'0')/LOG3);
	
	p=max(0,l/3-1); pow3p=pow3(p);
	for (int i=l;;++i)
		if (n<=calc(i)){
			cout<<i<<endl;
			break;
		}
	return 0;
}