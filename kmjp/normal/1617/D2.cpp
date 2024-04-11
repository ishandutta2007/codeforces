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

int T,N;
int P[101010];
int V[101010];
int C[101010]={1,0,0,1,1,0,1,0,1};
int ask(int a,int b,int c) {
	cout<<"? "<<(a+1)<<" "<<(b+1)<<" "<<(c+1)<<endl;
	//return C[a]+C[b]+C[c]>=2;
	cin>>a;
	return a;
}

void ans() {
	int i,n=0;
	FOR(i,N) n+=1-P[i];
	cout<<"! "<<n;
	
	FOR(i,N) if(P[i]==0) cout<<" "<<(i+1);
	cout<<endl;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		MINUS(P);
		
		x=y=0;
		for(i=0;i<N;i+=3) {
			V[i]=ask(i,i+1,i+2);
			if(V[i]==0) x=i;
			if(V[i]==1) y=i;
		}
		
		V[x+1]=ask(x+1,x+2,y);
		V[x+2]=ask(x+2,y,y+1);
		V[y+1]=ask(y+1,y+2,x);
		V[y+2]=ask(y+2,x,x+1);
		
		if(V[x]!=V[x+1]) {
			P[x]=V[x];
			P[y]=V[x+1];
			if(P[x]==1) swap(x,y);
			P[x+1]=ask(x,y,x+1);
			P[y+1]=ask(x,y,y+1);
			P[x+2]=ask(x,y,x+2);
			P[y+2]=ask(x,y,y+2);
		}
		else if(V[x+1]!=V[x+2]) {
			P[x+1]=V[x+1];
			P[y+1]=V[x+2];
			P[x]=ask(x+1,y+1,x);
			P[y]=ask(x+1,y+1,y);
			P[x+2]=ask(x+1,y+1,x+2);
			P[y+2]=ask(x+1,y+1,y+2);
			if(P[x+1]) swap(x,y);
			x++;
			y++;
		}
		else {
			P[x+2]=V[x+2];
			P[y+2]=V[y];
			P[x]=ask(x+2,y+2,x);
			P[y]=ask(x+2,y+2,y);
			P[x+1]=ask(x+2,y+2,x+1);
			P[y+1]=ask(x+2,y+2,y+1);
			if(P[x+2]) swap(x,y);
			x+=2;
			y+=2;
		}
		
		for(i=0;i<N;i+=3) {
			if(i/3==x/3) continue;
			if(i/3==y/3) continue;
			if(V[i]==0) {
				j=ask(i,i+1,y);
				if(j==0) {
					P[i]=0;
					P[i+1]=0;
					P[i+2]=ask(i+2,x,y);
				}
				else {
					P[i]=ask(i,x,y);
					P[i+1]=P[i]^1;
					P[i+2]=0;
				}
			}
			else {
				j=ask(i,i+1,x);
				if(j==0) {
					P[i]=ask(i,x,y);
					P[i+1]=P[i]^1;
					P[i+2]=1;
				}
				else {
					P[i]=1;
					P[i+1]=1;
					P[i+2]=ask(i+2,x,y);
				}
			}
		}
		ans();
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}