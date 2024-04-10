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

ll K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	
	for(int a=2;a<=2000;a+=2) {
		for(int mi=-a/2;mi>=-a/2-10;mi--) {
			for(int b=1;a+b<=2000;b++) {
				ll hoge=K+(-mi)*(a+b);
				if(hoge%a) continue;
				hoge/=a;
				if(hoge<b || hoge>=b*1000000) continue;
				
				cout<<a+b<<endl;
				FOR(i,(a/2)-1) {
					cout<<0<<" "<<-1<<" ";
				}
				cout<<0<<" "<<(mi+(a/2-1))<<" ";
				FOR(i,b) {
					x=min(hoge,1000000LL);
					cout<<x<<" ";
					hoge-=x;
				}
				cout<<endl;
				return;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}