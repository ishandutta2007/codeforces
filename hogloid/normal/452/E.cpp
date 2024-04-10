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

const int mod=1000000007;

struct Int {
	unsigned x;
	int mpow(Int a,int k){
		Int res=1;
		while(k){
			if(k&1) res=res*a;
			a=a*a;
			k>>=1;
		}
		return res.x;
	}
	int inverse(Int a){
		return mpow(a,mod-2);
	}
	Int(): x(0) { }
	Int(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
	int get() const { return (int)x; }
	
	Int &operator+=(Int that) { if((x += that.x) >= mod) x -= mod; return *this; }
	Int &operator-=(Int that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	Int &operator*=(Int that) { x = (unsigned long long)x * that.x % mod; return *this; }
	Int &operator=(Int that) { x=that.x; return *this;}
	Int &operator/=(Int that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
	bool operator==(Int that){ return x==that.x; }
	bool operator>(Int that) { return x>that.x;}
	bool operator<(Int that) { return x<that.x;}


	Int operator+(Int that) const { return Int(*this) += that; }
	Int operator-(Int that) const { return Int(*this) -= that; }
	Int operator*(Int that) const { return Int(*this) *= that; }
	Int operator/(Int that) const { return Int(*this) /= that; }

};



namespace std{
	ostream &operator <<(ostream& out,const Int& a){
		out<<a.get();
		return out;
	}
	istream &operator >>(istream& in,Int& a){
		in>>a.x;
		return in;
	}
};
typedef char item ;
static const int MAX_N=300005;
int len,dif;
const int INF2=1000000015;
int rankk[MAX_N],tmp[MAX_N],sa[MAX_N],rev[MAX_N],lcp[MAX_N];
bool cmp(const int& a,const int& b){
	if(rankk[a]!=rankk[b]) return rankk[a]<rankk[b];
	int a1=(a+dif<=len?rankk[a+dif]:-INF2),b1=(b+dif<=len?rankk[b+dif]:-INF2);
	return a1<b1;
}
void buildSA(item *s,int slen){	
	len=slen;
	REP(i,len+1){
		rankk[i]=s[i];
		sa[i]=i;
	}
	for(dif=1;dif<=len;dif*=2){
		sort(sa,sa+len+1,cmp);
		tmp[sa[0]]=0;
		REP(i,len) tmp[sa[i+1]]=tmp[sa[i]]+cmp(sa[i],sa[i+1]);
		REP(i,len+1) rankk[i]=tmp[i];
	}


	int h=0;
	REP(i,len+1) rev[sa[i]]=i;
	REP(i,len+1){
		if(rev[i]==len) lcp[rev[i]]=0;
		else{
			for(int j=sa[rev[i]+1];j+h<=len && i+h<=len && s[i+h]==s[j+h] && s[i+h]!='$';++h);
			lcp[rev[i]]=h;
		}
		if(h>0) --h;
	}
}//lcp[i] :=longest common prefix between suffix[i] and suffix[i+1]

char s[MAX_N];
struct uf{
	static const int MSIZE=300005;
	int par[MSIZE];
	int size[MSIZE];

	int cont[MSIZE][3];
	void init(){
		memset(par,-1,sizeof(par));
		REP(i,MSIZE) size[i]=1;
		CLR(cont);
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	Int unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return 0;
		if(size[a]<size[b]) swap(a,b);
		
		Int res=0;
		REP(i,3){
			Int tmp=cont[a][i],tmp2=cont[b][i];
			REP(j,3) if(i!=j) {
				tmp*=cont[b][j];
				tmp2*=cont[a][j];
			}
			res+=tmp+tmp2;
		}
		REP(i,3) cont[a][i]+=cont[b][i];
		par[b]=a;
		size[a]+=size[b];
		return res;
	}
	bool same(int a,int b){
		return root(a)==root(b);
	}
};
uf u;
int belong[MAX_N];

pi lcp2[MAX_N];

Int ans[300005];

int done[300005];
int main(){
	u.init();
	int len=0;

	int mini=INF2;
	memset(belong,-1,sizeof(belong));
	REP(i,3){
		scanf("%s",s+len);
		int len2=strlen(s);
		chmin(mini,len2-len);
		REPN(j,len2,len) belong[j]=i;
		s[len2]='$';
		++len2;
		len=len2;
	}
	buildSA(s,len);

	REP(i,len) lcp2[i]=mp(lcp[i],i);
	REP(i,len+1) if(belong[sa[i]]>=0){
		u.cont[i][belong[sa[i]]]++;
	}

	sort(lcp2,lcp2+len,greater<pi>());
	
	Int ever=0;

	REP(i,len){
		int p=lcp2[i].sc,length=lcp2[i].fr;
		ever+=u.unite(p,p+1);
		ans[length]=ever;
		done[length]=1;
	}
	for(int i=mini-1;i>0;--i) if(!done[i]) ans[i]=ans[i+1];

	REP(i,mini) printf("%d%c",ans[i+1].get(),i==mini-1?'\n':' ');
	return 0;
}