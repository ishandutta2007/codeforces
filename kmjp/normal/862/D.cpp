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
int first,last;

string answer;

int ask(string s) {
	int ret;
	
	
	cout<<"? "<<s<<endl;
	/*
	int i,num=0;
	FOR(i,s.size()) num+=s[i]!=answer[i];
	return num;
	*/
	cin>>ret;
	return ret;
}

void ans(int a,int b) {
	cout<<"! "<<a<<" "<<b<<endl;
	exit(0);
}

int search1(int L,int R,int num0) {
	if(L+1==R) return L;
	int M=(L+R)/2;
	string q=string(N,'0');
	for(int i=L;i<M;i++) q[i]='1';
	int r=ask(q);
	if(r==num0+(M-L)) return search1(M,R,num0);
	return search1(L,M,num0);
}
int search0(int L,int R,int num0) {
	if(L+1==R) return L;
	int M=(L+R)/2;
	string q=string(N,'0');
	for(int i=L;i<M;i++) q[i]='1';
	int r=ask(q);
	if(r==num0-(M-L)) return search0(M,R,num0);
	return search0(L,M,num0);;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	cin>>answer;
	N=answer.size();
	*/
	cin>>N;
	x = ask(string(N,'1'));
	y = ask(string(1,'0')+string(N-1,'1'));
	
	first=(x<y);
	
	x=N-x;
	if(first==0) {
		ans(1,search1(1,N,x)+1);
	}
	else {
		ans(search0(1,N,x)+1,first);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}