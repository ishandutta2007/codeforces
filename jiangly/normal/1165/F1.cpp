#include<bits/stdc++.h>
typedef long long ll,int64,LL;
const int inf=1e9;
namespace FastIO{
	const int BUF_SIZE=1<<24;
	char buf[BUF_SIZE],*p1,*p2;
	inline char gc(){
		return p1==p2?p2=(p1=buf)+fread(buf,1,BUF_SIZE,stdin):0,p1==p2?-1:*p1++;
	}
	inline int read_int(){
		int ans=0;
		char c=gc();
		bool sign=0;
		for(;(~c)&&!isdigit(c);c=gc())
			sign=(c=='-');
		for(;isdigit(c);c=gc())
			ans=(ans<<3)+(ans<<1)+(c^'0');
		if(sign)
			ans=-ans;
		return ans;
	}
	inline char read_char(){
		char c=gc();
		for(;isspace(c);)
			c=gc();
		return c;
	}
	inline int read_string(char*p){
		char*q=p;
		char c=gc();
		for(;isspace(c);c=gc());
		for(;(~c)&&!isspace(c);c=gc())
			*q++=c;
		*q=0;
		return q-p;
	}
}
using namespace FastIO;
namespace algo{
	template<class T>inline const T&min(const T&a,const T&b){
		return a<b?a:b;
	}
	template<class T>inline const T&max(const T&a,const T&b){
		return a>b?a:b;
	}
	template<class T>inline void swap(T&a,T&b){
		T c=a;
		a=b;
		b=c;
	}
	int gcd(int a,int b){
		return b?gcd(b,a%b):a;
	}
	inline int sq(int x){
		return x*x;
	}
    template<class T>inline void fill(T*a,T*b,const T&c){
        for(;a!=b;*a++=c);
    }
}
using namespace algo;
const int MAXN=200000;
int n,m,sum;
int k[MAXN];
bool used[MAXN];
struct sale{
    int d,t;
}a[MAXN];
bool operator<(const sale&a,const sale&b){
    return a.d<b.d;
}
bool check(int limit){
    fill(used,used+n,false);
    int cnt=0,res=limit;
    for(int i=m-1;~i;--i){
        if(a[i].d>limit||used[a[i].t])
            continue;
        res=min(res,a[i].d);
        used[a[i].t]=1;
        if(res>k[a[i].t]){
            res-=k[a[i].t];
            cnt+=k[a[i].t];
        }else{
            cnt+=res;
            break;
        }
    }
    return (sum<<1)-cnt<=limit;
}
void solve(){
    n=read_int();
    m=read_int();
    for(int i=0;i<n;++i){
        k[i]=read_int();
        sum+=k[i];
    }
    for(int i=0;i<m;++i){
        a[i].d=read_int();
        a[i].t=read_int()-1;
    }
    std::sort(a,a+m);
    int l=1,r=sum<<1;
    for(;l!=r;){
        int mid=l+r>>1;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%d\n",l);
}
int main(){
    solve();
	return 0;
}