#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() getchar()
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline ll readl() {
  ll ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline int Read(char*s) {
	int top=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) s[++top]=ch,ch=gc();
	return top;
}
namespace modular {
  const int mod=1e9+7;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
}
using namespace modular;
const int N=505;
int n,K,ps,vl,cnt1,cnt2;
bool ok[N];
int main() {
  #ifdef ldxcaicai
  #endif
  n=read(),K=read();
  if(K==1) {
  	cout<<"! 1";
		cout<<endl<<endl;
  	return 0;
	}
  cout<<"? ";
  for(ri i=1;i<=K;++i) {
		cout<<i;
		if(i!=K) cout<<' ';
	}
  cout<<endl<<endl;
  ps=read(),vl=read();
  int _ps=ps==1?2:1,chk=-1;
  cnt1=0,cnt2=0;
  for(ri t,v,x=K+1;x<=n;++x) {
  	cout<<"? ";
  	for(ri i=1;i<=K;++i) if(i!=_ps) cout<<i<<' ';
  	cout<<x;
  	cout<<endl<<endl;
  	t=read(),v=read();
  	if(t==ps) {
  		ok[x]=1;
  		continue;
		}
		else {
			if(v>vl) chk=0;
			else chk=1;
			continue;
		}
	}
	cnt1=1;
	for(ri t,v,x=1;x<=K;++x) {
		if(x==_ps||x==ps) continue;
		cout<<"? ";
		for(ri i=1;i<=K;++i) if(i!=x) cout<<i<<' ';
		cout<<K+1;
		cout<<endl<<endl;
		t=read(),v=read();
		if(ok[K+1]) {
			if(t==ps) {
				++cnt1;
			}
			else {
				++cnt2;
				if(v<vl) chk=0;
				else chk=1;
			}
		}
		else {
			if(t==ps) {
				++cnt2;
			}
			else {
				++cnt1;
				if(v>vl) chk=0;
				else chk=1;
			}
		}
	}
	int t,v;
	if(chk==-1) {
		if(ok[K+1]) {
			int pss=0;
			for(ri i=K+1;i<=n;++i) if(!ok[i]) {
				pss=i;
				break;
			}
			if(!pss) {
				cout<<"? ";
				for(ri i=1;i<=K;++i) if(i!=ps) cout<<i<<' ';
				cout<<K+1<<' ';
				cout<<endl<<endl;
				t=read(),v=read();
				if(v<vl) chk=0;
				else chk=1;
			}
			else {
				for(ri i=1;i<=K;++i) if(i!=ps) cout<<i<<' ';
				cout<<ps<<' ';
				cout<<endl<<endl;
				t=read(),v=read();
				if(v>vl) chk=0;
				else chk=1;
			}
		}
	}
	cout<<"! "<<(chk?K-cnt1:cnt1+1);
	cout<<endl<<endl;
  return 0;
}