#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define dump(x) cerr<<#x<<" = "<<x<<endl;
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
using namespace std;
typedef long long int lint;
typedef long double ld;
typedef pair<int,int> pi;
struct node{
	node *nxt[26];
	node *fail;
	int begin,end;
	vector<node*> rev;
	node(){
		REP(i,26) nxt[i]=NULL;
		fail=NULL;
		begin=end=-1;
	}
};
node tree[1000005];
node *root=&tree[0];
int cnt;
vector<node*> last;
void insert(char* s){
	node *cur=root;
	int len=strlen(s);
	REP(i,len){
		if(cur->nxt[s[i]-'a']==NULL) cur->nxt[s[i]-'a']=&tree[cnt++];
		cur=cur->nxt[s[i]-'a'];
	}
	last.pb(cur);
}
void build(){
	queue<node*>q;
	REP(i,26){
		if(root->nxt[i]==NULL) root->nxt[i]=root;
		else{
			root->nxt[i]->fail=root;
			q.push(root->nxt[i]);
		}
	}
	while(!q.empty()){
		node* cur=q.front();q.pop();
		REP(i,26) if(cur->nxt[i]!=NULL){
			node* p=cur->fail;
			while(p->nxt[i]==NULL) p=p->fail;
			p=p->nxt[i];
			cur->nxt[i]->fail=p;
			q.push(cur->nxt[i]);
		}
	}
}
int val[2300005];
struct BIT{
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
	}
	void add(int k,int a){// [k
		++k;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){ // [0,k)
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return res;
	}
};
void dfs(node* v){
	v->begin=cnt++;
	REP(i,v->rev.size()){
		node* to=v->rev[i];
		dfs(to);
	}
	v->end=cnt;
}
void euler_tour(){
	REPN(i,cnt,1){
		tree[i].fail->rev.pb(&tree[i]);
	}
	dfs(root);
}
BIT bit;
lint ahosch(char *s){
	lint res=0;
	node *cur=root;
	int len=strlen(s);
	REP(i,len){
		while(cur->nxt[s[i]-'a']==NULL) cur=cur->fail;
		cur=cur->nxt[s[i]-'a'];
		res+=bit.query(cur->begin+1);
	}
	return res;
}
char tmp[1100005];
int enable[110005];
int main(){
	cnt=1;
	int n,k;scanf("%d%d",&n,&k);
	bit.init(1100005);
	REP(i,k){
		scanf("%s",tmp);
		insert(tmp);
	}
	build();
	euler_tour();
	cnt=0;
	REP(i,k){
		enable[i]=1;
		bit.add(last[i]->begin,1);
		bit.add(last[i]->end,-1);
	}
	REP(i,n){
		scanf("%s",tmp);
		if(tmp[0]=='?') cout<<ahosch(tmp+1)<<endl;
		else if(tmp[0]=='+'){
			int a;
			sscanf(tmp+1,"%d",&a);
			--a;
			if(enable[a]==0){
				bit.add(last[a]->begin,1);
				bit.add(last[a]->end,-1);
				enable[a]=1;
			}
		}else if(tmp[0]=='-'){
			int a;
			sscanf(tmp+1,"%d",&a);
			--a;
			if(enable[a]==1){
				bit.add(last[a]->begin,-1);
				bit.add(last[a]->end,1);
				enable[a]=0;
			}
		}
	}

	return 0;
}