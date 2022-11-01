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
static const int INF =1000000005; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,t;
char s[1000005];
pi range[1000005];
int m;
lint cost(int k){
	vector<int> toput;
	int have=k,last=0,add=0;
	m=0;
	REP(i,n) if(s[i]!='.'){
		if(s[i]=='S'){
			if(!toput.empty()){
				add=i;
				if(toput.size()==1){
					range[m++]=mp(toput.back(),i);
				}
				toput.pop_back();
			}else ++have;
		}else{
			add=i;
			if(have==0) toput.pb(i);
			else{
				--have;
			}
		}
	}
	if(toput.empty()==false) return INF;
	
	lint res;
	lint cur=add+1;
	REP(i,m) cur+=(range[i].sc-range[i].fr)*2;
	res=cur;
	range[m].fr=add;
	for(int i=m-1;i>=0;--i){
		cur-=(range[i].sc-range[i].fr);
		cur+=(range[i+1].fr-range[i].sc);
		res=min(res,cur);
	}

	return res;
}

int main(){
	cin>>n>>t;
	scanf("%s",s);


	
	int lb=-1,ub=1000000;
	
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		if(cost(md)<=t) ub=md;
		else lb=md;
	}
	if(ub==1000000) ub=-1;
	printf("%d\n",ub);

	return 0;
}