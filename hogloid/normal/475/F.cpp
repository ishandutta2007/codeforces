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

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

//const int INF=5e8;

int n;
pi ps[100005];

pi swp(const pi& a){
	return mp(a.sc,a.fr);
}


int rec(set<pi>& a,set<pi>& b){
	if(a.size()==1) return 1;

	auto it=a.begin(),it2=a.end(),
		 	it3=b.begin(),it4=b.end();
	--it2;
	--it4;
	
	int turn=0;
	while(1){
		if(turn==0){
			auto nxt=it;
			++nxt;
			if(nxt==a.end()) return 1;

			if(nxt->fr-it->fr>1){
				set<pi> a2,b2;
				auto itr=a.begin();
				while(itr!=nxt){
					a2.insert(*itr);
					b2.insert(swp(*itr));

					b.erase(swp(*itr));
					a.erase(itr++);
				}
				return rec(a2,b2)+rec(a,b);
			}
			it=nxt;
		}else if(turn==1){
			auto nxt=it2;--nxt;
			if(it2->fr-nxt->fr>1){
				set<pi> a2,b2;
				auto itr=it2;
				while(itr!=a.end()){
					a2.insert(*itr);
					b2.insert(swp(*itr));

					b.erase(swp(*itr));
					a.erase(itr++);
				}
				return rec(a2,b2)+rec(a,b);
			}
			it2=nxt;
		}else if(turn==2){
			auto nxt=it3;
			++nxt;
			if(nxt==b.end()) return 1;
			if(nxt->fr-it3->fr>1){
				set<pi> a2,b2;
				auto itr=b.begin();
				while(itr!=nxt){
					b2.insert(*itr);
					a2.insert(swp(*itr));

					a.erase(swp(*itr));
					b.erase(itr++);
				}
				return rec(a2,b2)+rec(a,b);
			}
			it3=nxt;
		}else{
			auto nxt=it4;--nxt;
			if(it4->fr-nxt->fr>1){
				set<pi> a2,b2;
				auto itr=it4;
				while(itr!=b.end()){
					b2.insert(*itr);
					a2.insert(swp(*itr));

					a.erase(swp(*itr));
					b.erase(itr++);
				}
				return rec(a2,b2)+rec(a,b);
			}
			it4=nxt;
		}
		turn=(turn+1)%4;
	}
}


int main(){
	cin>>n;
	REP(i,n) scanf("%d%d",&ps[i].fr,&ps[i].sc);

	set<pi> X,Y;
	REP(i,n){
		X.insert(ps[i]);
		Y.insert(swp(ps[i]));
	}
	int res=rec(X,Y);
	cout<<res<<endl;

	return 0;
}