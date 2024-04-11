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

int N,M,K;
string S;
int num[12][12];
set<pair<int,pair<int,char>>> SS;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>S;
	FOR(i,N-1) num[S[i]-'a'][S[i+1]-'a']++;
	
	SS.insert({0,{0,10}});
	FOR(i,N) SS.insert({i+1,{i+1,S[i]-'a'}});
	SS.insert({N+1,{N+1,10}});
	
	
	while(M--) {
		cin>>x;
		
		if(x==1) {
			cin>>x>>y>>s;
			vector<pair<int,pair<int,char>>> toadd;
			int first=0;
			toadd.push_back({y,{x,s[0]-'a'}});
			while(1) {
				auto it=SS.lower_bound({x,{0,0}});
				if(it->second.first>y) break;
				if(it->second.first<x) toadd.push_back({x-1,{it->second.first,it->second.second}});
				if(y<it->first) toadd.push_back({it->first,{y+1,it->second.second}});
				if(first==0) {
					auto it2=it;
					it2--;
					num[it2->second.second][it->second.second]--;
					first=1;
				}
				auto it2=it;
				it2++;
				num[it->second.second][it2->second.second]--;
				num[it->second.second][it->second.second]-=it->first-it->second.first;
				SS.erase(it);
			}
			sort(ALL(toadd));
			FOR(i,toadd.size()) {
				auto r=toadd[i];
				num[r.second.second][r.second.second]+=r.first-r.second.first;
				auto it=SS.insert(r).first;
				it--;
				num[it->second.second][r.second.second]++;
				if(i==toadd.size()-1) {
					it++;
					it++;
					num[r.second.second][it->second.second]++;
				}
			}
		}
		else {
			cin>>s;
			ll ret=1;
			FOR(y,K) FOR(x,y+1) ret+=num[s[y]-'a'][s[x]-'a'];
			cout<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}