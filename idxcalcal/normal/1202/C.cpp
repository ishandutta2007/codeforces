#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return f?ans:-ans;
	#undef gc
}
typedef pair<int,int> pii;
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b){return (a+=b)>=mod?a-mod:a;}
inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline void Add(int&a,int b){(a+=b)>=mod?a-=mod:a;}
inline void Dec(int&a,int b){(a-=b)<0?a+=mod:a;}
inline void Mul(int&a,int b){a=(ll)a*b%mod;}
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
const int N=2e6+5;
int n,c1,c2,c3,c4,m1,m2,m3,m4,x,y,t11,t22,t33,t44,suf1[N],suf2[N],suf3[N],suf4[N],X[N],Y[N];
vector<int>t1,t2,t3,t4;
char s[N];
ll ans=0;
inline ll calc(int a,int b,int c,int d){return (ll)(b-a+1)*(d-c+1);}
inline void update1(){
	ans=min(ans,calc(min(min(m2,t11?X[t11-1]-1:0x3f3f3f3f),suf2[t11]-1),max(0,m1-1),m4,m3));
}
inline void update2(){
	ans=min(ans,calc(min(m2+1,0),max(max(m1,t22?X[t22-1]+1:-0x3f3f3f3f),suf1[t22]+1),m4,m3));
}
inline void update3(){
	ans=min(ans,calc(m2,m1,min(min(m4,t33?Y[t33-1]-1:0x3f3f3f3f),suf4[t33]-1),max(0,m3-1)));
}
inline void update4(){
	ans=min(ans,calc(m2,m1,min(m4+1,0),max(max(m3,t44?Y[t44-1]+1:-0x3f3f3f3f),suf3[t44]+1)));
}
int main(){
	for(ri tt=read();tt;--tt){
		scanf("%s",s+1);
		n=strlen(s+1);
		m1=0,m2=0,m3=0,m4=0,x=0,y=0,c1=1,c2=1,c3=1,c4=1,t11=t22=t33=t44=0;
		t1.clear(),t2.clear(),t3.clear(),t4.clear();
		t1.push_back(0);
		t2.push_back(0);
		t3.push_back(0);
		t4.push_back(0);
		for(ri i=1;i<=n;++i){
			if(s[i]=='W'){
				++x;
				if(m1==x)++c1,t1.push_back(i);
				else if(m1<x)c1=1,m1=x,t1.clear(),t1.push_back(i),t11=i;
			}
			if(s[i]=='S'){
				--x;
				if(m2==x)++c2,t2.push_back(i);
				else if(m2>x)c2=1,m2=x,t2.clear(),t2.push_back(i),t22=i;
			}
			if(s[i]=='D'){
				++y;
				if(m3==y)++c3,t3.push_back(i);
				else if(m3<y)c3=1,m3=y,t3.clear(),t3.push_back(i),t33=i;
			}
			if(s[i]=='A'){
				--y;
				if(m4==y)++c2,t4.push_back(i);
				else if(m4>y)c4=1,m4=y,t4.clear(),t4.push_back(i),t44=i;
			}
			X[i]=x,Y[i]=y;
		}
		suf1[n+1]=-1e9,suf2[n+1]=1e9,suf3[n+1]=-1e9,suf4[n+1]=1e9;
		for(ri i=n;i;--i){
			suf1[i]=max(suf1[i+1],X[i]);
			suf2[i]=min(suf2[i+1],X[i]);
			suf3[i]=max(suf3[i+1],Y[i]);
			suf4[i]=min(suf4[i+1],Y[i]);
		}
		ans=calc(m2,m1,m4,m3);
		update1();
		update2();
		update3();
		update4();
		cout<<ans<<'\n';
	}
	return 0;
}