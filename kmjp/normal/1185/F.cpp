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

int N,M;
int num[2525];
int numsum[2525];
vector<pair<int,int>> P[2525];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		x=0;
		cin>>y;
		FOR(j,y) {
			cin>>k;
			x|=1<<(k-1);
		}
		num[x]++;
	}
	FOR(i,M) {
		cin>>r;
		x=0;
		cin>>y;
		FOR(j,y) {
			cin>>k;
			x|=1<<(k-1);
		}
		P[x].push_back({r,i+1});
	}
	FOR(i,1<<9) FOR(j,1<<9) if((i&j)==j) numsum[i]+=num[j];
	
	int ma=-1,co=0;
	pair<int,int> p;
	FOR(i,1<<9) {
		sort(ALL(P[i]));
		if(P[i].size()>=2) {
			if(numsum[i]>ma || (numsum[i]==ma&&P[i][0].first+P[i][1].first<co)) {
				ma=numsum[i];
				co=P[i][0].first+P[i][1].first;
				p={P[i][0].second,P[i][1].second};
			}
		}
	}
	
	FOR(y,1<<9) FOR(x,y) if(P[x].size()&&P[y].size()) {
		r=numsum[x|y];
		j=P[x][0].first+P[y][0].first;
		if(r>ma || (r==ma && j<co)) {
			ma=r;
			co=j;
			p={P[x][0].second,P[y][0].second};
		}
	}
	if(p.first>p.second) swap(p.first,p.second);
	cout<<p.first<<" "<<p.second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}