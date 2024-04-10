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

int N;
int R[1010],C[1010];

int ask(int x1,int y1,int x2,int y2) {
	int r;
	cout<<"? "<<(x1+1)<<" "<<(y1+1)<<" "<<(x2)<<" "<<(y2)<<endl;
	cin>>r;
	return r;
}

pair<int,int> getR(int y,int RS) {
	int LL=0,RR=N;
	RS%=2;
	while(RR-LL>1) {
		int MM=(LL+RR)/2;
		int n1=ask(LL,y,MM,y+1);
		int n2=n1^RS;
		
		if(n1%2) {
			RR=MM;
			RS=n1;
		}
		else {
			LL=MM;
			RS=n2;
		}
	}
	return {LL,y};
}

pair<int,int> getC(int x,int CS) {
	CS%=2;
	int LL=0,RR=N;
	while(RR-LL>1) {
		int MM=(LL+RR)/2;
		int n1=ask(x,LL,x+1,MM)%2;
		int n2=n1^CS;
		
		if(n1%2) {
			RR=MM;
			CS=n1;
		}
		else {
			LL=MM;
			CS=n2;
		}
	}
	return {x,LL};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> Rs,Cs;
	FOR(y,N-1) R[y+1]=ask(0,y,N,y+1)-R[y];
	FOR(x,N-1) C[x+1]=ask(x,0,x+1,N)-C[x];
	
	FOR(y,N) if((R[y]+R[y+1])%2) Rs.push_back(y);
	FOR(x,N) if((C[x]+C[x+1])%2) Cs.push_back(x);
	
	vector<pair<int,int>> P;
	
	
	if(Rs.size()==2) {
		P.push_back(getR(Rs[0],R[Rs[0]]+R[Rs[0]+1]));
		P.push_back(getR(Rs[1],R[Rs[1]]+R[Rs[1]+1]));
	}
	else {
		P.push_back(getC(Cs[0],C[Cs[0]]+C[Cs[0]+1]));
		P.push_back(getC(Cs[1],C[Cs[1]]+C[Cs[1]+1]));
	}
	
	cout<<"! "<<P[0].first+1<<" "<<P[0].second+1<<" "<<P[1].first+1<<" "<<P[1].second+1<<endl;
}


int main(int argc,char** argv){
	solve(); return 0;
}