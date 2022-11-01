#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int h,m,n;
typedef vector<int> vi;
map<int,int> conv;
map<pi,int> rev;
int used[200005];
pi pos[200005];
int gcnt;
struct segtree{
	int n;
	vi val;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		val.resize(n*2);
		REP(i,n_) val[i+n-1]=1;
		for(int i=n-2;i>=0;--i) val[i]=val[i*2+1]+val[i*2+2];
	}
	void add(int k,int a){
		k+=n-1;
		val[k]+=a;
		while(k){
			k=(k-1)/2;
			val[k]+=a;
		}
	}
	int query(int begin,int node,int l,int r,int& v){
		if(r<=begin) return INF;
		int md=(l+r)>>1,left,right;
		if(l<begin){
			left=query(begin,node*2+1,l,md,v);
			if(left<INF) return left;
			right=query(begin,node*2+2,md,r,v);
			return right;
		}
		if(val[node]<v){
			v-=val[node];
			return INF;
		}
		if(r-l==1) return l;
		if(val[node*2+1]<v){
			v-=val[node*2+1];
			return query(begin,node*2+2,md,r,v);
		}else return query(begin,node*2+1,l,md,v);
	}
	int q(int begin,int step){
		int a,b;
		a=query(begin,0,0,n,step);
		if(a<INF) return a;
		return query(0,0,0,n,step);
	}
};
segtree segs[200005];
int num[200005];
int main(){
	scanf("%d%d%d",&h,&m,&n);
	memset(pos,-1,sizeof(pos));
	REP(i,h){
		if(pos[i].fr!=-1) continue;
		int cnt=0;
		for(int j=i;pos[j].fr==-1;j=(j+m)%h,++cnt){
			pos[j]=mp(gcnt,cnt);
			rev[pos[j]]=j;
		}
		num[gcnt]=cnt;
		segs[gcnt].init(cnt);
		++gcnt;
	}
	char tmp[10];
	lint res=0;
	REP(i,n){
		scanf("%s",tmp);
		if(tmp[0]=='+'){
			int id,hash;scanf("%d%d",&id,&hash);
			int row=pos[hash].fr,begin=pos[hash].sc;
			int p=segs[row].q(begin,1);
			if(begin<=p) res+=p-begin;
			else res+=num[row]-begin+p;
			int p2=rev[mp(row,p)];
			segs[row].add(p,-1);
			conv[id]=p2;
		}else{
			int id;scanf("%d",&id);
			int p=conv[id];
			segs[pos[p].fr].add(pos[p].sc,1);
		}
	}
	cout<<res<<endl;

	return 0;
}