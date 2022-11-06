#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
    static char buf[rlen],*ib,*ob;
    (ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
    return ib==ob?-1:*ib++;
}
inline int read(){
    int ans=0;
    char ch=gc();
    while(!isdigit(ch))ch=gc();
    while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
    return ans;
}
inline int Read(char*s){
    int top=0;
    char ch=gc();
    while(!isalpha(ch)&&!isdigit(ch))ch=gc();
    while(isalpha(ch)||isdigit(ch))s[++top]=ch,ch=gc();
    return top;
}
const int N=205;
int n,m;
const int mod1=1e9+9;
typedef long long ll;
typedef unsigned long long Ull;
const ll inf=1e18;
const Ull bas=311;
inline int add1(const int&a,const int&b){return a+b>=mod1?a+b-mod1:a+b;}
inline int dec1(const int&a,const int&b){return a>=b?a-b:a-b+mod1;}
inline int mul1(const int&a,const int&b){return (ll)a*b%mod1;}
struct Hash_string{
    vector<Ull>pw1,s1;
    vector<int>pw2,s2;
    int len;
    inline void init(char*s,int n){
        len=n;
        pw1.clear(),pw2.clear(),s1.clear(),s2.clear();
        pw1.resize(n+1),pw2.resize(n+1),s1.resize(n+1),s2.resize(n+1);
        pw1[0]=pw2[0]=1;
        for(ri i=1;i<=n;++i){
            pw1[i]=pw1[i-1]*bas;
            s1[i]=s1[i-1]*bas+(Ull)s[i];
            pw2[i]=mul1(pw2[i-1],bas);
            s2[i]=add1(mul1(s2[i-1],bas),(int)s[i]);
        }
    }
    inline void update(char x){
    	pw1.push_back(pw1.back()*bas);
    	s1.push_back(s1.back()*bas+(Ull)x);
    	pw2.push_back(mul1(pw2.back(),bas));
    	s2.push_back(add1(mul1(s2.back(),bas),(int)x));
    	++len;
	}
    inline Ull get1(int l,int r){return s1[r]-s1[l-1]*pw1[r-l+1];}
    inline Ull get2(int l,int r){return dec1(s2[r],mul1(s2[l-1],pw2[r-l+1]));}
}S[2];
char s[1000005];
int Len[1000005];
typedef long long ll;
inline int init(int a,int b){
    int n=S[a].len,m=S[b].len;
    int up=min(n,m),ret=0;
   	for(ri i=1;i<=up;++i)if(S[a].get1(n-i+1,n)==S[b].get1(1,i)&&S[a].get2(n-i+1,n)==S[b].get2(1,i))ret=i;
   	return ret;
}
int main(){
    n=read();
    int cur=0;
    S[0].init(s,0);
    for(ri len,i=1;i<=n;++i){
        len=Read(s);
        S[1].init(s,len);
        int tt=init(0,1);
        for(ri j=tt+1;j<=len;++j)cout<<s[j],S[0].update(s[j]);
    }
    return 0;
}