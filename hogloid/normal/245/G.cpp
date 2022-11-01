#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
map<string,int> id;
string name[10005];
vector<int> g[10005];
int getid(string& s){
	if(id.count(s)) return id[s];
	name[id.size()]=s;
	int i=id.size();
	return id[s]=i;
}
pi res[10005];
int main(){
	string a,b;
	int m;cin>>m;
	REP(i,m){
		cin>>a>>b;
		int A=getid(a),B=getid(b);
		g[A].pb(B);
		g[B].pb(A);
	}
	m=id.size();
	REP(i,m) sort(ALL(g[i]));
	REP(i,m) REP(j,i) if(!binary_search(ALL(g[i]),j)){
		int k=0,l=0;
		int same=0;
		while(k<g[i].size() && l<g[j].size()){
			if(g[i][k]==g[j][l]){
				++same;
				++k;++l;
			}else if(g[i][k]>g[j][l]){
				++l;
			}else{
				++k;
			}
		}
		if(res[i].fr<same) res[i]=mp(same,1);
		else if(res[i].fr==same) ++res[i].sc;

		if(res[j].fr<same) res[j]=mp(same,1);
		else if(res[j].fr==same) ++res[j].sc;
	}
	printf("%d\n",m);
	REP(i,m) cout<<name[i]<<' '<<res[i].sc<<'\n';

	return 0;
}