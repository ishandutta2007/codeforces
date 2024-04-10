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
int n,q;
struct list{
	int next[100005],back[100005];
	list(){
		REP(i,100005) next[i]=i+1,back[i]=i-1;
	}
	int get(int a,int t){
		++a;
		if(t==0) return next[a]-1;
		else return back[a]-1;
	}
	void erase(int a){
		++a;
		next[back[a]]=next[a];
		back[next[a]]=back[a];
	}
};
list move;

int vised[100005];
char buf[100005];
int putted[3000005][10];
int passed[100005],backtime[100005];
vector<int> stk;
int main(){
	cin>>n>>q;
	scanf("%s",buf);
	int cp=0,dp=0,last=0;//0:forward 1:backward
	int start=0;
	int t;
	memset(backtime,-1,sizeof(backtime));
	memset(vised,-1,sizeof(vised));
	for(t=0;;++t){

		if(cp==-1){
			REP(i,n) if(!passed[i]){
				start=cp=i;break;
			}
			if(cp==-1) break;
			dp=0;
			last=0;
		}
		if(vised[cp]==-1){
			vised[cp]=t;
			stk.pb(cp);
		}
		REP(i,10) putted[t+1][i]=putted[t][i];
		passed[cp]=1;
		if(buf[cp]>='0' && buf[cp]<='9'){
			putted[t+1][buf[cp]-'0']++;
			if(buf[cp]=='0'){
				move.erase(cp);
				if(start==cp) ++start;
			}else{
				--buf[cp];
			}
			last=0;
		}else if(buf[cp]=='<'){
			dp=1;
			last=1;
		}else{
			dp=0;
			last=1;
		}
		int prev=cp;
		cp=move.get(cp,dp);
		while(!stk.empty() && stk.back()>cp){
			backtime[stk.back()]=t+1;
			stk.pop_back();
		}
		if(cp<start){
			cp=-1;
			continue;
		}

		if(cp>=n){
			++t;
			break;
		}
		if(last && (buf[cp]=='<' || buf[cp]=='>')){
			move.erase(prev);
		}
	}
	REP(hoge,q){
		int l,r;cin>>l>>r;
		--l;
		int begin=vised[l],end=t;
		if(backtime[l]>=0){
			end=min(end,backtime[l]);
		}
		if(r<n) end=min(end,vised[r]);
		REP(i,10){
			printf("%d%c",putted[end][i]-putted[begin][i],i==9?'\n':' ');
		}
	}
	return 0;
}