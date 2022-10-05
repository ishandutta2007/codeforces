#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
ll D[303030];
ll S[303030];
int Q;

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

pair<ll,ll> crt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
	__int128_t lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	
	__int128_t v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	ll sum=0;
	int p=0,nz=0;
	FOR(i,N) {
		cin>>x>>y;
		sum+=x;
		D[i]=y-x;
		if(D[i]>0) p++;
		if(D[i]>=nz) nz++;
	}
	sort(D,D+N);
	reverse(D,D+N);
	FOR(i,N) S[i+1]=S[i]+D[i];
	cin>>Q;
	while(Q--) {
		ll A,B;
		cin>>A>>B;
		ll mb=crt(N%A,A,0,B).first;
		ll g=__gcd(A,B);
		
		if(mb==-1) {
			cout<<-1<<endl;
			continue;
		}
		assert(mb%B==0);
		mb/=B;
		ll add=A/g;
		mb%=add*B;
		if(mb*B>N) {
			cout<<-1<<endl;
			continue;
		}
		ll ma=sum+S[mb*B];
		if(mb*B<p) {
			mb+=(p-mb*B)/B/add*add;
			ma=max(ma,sum+S[mb*B]);
			if((mb+add)*B<=N) {
				ma=max(ma,sum+S[(mb+add)*B]);
			}
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}