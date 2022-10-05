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

int N,ON;

vector<vector<int>> R;

vector<pair<int,int>> lis;
vector<int> prelis;

void hoge(vector<int>& V) {
	if(V.empty()) return;
	
	lis.clear();
	prelis.resize(V.size());
	
	
	int i,x;
	FOR(i,V.size()) {
		int x=lower_bound(ALL(lis),make_pair(V[i],0))-lis.begin();
		if(x==lis.size()) lis.resize(x+1);
		lis[x]={V[i],i};
		if(x==0) {
			prelis[i]=-1;
		}
		else {
			prelis[i]=lis[x-1].second;
		}
	}
	
	if(1LL*lis.size()*(lis.size()+1)/2>=V.size()) {
		vector<int> V2,ret;
		for(i=lis.size()-1;i>0;i--) {
			x=prelis[lis[i].second];
			lis[i-1]={V[x],x};
		}
		for(i=x=0;i<V.size();i++) {
			if(x<lis.size() && lis[x].second==i) {
				ret.push_back(V[i]);
				x++;
			}
			else {
				V2.push_back(V[i]);
			}
		}
		R.push_back(ret);
		hoge(V2);
		return;
	}
	
	set<pair<int,int>> S;
	vector<vector<int>> R2;
	reverse(ALL(V));
	FORR(c,V) {
		auto it=S.lower_bound({c,0});
		int x;
		if(it==S.begin()) {
			R2.resize(R2.size()+1);
			x=R2.size()-1;
		}
		else {
			it--;
			x=it->second;
			S.erase(it);
		}
		S.insert({c,x});
		R2[x].push_back(c);
	}
	
	
	FORR(r,R2) {
		reverse(ALL(r));
		R.push_back(r);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ON=N;
	while(N--) {
		cin>>x;
		vector<int> V(x);
		FOR(i,x) cin>>V[i];
		
		R.clear();
		hoge(V);
		cout<<R.size()<<endl;
		FORR(r,R) {
			cout<<r.size();
			FORR(r2,r) cout<<" "<<r2;
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