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
int ON=0;
int ret[101]={0,2,1,3,0,2};
int A[101]={};
int H;
vector<vector<int>> hist;
int T[202];

pair<int,int> pat() {
	int i;
	int a=0,b=0;
	for(i=1;i<=ON;i++) a+=ret[i]*(ret[i]-1)*(ret[i]-2)/6;
	for(i=1;i+2<=ON;i++) b+=ret[i]*ret[i+1]*ret[i+2];
	return {a,b};
}
pair<int,int> pat2() {
	int i;
	int a=0,b=0;
	for(i=1;i<=ON;i++) a+=A[i]*(A[i]-1)*(A[i]-2)/6;
	for(i=1;i+2<=ON;i++) b+=A[i]*A[i+1]*A[i+2];
	return {a,b};
}



pair<int,int> ask(int v) {
	int a,b;
	cout<<"+ "<<v<<endl;
	ret[v]++;
	if(ON) {
		auto x=pat();
		a=x.first;
		b=x.second;
	}
	else {
		cin>>a>>b;
	}
	hist.push_back({a,b,v});
	H=hist.size();
	return {a,b};
}

void pop() {
	A[hist.back()[2]]--;
	H--;
	hist.pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,201) T[i]=i*(i-1)*(i-2)/6;
	
	if(ON) {
		N=ON;
		auto a=pat();
		x=a.first;
		y=a.second;
	}
	else {
		cin>>N;
		cin>>x>>y;
	}
	hist.push_back({x,y,0});
	for(x=N-1;x>=3;x--) ask(x);
	ask(1);
	ask(2);
	ask(1);
	for(i=2;i<=103;i++) if(hist[H-1][0]-hist[H-2][0]==T[i]-T[i-1]) {
		A[1]=i;
		break;
	}
	x=hist[H-1][1]-hist[H-2][1];
	pop();
	y=hist[H-1][1]-hist[H-2][1];
	if(hist[H-1][0]-hist[H-2][0]==0) {
		pop();
		if(hist[H-1][1]-hist[H-2][1]==0) {
			A[2]=0;
		}
		else {
			A[2]=1;
		}
	}
	else {
		for(i=2;i<=103;i++) if(hist[H-1][0]-hist[H-2][0]==T[i]-T[i-1]) {
			A[2]=i;
			break;
		}
		pop();
	}
	A[3]=x/(A[2]+1);
	pop();
	A[4]=(y-(A[1]+1)*(A[3]))/(A[3]);
	for(x=3;x<=N-2;x++) {
		assert(x==hist[H-1][2]);
		y=hist[H-1][1]-hist[H-2][1];
		A[x+2]=(y-A[x-2]*A[x-1]-A[x-1]*A[x+1])/A[x+1];
		pop();
	}
	
	while(H>1) pop();
	
	cout<<"! ";
	for(i=1;i<=N;i++) cout<<A[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}