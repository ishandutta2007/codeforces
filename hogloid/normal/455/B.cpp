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
static const int MAX_NODE=200010;
static const int CHNUM=26;
struct node{
	node* nxt[CHNUM];
	bool win,lose;
	void init(){
		memset(nxt,0,sizeof(nxt));
	}
};
node tree[MAX_NODE];
int cnt=1;
node* root=&tree[0];
void insert(char *s){
	int len=strlen(s);
	node* cur=root;
	REP(j,len){
		if(cur->nxt[s[j]-'a']==NULL){
			cur->nxt[s[j]-'a']=&tree[cnt++];
		}
		cur=cur->nxt[s[j]-'a'];
	}
}

char tmp[100005];
int n,k;

void rec(node* cur){
	cur->lose=cur->win=0;
	
	int term=1;
	REP(i,26) if(cur->nxt[i]){
		term=0;
		rec(cur->nxt[i]);
		if(!cur->nxt[i]->win) cur->win=1;
		if(!cur->nxt[i]->lose) cur->lose=1;
	}
	if(term){
		cur->lose=1;
	}
}

bool solve(){
	if(root->win && root->lose) return true;
	if(root->win && (k&1)) return true;
	return false;
}

int main(){
	cin>>n>>k;
	REP(i,n){
		scanf("%s",tmp);
		insert(tmp);
	}
	rec(root);

	puts(solve()?"First":"Second");

	return 0;
}