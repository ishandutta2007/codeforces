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


template<lint mod>
struct Int_{
	unsigned x;
	unsigned mpow(Int_ a,unsigned k){
		Int_ res=1;
		while(k){
			if(k&1) res=res*a;
			a=a*a;
			k>>=1;
		}
		return res.x;
	}
	unsigned inverse(Int_ a){
		return mpow(a,mod-2);
	}
	Int_(): x(0) { }
	Int_(long long sig) {
    if(sig<0) x=sig%mod+mod;
    else x=sig%mod;
  }
	unsigned get() const { return (unsigned)x; }
	
	Int_ &operator+=(Int_ that) { if((x += that.x) >= mod) x -= mod; return *this; }
	Int_ &operator-=(Int_ that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	Int_ &operator*=(Int_ that) { x = (unsigned long long)x * that.x % mod; return *this; }
	Int_ &operator=(Int_ that) { x=that.x; return *this;}
	Int_ &operator/=(Int_ that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
	bool operator==(Int_ that) const { return x==that.x; }
	bool operator!=(Int_ that) const { return x!=that.x; }

	Int_ operator-() const { return Int_(0)-Int_(*this);}
	Int_ operator+(Int_ that) const { return Int_(*this) += that; }
	Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
	Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
	Int_ operator/(Int_ that) const { return Int_(*this) /= that; }

};

namespace std{
	template<lint mod>
	ostream &operator <<(ostream& out,const Int_<mod>& a){
		out<<a.get();
		return out;
	}
	template<lint mod>
	istream &operator >>(istream& in,Int_<mod>& a){
		in>>a.x;
		return in;
	}
};

typedef Int_<1000000009> Int;

int n;

int mark[100005];
pair<pi,int> ps[100005];

set<int> cur;

int getid(int x,int y){
  int p=lower_bound(ps,ps+n,mp(mp(x,y),-1))-ps;
  if(p<n && ps[p].fr==mp(x,y) && mark[p]){
    return ps[p].sc;
  }
  return -1;
}
int exi(int x,int y){
  return (getid(x,y)==-1?0:1);
}
int base(int x,int y){
  int p=getid(x,y);
  if(p==-1) return 0;
  return exi(x,y-1)+exi(x-1,y-1)+exi(x+1,y-1);
}

int candel(int x,int y){
  if(!exi(x,y)) return -1;
  if(base(x,y+1)==1 || base(x+1,y+1)==1 || base(x-1,y+1)==1) return -1;
  return getid(x,y);
}

int conv[100005];//id->index
int main(){
  cin>>n;
  REP(i,n){
    scanf("%d%d",&ps[i].fr.fr,&ps[i].fr.sc);
    ps[i].sc=i;
  }
  sort(ps,ps+n);

  REP(i,n) conv[ps[i].sc]=i,mark[i]=1;

  REP(i,n){
    if(candel(ps[i].fr.fr,ps[i].fr.sc)>=0){
      cur.insert(ps[i].sc);
    }
  }

  int turn=0;//0:maximize

  Int res=0;

  REP(i,n){
    int pos;
    dump(cur.size());
    if(turn==0){
      pos=*cur.rbegin();
    }else pos=*cur.begin();

    res=(res*n+pos);

    cur.erase(pos);
    dump(pos);

    pos=conv[pos];

    int x=ps[pos].fr.fr,y=ps[pos].fr.sc;
    mark[pos]=0;

    cur.insert(candel(x,y-1));
    cur.insert(candel(x+1,y-1));
    cur.insert(candel(x-1,y-1));

    if(exi(x+1,y)) cur.erase(getid(x+1,y));
    if(exi(x-1,y)) cur.erase(getid(x-1,y));
    if(exi(x+2,y)) cur.erase(getid(x+2,y));
    if(exi(x-2,y)) cur.erase(getid(x-2,y));

    cur.insert(candel(x+1,y));
    cur.insert(candel(x-1,y));
    cur.insert(candel(x+2,y));
    cur.insert(candel(x-2,y));

    cur.erase(-1);
    turn^=1;
  }
  cout<<res<<endl;
  return 0;
}