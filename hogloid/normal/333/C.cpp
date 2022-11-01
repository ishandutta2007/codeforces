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

int k,m;

string s;
int MX=10000;
bool done[10][10];
set<int> memo[10][10];


vector<int> pool_[20010],*pool=&pool_[10005];
void rec(int l,int r){
	if(done[l][r]) return;

	done[l][r]=1;


	int num=0;
	REPN(i,r,l) num=num*10+s[i]-'0';

	set<int>& res=memo[l][r];
	res.clear();
	res.insert(num);
	res.insert(-num);

	REPN(i,r,l+1){
		rec(l,i);
		rec(i,r);


		set<int>& A=memo[l][i],&B=memo[i][r];
		auto it=A.begin();
		while(it!=A.end()){
			auto it2=B.begin();
			while(it2!=B.end()){
				res.insert(*it+*it2);
				res.insert(*it-*it2);
				res.insert(-*it-*it2);
				res.insert(-*it+*it2);
				res.insert((*it)*(*it2));
				res.insert(-(*it)*(*it2));
				++it2;
			}
			++it;
		}
	}
}



string itos(int a,int dig){
	string res;
	REP(hoge,dig){
		res+=a%10+'0';
		a/=10;
	}
	reverse(ALL(res));
	return res;
}

int main(){
	
	REP(i,MX){
		CLR(done);
		s=itos(i,4);

		rec(0,s.size());
		set<int>& exp=memo[0][s.size()];
		auto it=exp.begin();
		while(it!=exp.end()){
			pool[*it].pb(i);
			++it;
		}
	}

	int k,m;cin>>k>>m;

	REPN(i,10000,0){
		
		int rest=k-i;
		if(pool[i].size()>0 && pool[rest].size()>0){
			for(auto num:pool[rest]){
				int num2=i;
				{
					--m;
					string s=itos(num2,4),lat=itos(num,4);
					cout<<s+lat<<'\n';
					if(m==0) return 0;
				}
			}
		}
	}
	return 0;
}