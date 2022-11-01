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
struct Hash{

	static const int MAX_N=300005;
	static Hash pows[MAX_N];
	static lint M1;
	static lint mul1[MAX_N];
	lint a;
	static void init(){
		M1=100000037;

		mul1[0]=1;
		REP(i,MAX_N-1){
			mul1[i+1]=mul1[i]*M1;
		}
		REP(i,MAX_N) pows[i].a=mul1[i];
	}
	Hash(lint val=0){
		a=val;
	}
	Hash &operator+=(const Hash& b) { 
		a+=b.a;

		return *this;
	}
	Hash &operator-=(const Hash& b) {
		a-=b.a;

		return *this;
	}
	Hash &operator <<=(int k){
		a*=mul1[k];
		return *this;
	}
	Hash &operator =(Hash b){
		a=b.a;
		return *this;
	}
	Hash operator -()const{
		return Hash(0)-=Hash(*this);
	}

	Hash operator +(const Hash& b) const{
		return Hash(*this)+=b;
	}
	Hash operator -(const Hash& b) const{
		return Hash(*this)-=b;
	}

	Hash operator <<(int k) const{
		return Hash(*this)<<=k;
	}

	bool operator==(const Hash& b) const { return (a==b.a); }
	bool operator!=(const Hash& b) const { return (a!=b.a); }
};

const int Hash::MAX_N;
lint Hash::M1;
lint Hash::mul1[MAX_N];

Hash Hash::pows[MAX_N];int rad[16];
bool gray[16][100005];
char s[100005];
int n;
int app[100005][26];
lint cost[100005];

lint prof[100005][26];


Hash sum[100005];
bool same(int a,int b,int len){
	if(a+len>n || b+len>n) return false;
	return (sum[a+len]-(sum[a]<<len))==(sum[b+len]-(sum[b]<<len));
}

int clen(int a,int b){
	int res=0;
	for(int i=15;i>=0;--i) if(same(a,b,1<<i)){
		a+=(1<<i);
		b+=(1<<i);
		res+=(1<<i);
	}
	return res;
}

int main(){
	Hash::init();

	scanf("%s",s);
	n=strlen(s);

	REP(i,n) sum[i+1]=(sum[i]<<1)+Hash(s[i]);


	REP(i,n) gray[0][i]=true;
	
	REP(i,n){
		REP(j,26) app[i+1][j]=app[i][j];
		++app[i+1][s[i]-'a'];
	}

	rad[0]=0;
	lint base=0;
	for(int j=1;j<16;++j){
		rad[j]=rad[j-1]*2+1;
		
		REP(i,n){
			int r_c=i+(rad[j]+1)/2,l_c=i-(rad[j]+1)/2;
			if(r_c>=n || l_c<0) continue;
			int col=s[i]-'a';
			if(gray[j-1][r_c] && gray[j-1][l_c] && same(r_c,l_c,rad[j-1]+1) &&
					app[i+rad[j]+1][col]-app[i-rad[j]][col]==1){
				gray[j][i]=true;
			}
		}
	}
	
	REP(j,16) REP(i,n) if(gray[j][i]){
		int L=i-rad[j],R=i+rad[j]+1;
		lint len=rad[j]*2+1;
		cost[L]+=len*len;
		cost[R]-=len*len;

		base+=len*len;
	}

	REP(i,n) cost[i+1]+=cost[i];

	REP(j,16) REP(i,n){
		if(j==0){
			REP(c,26) ++prof[i][c];
		}else{

			int L=i-rad[j],R=i+rad[j]+1;
			int r_c=i+(rad[j]+1)/2,l_c=i-(rad[j]+1)/2;
			if(r_c>=n || l_c<0) continue;
			int col=s[i]-'a';
			lint len=(rad[j]*2+1);
			if(gray[j-1][r_c] && gray[j-1][l_c] && same(r_c,l_c,rad[j-1]+1)){
				REP(c,26) if(app[R][c]-app[L][c]-(s[i]=='a'+c?1:0)==0){
					prof[i][c]+=len*len;
				}
			}
			
			if(!gray[j-1][l_c] && !gray[j-1][r_c]) continue;
			int indx=clen(L,i+1);
			int pos=indx+L;
			if(pos>=i) continue;

			if(clen(pos+1,i+1+indx+1)+pos+1<i) continue;
			if(gray[j-1][l_c] && app[i][col]-app[L][col]==0) prof[indx+i+1][s[pos]-'a']+=len*len;
			if(gray[j-1][r_c] && app[R][col]-app[i+1][col]==0) prof[pos][s[indx+i+1]-'a']+=len*len;
		}
	}
	lint res=base;
	
	dump(base);
	REP(i,n) REP(c,26) if(s[i]-'a'!=c) chmax(res,base+prof[i][c]-cost[i]);

	cout<<res<<endl;
	return 0;
}