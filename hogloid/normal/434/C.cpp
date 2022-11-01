#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int n,m,lim;
typedef vector<int> vi;
vector<int> L,R;
int dp[205][255][505][2][2];//dp[len][pos][value][islower][iszero]
const lint mod=1000000007;

void input(vector<int>& a){
	int len;cin>>len;
	REP(i,len){
		int t;cin>>t;
		a.pb(t);
	}
}


static const int MAX_NODE=405,MAX_LEN=205;
static const int CHNUM=22;
struct node{
	node* nxt[CHNUM];
	int flag;
	node* fail;
	void init(){
		memset(nxt,0,sizeof(nxt));
		flag=0;
		fail=NULL;
	}
};
node tree[MAX_NODE];
char tmp[MAX_LEN];
node* root=&tree[0];
int cnt=1;
void insert(int *s,int len,int value){
	node* cur=root;
	REP(j,len){
		if(cur->nxt[s[j]]==NULL){
			cur->nxt[s[j]]=&tree[cnt++];
		}
		cur=cur->nxt[s[j]];
	}
	cur->flag+=value;
}
void build(){
	queue<node*>q;
	REP(i,CHNUM){
		if(root->nxt[i]==NULL)root->nxt[i]=root;
		else{
			root->nxt[i]->fail=root;
			q.push(root->nxt[i]);
		}
	}
	while(!q.empty()){
		node* cur=q.front();q.pop();
		REP(i,CHNUM) if(cur->nxt[i]!=NULL){
			node* p=cur->fail;
			while(p->nxt[i]==NULL){
				p=p->fail;
			}
			p=p->nxt[i];
			cur->nxt[i]->fail=p;
			cur->nxt[i]->flag+=p->flag;
			q.push(cur->nxt[i]);
		}
	}
}
//dp [len][pos][value][islower][iszero]

inline void chadd(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}

int solve(vi R,int flag=0){//flag=1 no toki same dame
	memset(dp,0,sizeof(dp));
	int len=R.size();

	dp[0][0][0][0][1]=1;
	REP(i,len) REP(j,cnt) REP(k,lim+1) REP(t,2) REP(t2,2) if(dp[i][j][k][t][t2]){
		node* cur=&tree[j];
		REP(l,m) {
			int nsign=t;
			if(t==0 && l>R[i]) continue;
			if(l<R[i]) nsign=1;
			node* p=cur;
			while(p->nxt[l]==NULL) p=p->fail;
			p=p->nxt[l];
			int sum=k+p->flag;
			if(t2&&l==0) sum=k,p=root;
			if(sum<=lim) 
				chadd(dp[i+1][p-root][sum][nsign][t2 && l==0],dp[i][j][k][t][t2]);
		}
	}

	int res=0;
	REP(i,cnt) REP(j,lim+1){
		if(flag) chadd(res,dp[len][i][j][1][0]);
		else REP(t,2) chadd(res,dp[len][i][j][t][0]);
	}
	return res;
}

int main(){
	cin>>n>>m>>lim;
	
	
	input(L);input(R);
	
	REP(i,n){
		int ar[205];
		int len;cin>>len;
		REP(j,len) cin>>ar[j];
		int val;cin>>val;
		insert(ar,len,val);
	}
	build();
	lint ans;
	if(L.size()==1 && L[0]==1) ans=solve(R);
	else{
		ans=solve(R)-solve(L,1);
		ans=(ans+mod)%mod;
	}
	cout<<ans<<endl;

	return 0;
}