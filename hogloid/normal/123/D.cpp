#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
typedef char item ;
static const int MAX_N=100005;

int len,dif;
const int INF2=1000000015;
int rank[MAX_N],tmp[MAX_N],sa[MAX_N],rev[MAX_N],lcp[MAX_N];
bool cmp(const int& a,const int& b){
	if(rank[a]!=rank[b]) return rank[a]<rank[b];
	int a1=(a+dif<=len?rank[a+dif]:-INF2),b1=(b+dif<=len?rank[b+dif]:-INF2);
	return a1<b1;
}
void buildSA(item *s,int slen){	
	len=slen;
	REP(i,len+1){
		rank[i]=s[i];
		sa[i]=i;
	}
	for(dif=1;dif<=len;dif*=2){
		sort(sa,sa+len+1,cmp);
		tmp[sa[0]]=0;
		REP(i,len) tmp[sa[i+1]]=tmp[sa[i]]+cmp(sa[i],sa[i+1]);
		REP(i,len+1) rank[i]=tmp[i];
	}


	int h=0;
	REP(i,len+1) rev[sa[i]]=i;
	REP(i,len+1){
		if(rev[i]==len) lcp[rev[i]]=0;
		else{
			for(int j=sa[rev[i]+1];j+h<=len && i+h<=len && s[i+h]==s[j+h];++h);
			lcp[rev[i]]=h;
		}
		if(h>0) --h;
	}
}//lcp[i] :=longest common prefix between suffix[i] and suffix[i+1]


lint calc(lint a){
	return a*(a-1)/2;
}
char s[100005];
lint cur;
struct uf{
	int par[100005],size[100005];
	uf(){
		memset(par,-1,sizeof(par));
		REP(i,100005) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		cur-=calc(size[a])+calc(size[b]);
		par[a]=b;
		size[b]+=size[a];
		cur+=calc(size[b]);
	}
};
uf u;
pi tall[100005];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	s[n]='$';
	buildSA(s,n);
	

	int h=0;
	lint ans=n*(lint)(n+1)/2;
	cur=0;
	REPN(i,n+1,1) tall[i-1]=mp(lcp[i],i-1);
	sort(tall,tall+n,greater<pi>());
	int j=0;
	for(int i=n;i>=1;--i){
		while(j<n && tall[j].fr==i){
			u.unite(tall[j].sc,tall[j].sc+1);
			++j;
		}
		ans+=cur;
	}


	cout<<ans<<endl;
	return 0;
}