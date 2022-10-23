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

int T;
int N;
long double X,Y;
int P[303030],Q[303030];

struct cmp {
    bool operator() (pair<long double,long double> a, pair<long double,long double> b) const {
		return a.first*b.second>a.second*b.first;
    }
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X>>Y;
		FOR(i,N) cin>>P[i];
		FOR(i,N) cin>>Q[i];
		multiset<pair<long double,long double>,cmp> S;
		S.insert({X,0});
		S.insert({0,Y});
		FOR(i,N) {
			long double deg=atan2(Q[i],P[i]);
			long double len=hypot(P[i],Q[i]);
			S.insert({2*P[i],2*Q[i]});
			long double CY=Y+Q[i];
			long double CX=P[i];
			//FORR2(a,b,S) cout<<a<<":"<<b<<" ";
			//cout<<endl;
			while(CX>1e-9) {
				while(S.empty());
				auto p=*S.begin();
				S.erase(S.begin());
				//cout<<"!"<<CX<<" "<<CY<<" "<<p.first<<" "<<p.second<<endl;
				if(CX>=p.first) {
					CX-=p.first;
					CY-=p.second;
					continue;
				}
				CY-=CX*p.second/p.first;
				p.second-=CX*p.second/p.first;
				p.first-=CX;
				//cout<<"!a"<<CX<<" "<<CY<<" "<<p.first<<" "<<p.second<<endl;
				S.insert(p);
				break;
			}
			Y=CY;
			CX=X+P[i];
			CY=Q[i];
			//FORR2(a,b,S) cout<<a<<":"<<b<<" ";
			//cout<<endl;
			while(CY>1e-9) {
				//cout<<"$$"<<S.size()<<endl;
				
				auto p=*--S.end();
				S.erase(--S.end());
				//cout<<"#"<<CX<<" "<<CY<<" "<<p.first<<" "<<p.second<<endl;
				if(CY>=p.second) {
					CX-=p.first;
					CY-=p.second;
					continue;
				}
				CX-=CY*p.first/p.second;
				p.first-=CY*p.first/p.second;
				p.second-=CY;
				//cout<<"#a"<<CX<<" "<<CY<<" "<<p.first<<" "<<p.second<<endl;
				S.insert(p);
				break;
			}
			X=CX;
			_P("%.12lf\n",(double)X);
			
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}