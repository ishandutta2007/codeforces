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

int N;
map<int,vector<int>> Ha,He;
map<int,vector<pair<int,int>>> V,H;
set<int> cand;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

map<int,int> Yc;
set<int> Ys;
vector<int> YI;
int X1[101010],X2[101010];
int Y1[101010],Y2[101010];

ll ret;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	YI.push_back(-1<<30);
	cin>>N;
	FOR(i,N) {
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x2<x1) swap(x1,x2);
		if(y2<y1) swap(y1,y2);
		YI.push_back(y1-1);
		YI.push_back(y1);
		YI.push_back(y1+1);
		YI.push_back(y2-1);
		YI.push_back(y2);
		YI.push_back(y2+1);
		X1[i]=x1, X2[i]=x2,Y1[i]=y1,Y2[i]=y2;
	}
	sort(ALL(YI));
	YI.erase(unique(ALL(YI)),YI.end());
	FOR(i,N) {
		Y1[i]=lower_bound(ALL(YI),Y1[i])-YI.begin();
		Y2[i]=lower_bound(ALL(YI),Y2[i])-YI.begin();
		if(X1[i]==X2[i]) {
			V[X1[i]].push_back({Y1[i],Y2[i]});
			cand.insert(X1[i]);
		}
		else {
			Ha[X1[i]].push_back(Y1[i]);
			He[X2[i]].push_back(Y1[i]);
			H[Y1[i]].push_back({X1[i],X2[i]});
			cand.insert(X1[i]);
			cand.insert(X2[i]);
		}
	}
	FORR(cx,cand) {
		FORR(y,Ha[cx]) if(Yc[y]++==0) bt.add(y,1);
		if(V.count(cx)) {
			vector<pair<int,int>>& T=V[cx];
			sort(ALL(T));
			int ma=-1<<30;
			FORR(r,T) {
				r.first=max(r.first,ma+1);
				if(r.first>r.second) continue;
				ret+=YI[r.second]-YI[r.first]+1;
				ret-= bt(r.second)-bt(r.first-1);
				ma=r.second;
			}
		}
		
		FORR(y,He[cx]) if(--Yc[y]==0) bt.add(y,-1);
	}
	FORR(hy,H) {
		vector<pair<int,int>>& T=hy.second;
		sort(ALL(T));
		int ma=-1<<30;
		FORR(r,T) {
			r.first=max(r.first,ma+1);
			if(r.first>r.second) continue;
			ret+=r.second-r.first+1;
			ma=r.second;
		}
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}