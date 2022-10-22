#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10,mod=998244353;
struct modint{
	int val;
	inline modint(int val_=0):val(val_){}
	inline modint &operator=(int val_){return val=val_,*this;}
	inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
	inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
	inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
	inline modint &operator^=(int k){
	    modint ret=1,tmp=*this;
	    for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
	    return val=ret.val,*this;
	}
	inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
	inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
	inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
	inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
	inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
	template<class T>friend modint operator+(modint a,T b){return a+=b;}
	template<class T>friend modint operator-(modint a,T b){return a-=b;}
	template<class T>friend modint operator*(modint a,T b){return a*=b;}
	template<class T>friend modint operator^(modint a,T b){return a/=b;}
	template<class T>friend modint operator/(modint a,T b){return a/=b;}
	friend modint operator^(modint a,int b){return a^=b;}
	friend bool operator==(modint a,int b){return a.val==b;}
	friend bool operator!=(modint a,int b){return a.val!=b;}
	inline bool operator!(){return !val;}
	inline modint operator-(){return val?mod-val:0;}
	inline modint &operator++(){return *this+=1;}
};
using mi=modint;
int n;
mi f[maxn][1<<3][1<<3];
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0][0][7]=1;
	for(ri i=0;i<n;++i)
		for(ri j=0;j<8;++j)
			for(ri k=0;k<8;++k)
				if(f[i][j][k].val){
					ri S=0;
					for(ri l=0;l<3;++l)
						if(!((k>>l)&1)||(s[i+1]^48))
							S|=1<<l;
					for(ri l=0;l<8;++l)
						if((l&S)==l){
							if(l==1||l==6)f[i+1][j|1][k&((s[i+1]^48)?l:7)]+=f[i][j][k];
							else if(l==2||l==5)f[i+1][j|2][k&((s[i+1]^48)?l:7)]+=f[i][j][k];
							else if(l==3||l==4)f[i+1][j|4][k&((s[i+1]^48)?l:7)]+=f[i][j][k];
							else f[i+1][j][k&((s[i+1]^48)?l:7)]+=f[i][j][k];
						}
				}
	printf("%d",accumulate(f[n][7],f[n][7]+8,mi(0)));
	return 0;
}
//001
//011
//
//010
//101
//
//011
//110
//
//100
//110
//
//101
//101
//
//110
//011