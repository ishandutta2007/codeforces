#include<bits/stdc++.h>
typedef long long ll,int64,LL;
const int inf=1e9;
const ll INF=1e18;
const double eps=1e-7;
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
    template<class T>inline const T&min(const T*a,const T*b){
        const T*_ans=a;
        for(++a;a!=b;++a)
            if(*a<*_ans)
            	_ans=a;
        return *_ans;
    }
	template<class T>inline const T&max(const T&a,const T&b){
		return a>b?a:b;
	}
    template<class T>inline const T&max(const T*a,const T*b){
        const T*_ans=a;
        for(++a;a!=b;++a)
            if(*a>*_ans)
            	_ans=a;
        return *_ans;
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
namespace silent_classroom{
    int n;
    int cnt[26];
    char s[21];
    int f(int x){
    	return x*(x-1)/2;
	}
    void main(){
        n=read_int();
        for(int i=0;i<n;++i){
            read_string(s);
            ++cnt[s[0]-'a'];
        }
        int ans=0;
        for(int i=0;i<26;++i)
           	ans+=f(cnt[i]>>1)+f(cnt[i]+1>>1);
        printf("%d\n",ans);
    }
}
int main(){
	silent_classroom::main();
	return 0;
}