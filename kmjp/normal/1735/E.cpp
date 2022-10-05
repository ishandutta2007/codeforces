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
ll D[2][1010];
map<int,int> M;
multiset<int> A,B;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(y,2) FOR(x,N) cin>>D[y][x];
		vector<int> C;
		FOR(x,N) {
			C.push_back(D[0][0]+D[1][x]);
			C.push_back(abs(D[0][0]-D[1][x]));
		}
		int ok=0;
		FORR(a,C) {
			A.clear();
			B.clear();
			FOR(i,N) A.insert(D[0][i]);
			FOR(i,N) B.insert(D[1][i]);
			int H[2020];
			int mi=0;
			int num=0;
			int ng=0;
			while(A.size()) {
				if(*A.rbegin()>=*B.rbegin()&&*A.rbegin()>=a) {
					x=*A.rbegin();
					A.erase(A.find(x));
					auto it=B.find(x-a);
					if(it==B.end()) {
						ng=1;
						break;
					}
					B.erase(it);
					H[num++]=x;
				}
				else if(*A.rbegin()<=*B.rbegin()&&*B.rbegin()>=a) {
					x=*B.rbegin();
					B.erase(B.find(x));
					auto it=A.find(x-a);
					if(it==A.end()) {
						ng=1;
						break;
					}
					A.erase(it);
					H[num++]=a-x;
					
				}
				else {
					break;
				}
			}
			if(ng) continue;
			FORR(v,A) {
				auto it=B.find(a-v);
				if(it==B.end()) {
					break;
				}
				B.erase(it);
				H[num++]=v;
			}
			if(B.size()) continue;
			
			FOR(i,N) mi=min(mi,H[i]);
			cout<<"YES"<<endl;
			FOR(i,N) cout<<(H[i]-mi)<<" ";
			cout<<endl;
			cout<<-mi<<" "<<a-mi<<endl;
			
			
			
			ok=1;
			break;
		}
		if(ok==0) {
			cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}