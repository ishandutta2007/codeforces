#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N=0;
ll X[100],Y[100];
ll AX,AY,BX,BY;
ll SX,SY,T;
int num[100][100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0]>>Y[0]>>AX>>AY>>BX>>BY;
	cin>>SX>>SY>>T;
	for(;;N++) {
		X[N+1]=X[N]*AX+BX;
		Y[N+1]=Y[N]*AY+BY;
		//cout<<N+1<<" "<<X[N+1]<<" "<<Y[N+1]<<endl;
		
		if(X[N+1]>2LL*10000000000000000) break;
		if(Y[N+1]>2LL*10000000000000000) break;
	}
	N++;
	int ma=0;
	FOR(i,N) {
		ll lef=T-abs(SX-X[i])-abs(SY-Y[i]);
		int num=0;
		for(x=i;x<N;x++) {
			if(x>i) lef-=abs(X[x-1]-X[x])+abs(Y[x-1]-Y[x]);
			if(lef<0) break;
			num++;
			ma=max(ma,num);
			int cur=num;
			ll clef=lef;
			for(y=i-1;y>=0;y--) {
				if(y==i-1) clef-=abs(X[x]-X[y])+abs(Y[x]-Y[y]);
				else clef-=abs(X[y+1]-X[y])+abs(Y[y+1]-Y[y]);
				if(clef<0) break;
				cur++;
				ma=max(ma,cur);
			}
		}
		num=0;
		lef=T-abs(SX-X[i])-abs(SY-Y[i]);
		for(x=i;x>=0;x--) {
			if(x<i) lef-=abs(X[x+1]-X[x])+abs(Y[x+1]-Y[x]);
			if(lef<0) break;
			num++;
			ma=max(ma,num);
			int cur=num;
			ll clef=lef;
			for(y=i+1;y<N;y++) {
				if(y==i+1) clef-=abs(X[x]-X[y])+abs(Y[x]-Y[y]);
				else clef-=abs(X[y-1]-X[y])+abs(Y[y-1]-Y[y]);
				if(clef<0) break;
				cur++;
				ma=max(ma,cur);
			}
		}
		
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}