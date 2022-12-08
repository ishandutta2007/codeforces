#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353,g=3;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
const int N=5e5+5;
int rev[N],fac[N],ifac[N];

inline void init(int n){
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
int comb(int a,int b){
	if(b>a)return 0;
	return mul(fac[a],mul(ifac[b],ifac[a-b]));
}
/* ****************************************************************************** */
typedef vector<int> Poly;
void DFT(int *t,int n,int type){
	int l=0;while(1<<l<n)++l;
	for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<n;i++)if(rev[i]>i)swap(t[rev[i]],t[i]);
	for(int step=1;step<n;step<<=1){
		int wn=qpow(g,(mod-1)/(step<<1));
		for(int i=0;i<n;i+=step<<1){
			int w=1;
			for(int k=0;k<step;k++,w=mul(w,wn)){
				int x=t[i+k],y=mul(t[i+k+step],w);
				t[i+k]=add(x,y),t[i+k+step]=sub(x,y);
			}
		}
	}
	if(type==1)return;
	for(int i=1;i<n-i;i++)swap(t[i],t[n-i]);
	int inv=qpow(n,mod-2);
	for(int i=0;i<n;i++)t[i]=mul(t[i],inv);
}
Poly NTT(Poly A,int n,Poly B,int m){
	static Poly res,PolA,PolB;
	PolA=A,PolB=B;
	int len=1;while(len < n+m)len<<=1;
	res.resize(len);
	PolA.resize(len),PolB.resize(len);
	DFT(&PolA[0],len,1);DFT(&PolB[0],len,1);
	for(int i=0;i<len;i++) res[i]= mul(PolA[i],PolB[i]);
	DFT(&res[0],len,-1);
	res.resize(n+m-1);
	return res;
}
Poly NTT(Poly A,Poly B){
	return NTT(A,A.size(),B,B.size());
}

Poly Getstirling(int X){
	Poly ret;
	if(X==0){
		ret.resize(1);ret[0]=1;
		return ret;
	}
	if(X==1){
		ret.resize(2);ret[0]=0,ret[1]=1;
		return ret;
	}
	if(X==2){
		ret.resize(3);ret[0]=0,ret[1]=1,ret[2]=1;
	}
	int nn=X/2+1;
	Poly pst=Getstirling(X/2);
	int t=X/2;
	Poly snd=pst,tmp;
	for(int i=0;i<nn;i++) snd[i]=mul(snd[i],fac[i]);
	tmp.resize(nn);
	for(int i=0;i<nn;i++) tmp[i]=mul(qpow(t,nn-1-i),ifac[nn-1-i]);
	Poly R=NTT(snd,tmp);
	snd.resize(nn);
	for(int i=0;i<nn;i++) snd[i]=mul(ifac[i],R[i+nn-1]);
	ret=NTT(pst,snd);
	if(X%2){
		ret.resize(X+1);
		for(int i=X;i;i--){
			ret[i]=add(mul(ret[i],X-1),ret[i-1]);
		}
	}
	return ret;
}
int n,a,b;
Poly S;


int main()
{
	cin>>n>>a>>b;a--,b--;
	if(a<0||b<0){
		puts("0");return 0;
	}
	init(400000);S=Getstirling(n-1);
	//for(int i=0;i<n;i++)cout<<S[i]<<" ";
	//puts("");
	int St=0;
	if(a+b<S.size()){
		St=S[a+b];
	}
//	cout<<St<<endl;
//	cout<<a<<" "<<b<<" "<<a+b-b<<" "<<comb(a+b,b)<<endl;
//	cout<<ifac[1]<<endl;
//	cout<<fac[a+b]<<" "<<ifac[b]<<" "<<ifac[a+b-b]<<endl;
	St=mul(St,comb(a+b,b));
	printf("%d\n",St);
}