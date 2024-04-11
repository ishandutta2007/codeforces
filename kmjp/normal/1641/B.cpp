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
ll A[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> op;
		vector<int> pat;
		deque<int> Q;
		FOR(i,N) {
			cin>>x;
			
			Q.push_back(x);
		}
		int len=0;
		while(Q.size()) {
			x=Q.front();
			Q.pop_front();
			vector<int> C;
			while(Q.size()) {
				y=Q.front();
				if(x==y) break;
				C.push_back(y);
				Q.pop_front();
			}
			if(Q.empty()) {
				Q.push_front(0);
				break;
			}
			len+=C.size()+2;
			/*
			cout<<x<<"!";
			FORR(c,C) cout<<c<<" ";
			cout<<":";
			FORR(q,Q) cout<<q<<" ";
			cout<<endl;
			*/
			pat.push_back(2*(C.size()+1));
			Q.pop_front();
			FORR(c,C) {
				if(Q.size()&&Q.front()==c) {
					Q.pop_front();
					len++;
				}
				else {
					op.push_back({len,c});
					len++;
					Q.push_front(c);
				}
			}
			
			
		}
		
		if(Q.size()) {
			cout<<-1<<endl;
		}
		else {
			cout<<op.size()<<endl;
			FORR2(a,b,op) {
				cout<<a<<" "<<b<<endl;
			}
			cout<<pat.size()<<endl;
			FORR(a,pat) cout<<a<<" ";
			cout<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}