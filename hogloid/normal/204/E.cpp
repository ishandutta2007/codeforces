#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
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
static const int MAX_N=200005;
int len,dif;
const int INF2=1000000015;
int rank[MAX_N],tmp[MAX_N],sa[MAX_N],rev[MAX_N],lcp[MAX_N];
bool cmp(const int& a,const int& b){
	if(rank[a]!=rank[b]) return rank[a]<rank[b];
	int a1=(a+dif<=len?rank[a+dif]:-INF2),b1=(b+dif<=len?rank[b+dif]:-INF2);
	return a1<b1;
}

struct segtree{
	static const int MAX_N=800005;
	int val[MAX_N],all[MAX_N];
	int n;
	void init(int n_,int *a){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=INF;
		REP(i,n_) val[i+n-1]=a[i];
		for(int i=n-2;i>=0;--i) val[i]=min(val[i*2+1],val[i*2+2]);
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return INF;
		int md=(l+r)>>1;
		return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
	void renew(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			val[i]=max(v,val[i]);
			all[i]=max(all[i],v);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		renew(a,b,i*2+1,l,md,v);
		renew(a,b,i*2+2,md,r,v);
	}
	int get(int k){
		k+=n-1;
		int res=all[k];
		while(k>0){
			k=(k-1)/2;
			res=max(res,all[k]);
		}
		return res;
	}
};


segtree seg,hei;
int kind[200005],kind2[200005];
int last[200005],nxt[200005];
int n,k;
int nullnull[200005];
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
			for(int j=sa[rev[i]+1];j+h<=len && i+h<=len && s[i+h]==s[j+h] && s[i+h]!='$';++h);
			lcp[rev[i]]=h;
		}
		if(h>0) --h;
	}
	REP(i,len+1) kind2[i]=kind[sa[i]];
	seg.init(len+1,lcp);
	hei.init(len+1,nullnull);

}//lcp[i] :=longest common prefix between suffix[i] and suffix[i+1]
char s[200005],temp[100005];
int begin[100005],end[100005];
lint ans[100005];
int main(){
	scanf("%d%d",&n,&k);
	int m=0;
	REP(i,n){
		scanf("%s",temp);
		int len=strlen(temp);
		if(k==1) cout<<len*(lint)(len+1)/2<<endl;
		begin[i]=m;
		REP(j,len){
			kind[m]=i;
			s[m++]=temp[j];
		}
		end[i]=m;
		kind[m]=i;
		s[m++]='$';
	}
	if(k==1) return 0;
	buildSA(s,m-1);
	
	int b=0,e=0;
	while(s[sa[b]]<'a') ++b;

	int pos=e=b;
	int sum=0;
	map<int,int> dict;
	while(e<=m){
		if(sum<k){
			int a=dict[kind2[e]];
			if(b>pos){
				int small=seg.query(b-1,e-1,0,0,seg.n);
				hei.renew(b-1,e,0,0,seg.n,small);
			}
			++dict[kind2[e]];++e;
			if(a==0) ++sum;
		}else{
			int small=seg.query(b,e-1,0,0,seg.n);
			hei.renew(b,e,0,0,seg.n,small);
			int a=dict[kind2[b]];
			--dict[kind2[b]];++b;
			if(a==1) --sum;
		}
	}
	REPN(i,m+1,pos){
		int val=hei.get(i);
		ans[kind2[i]]+=val;
	}
	REP(i,n) cout<<ans[i]<<'\n';

	return 0;
}