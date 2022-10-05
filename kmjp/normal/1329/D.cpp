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

int T;
int N;
string S;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int range[202020],tnum[202020];
int ri[202020];
int p1[202020],p2[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	int ot=T;
	while(T--) {
		cin>>S;
		N=S.size();
		set<int> pat[27][27];
		int cnt[27]={};
		set<int> pos;
		set<int> alive;
		int lef=0;
		cnt[26]=2;
		FOR(i,N) {
			alive.insert(i);
			bt.add(i,1);
			assert(bt(i)==i+1);
			if(i&&S[i]==S[i-1]) {
				cnt[S[i]-'a']++;
				pos.insert(lef);
				range[lef]=i;
				ri[lef]=i-1;
				lef=i;
			}
		}
		range[lef]=N;
		ri[lef]=N-1;
		pos.insert(lef);
		
		FORR(p,pos) {
			if(p==0) {
				p1[p]=26;
			}
			else {
				p1[p]=S[p]-'a';
			}
			if(ri[p]==N-1) {
				p2[p]=26;
			}
			else {
				p2[p]=S[ri[p]]-'a';
			}
			pat[p1[p]][p2[p]].insert(p);
		}
		
		vector<pair<int,int>> ret;
		while(bt(N)) {
			int ma=0,id=26;
			FOR(i,26) if(cnt[i]>ma) ma=cnt[i],id=i;
			
			int ma2=0,id2=0;
			FOR(i,26) if(i!=id) {
				if(pat[id][i].size()+pat[i][id].size()>ma2) {
					ma2=pat[id][i].size()+pat[i][id].size();
					id2=i;
				}
			}
			
			int cur;
			if(ma==0 || ma2==0) {
				cur=*pos.begin();
			}
			else {
				if(pat[id][id2].size()) {
					cur=*pat[id][id2].begin();
					pat[id][id2].erase(pat[id][id2].begin());
				}
				else {
					cur=*pat[id2][id].begin();
					pat[id2][id].erase(pat[id2][id].begin());
				}
			}
			ret.push_back({bt(cur),bt(range[cur]-1)});
			{
				auto it=alive.lower_bound(cur);
				while(1) {
					if(it==alive.end() || *it>=range[cur]) break;
					bt.add(*it,-1);
					it=alive.erase(it);
				}
			}
			cnt[p1[cur]]--;
			cnt[p2[cur]]--;
			pos.erase(cur);
			
			if(pos.empty()) break;
			auto it=alive.lower_bound(cur);
			if(it==alive.end()) {
				it=pos.lower_bound(cur);
				x=*prev(it);
				
				cnt[p2[x]]--;
				pat[p1[x]][p2[x]].erase(x);
				p2[x]=26;
				cnt[p2[x]]++;
				pat[p1[x]][p2[x]].insert(x);
				continue;
			}
			if(it==alive.begin()) {
				x=*it;
				cnt[p1[x]]--;
				pat[p1[x]][p2[x]].erase(x);
				p1[x]=26;
				cnt[p1[x]]++;
				pat[p1[x]][p2[x]].insert(x);
				continue;
			}
			x=*it;
			y=*prev(it);
			if(S[x]==S[y]) {
				cnt[p2[x]]++;
			}
			else {
				
				auto it=pos.lower_bound(cur);
				y=*it;
				x=*prev(it);
				//cout<<cur<<" "<<x<<" "<<y<<endl;
				pos.erase(y);
				pat[p1[x]][p2[x]].erase(x);
				pat[p1[y]][p2[y]].erase(y);
				p2[x]=p2[y];
				pat[p1[x]][p2[x]].insert(x);
				range[x]=range[y];
				ri[x]=ri[y];
			}
		}
		/*
		if(ot==22982 && ot-T!=3716) continue;
		if(ot==22982) cout<<S<<endl;
		*/
		cout<<ret.size()<<endl;
		FORR(r,ret) cout<<r.first<<" "<<r.second<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}