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

int N;
ll C[202020],R[202020];

struct node {
	node *lef, *ri;
	ll SC,SR;
	node(): lef(NULL),ri(NULL),SC(0),SR(0) {};
	node(node* L,node* R,ll SC,ll SR): lef(L),ri(R),SC(SC),SR(SR) {};
	
	void build(int L,int R) {
		if(L+1==R) {
			SR=::R[L];
			return;
		}
		int M=(L+R)/2;
		lef=new node();
		ri=new node();
		lef->build(L,M);
		ri->build(M,R);
		SC=lef->SC+ri->SC;
		SR=lef->SR+ri->SR;
	}
	
	node* update(int L,int R,int P,int V) {
		if(L+1==R) {
			return new node(NULL,NULL,V,0);
		}
		int M=(L+R)/2;
		node* cur=new node(this->lef,this->ri,0,0);
		if(P<M) {
			cur->lef=this->lef->update(L,M,P,V);
		}
		else {
			cur->ri=this->ri->update(M,R,P,V);
		}
		cur->SC=cur->lef->SC+cur->ri->SC;
		cur->SR=cur->lef->SR+cur->ri->SR;
		return cur;
	}
	
	ll sum(ll m) {
		return SC+SR*m;
	}
	int search(int L,int R,int x,int y,ll* v,ll m) {
		if(x>=y||L>=R) return 0;
		//cout<<"!"<<L<<R<<" "<<x<<y<<" "<<*v<<m<<" "<<this->sum(m)<<" "<<this->SC<<"+"<<m<<"*"<<this->SR<<endl;
		if(L==x&&R==y&&*v>=this->sum(m)) {
			*v-=this->sum(m);
			return R-L;
		}
		if(L+1==R) return 0;
		int M=(L+R)/2;
		ll tar=this->lef->search(L,M,x,min(y,M),v,m);
		//cout<<"!!"<<L<<R<<" "<<x<<y<<" "<<*v<<m<<" "<<this->sum(m)<<" "<<this->SC<<"+"<<m<<"*"<<this->SR<<" "<<M<<" "<<tar<<endl;
		if(tar==max(0,min(M,y)-x)) {
			tar+=this->ri->search(M,R,max(M,x),y,v,m);
		}
		return tar;
	}
};

struct segment {
	int L,R;
	ll tim,vol;
};
int Q;
vector<pair<ll,int>> pos;
vector<node*> nodes;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i]>>R[i];
		pos.push_back({C[i]/R[i],i});
	}
	sort(ALL(pos));
	nodes.push_back(new node());
	nodes.back()->build(0,N);
	FOR(i,N) {
		x=pos[i].second;
		nodes.push_back(nodes.back()->update(0,N,x,C[x]));
	}

	vector<segment> segs;
	for(i=N-1;i>=0;i--) segs.push_back({i,i+1,0LL,C[i]});


	ll ret=0;
	cin>>Q;
	while(Q--) {
		int T;
		ll H;
		cin>>T>>H;
		
		while(segs.size()&&H) {
			/*
			cout<<"!"<<H<<" "<<segs.size()<<endl;
			FORR(s,segs) {
				cout<<s.L<<" "<<s.R<<" "<<s.tim<<" "<<s.vol<<endl;
			}
			*/
			auto s=segs.back();
			segs.pop_back();
			if(s.L+1==s.R) {
				x=s.L;
				//
				ll now=min(C[x],s.vol+R[x]*(T-s.tim));
				if(now<=H) {
					H-=now;
				}
				else {
					segs.push_back({s.L,s.R,T,now-H});
					H=0;
				}
			}
			else {
				int tar=lower_bound(ALL(pos),make_pair(T-s.tim,0))-pos.begin();
				int cnt=nodes[tar]->search(0,N,s.L,s.R,&H,T-s.tim);
				assert(s.vol==0);
				//cout<<"#"<<cnt<<" "<<H<<endl;
				if(cnt!=s.R-s.L) {
					if(cnt<=(s.R-s.L)-2) {
						segs.push_back({s.L+cnt+1,s.R,s.tim,0});
					}
					x=s.L+cnt;
					ll now=min(C[x],s.vol+R[x]*(T-s.tim));
					segs.push_back({s.L+cnt,s.L+cnt+1,T,now-H});
					H=0;
				}
			}
		}
		
		
		//
		if(segs.empty()) {
			segs.push_back({0,N,T,0});
		}
		else if(segs.back().L!=0) {
			segs.push_back({0,segs.back().L,T,0});
		}
		
		//cout<<"H="<<H<<endl;
		ret+=H;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}