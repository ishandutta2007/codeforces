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

int H,W;

int ask(int h,int w,int y1,int x1,int y2,int x2) {
	cout<<"? "<<h<<" "<<w<<" "<<(y1+1)<<" "<<(x1+1)<<" "<<(y2+1)<<" "<<(x2+1)<<endl;
	cin>>h;
	return h;
}

int sph(int th,int step) {
	int cur=1;
	while(cur<step){
		int add=min(cur,step-cur);
		if(ask(add*th,W,0,0,cur*th,0)==0) return 0;
		cur+=add;
	}
	return 1;
}
int spw(int tw,int step) {
	int cur=1;
	while(cur<step){
		int add=min(cur,step-cur);
		if(ask(H,add*tw,0,0,0,cur*tw)==0) return 0;
		cur+=add;
	}
	return 1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	int c=H;
	int GH=H,GW=W;
	for(i=2;i<=H;i++) {
		int ok=1;
		int num=i;
		while(c%i==0) {
			if(ok&&sph(H/num,i)) GH=__gcd(GH,H/num);
			else ok=0;
			
			num*=i;
			c/=i;
		}
	}
	c=W;
	for(i=2;i<=W;i++) {
		int ok=1;
		int num=i;
		while(c%i==0) {
			if(ok&&spw(W/num,i)) GW=__gcd(GW,W/num);
			else ok=0;
			num*=i;
			c/=i;
		}
	}
	
	x=y=0;
	for(i=1;i<=H;i++) if(i%GH==0&&H%i==0) x++;
	for(i=1;i<=W;i++) if(i%GW==0&&W%i==0) y++;
	
	cout<<"! "<<(x*y)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}