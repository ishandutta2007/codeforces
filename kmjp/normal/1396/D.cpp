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

int N,K,L;
int X[2020],Y[2020],C[2020];
vector<pair<int,int>> ycand[2020];
const ll mo=1000000007;
vector<int> Ys;

multiset<int> Xs[2020];

class AreaRect {
public:
	map<ll,ll> M;
	ll sum;
	AreaRect() {
		M[0]=1LL<<60;
		M[1LL<<60]=0;
		sum=0;
	}
	void add(ll x,ll y) {
		auto k=M.lower_bound(x);
		if(k->second>=y) return;
		while(prev(M.lower_bound(x))->second<=y) {
			auto p=*prev(M.lower_bound(x));
			M.erase(p.first);
			sum-=(p.first-prev(M.lower_bound(p.first))->first)*(p.second-M.lower_bound(p.first)->second);
		}
		sum += (x-prev(M.lower_bound(x))->first)*(y-M.lower_bound(x)->second);
		M[x]=y;
		//cout<<"add "<<x<<" "<<y<<" "<<sum<<endl;
	}
};



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L;
	Ys.push_back(0);
	Ys.push_back(L);
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>C[i];
		Ys.push_back(Y[i]);
		C[i]--;
	}
	sort(ALL(Ys));
	Ys.erase(unique(ALL(Ys)),Ys.end());
	FOR(i,N) {
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		ycand[Y[i]].push_back({X[i],C[i]});
	}
	FOR(y,Ys.size()) sort(ALL(ycand[y]));
	
	ll ret=0;
	int prey=-1;
	FOR(y,Ys.size()-1) {
		AreaRect ar;
		
		FOR(i,K) Xs[i].clear(),Xs[i].insert(-1),Xs[i].insert(L);
		FOR(i,N) if(Y[i]>=y) Xs[C[i]].insert(X[i]);
		FOR(i,K) {
			int pre=0;
			FORR(x,Xs[i]) if(x>=0) {
				//cout<<"!add "<<i<<" "<<pre<<" "<<x<<endl;
				ar.add(L-(pre),x+1);
				pre=x+1;
			}
		}
		/*
		FORR(m,ar.M) cout<<m.first<<":"<<m.second<<"  ";
		cout<<y<<" "<<ar.sum<<endl;
		*/
		for(int y2=Ys.size()-2;y2>=y;y2--) {
			(ret+=1LL*(Ys[y]-prey)*(Ys[y2+1]-Ys[y2])%mo*((1LL*L*(L+1)-ar.sum)%mo))%=mo;
			//cout<<Ys[y]<<" "<<Ys[y2]<<" "<<((Ys[y]-prey))<<" "<<(Ys[y2+1]-Ys[y2])<<" "<<(1LL*L*(L+1)-ar.sum)<<" "<<ret<<endl;
			FORR(c,ycand[y2]) {
				auto it=Xs[c.second].lower_bound(c.first);
				ar.add(L-(*prev(it)+1),*next(it)+1);
				
				Xs[c.second].erase(it);
			}
			/*
			cout<<"  "<<y2<<"  : ";
			FORR(m,ar.M) cout<<m.first<<":"<<m.second<<"  ";
			cout<<y<<" "<<ar.sum<<endl;
			*/
		}
		prey=Ys[y];
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}