#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

int n;
int ar[500005];
vector<int> pos[1000005];
set<int> remain;
int main(){
	cin>>n;
	if(n==1){
		puts("0");
		return 0;
	}

	REP(i,n){
		scanf("%d",&ar[i]);
		pos[ar[i]].pb(i);
		remain.insert(i);
	}
	
	lint res=0;
	REP(i,1000005){
		REP(j,pos[i].size()){
			int p=pos[i][j];
			auto it=remain.lower_bound(p),it2=it;
			++it2;
			if(it==remain.begin() || it2==remain.end()) continue;
			--it;
			if(min(ar[*it2],ar[*it])>=ar[p]){
				res+=min(ar[*it2],ar[*it]);

				++it;
				remain.erase(it);
			}
		}
	}
	auto it=remain.begin();
	vector<int> left;
	while(it!=remain.end()) left.pb(ar[*it]),++it;
	
	int mx=max_element(ALL(left))-left.begin();
	debug(ALL(left));
	if(left.size()>2){
		sort(ALL(left));
		REP(i,left.size()-2) res+=left[i];
	}
	cout<<res<<endl;


	return 0;
}