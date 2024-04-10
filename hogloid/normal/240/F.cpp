#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<fstream>
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
int n,m;
char s[100005],ans[100005];
struct segtree{
	int sum[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		memset(sum,0,sizeof(sum));
	}
	void set(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			sum[i]=v*(r-l);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		if(sum[i]==r-l) sum[i*2+1]=sum[i*2+2]=md-l;
		else if(sum[i]==0) sum[i*2+1]=sum[i*2+2]=0;

		set(a,b,i*2+1,l,md,v);
		set(a,b,i*2+2,md,r,v);
		sum[i]=sum[i*2+1]+sum[i*2+2];
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return sum[i];
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		if(sum[i]==r-l) sum[i*2+1]=sum[i*2+2]=md-l;
		else if(sum[i]==0) sum[i*2+1]=sum[i*2+2]=0;

		return query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r);
	}
};
segtree seg[30];
int num[30];
int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>n>>m;
	cin>>s;
	REP(i,26){
		seg[i].init(n);
	}
	REP(i,n){
		seg[s[i]-'a'].set(i,i+1,0,0,seg[0].n,1);
	}

	REP(hoge,m){
		int l,r;cin>>l>>r;
		--l;
		int odd=0;
		REP(i,26){
			num[i]=seg[i].query(l,r,0,0,seg[i].n);
			if(num[i]&1) ++odd;
		}
		if(odd>1) continue;
		int adv=0;
		int med=(l+r)/2;
		REP(i,26){
			seg[i].set(l,r,0,0,seg[i].n,0);
			seg[i].set(l+adv,l+adv+num[i]/2,0,0,seg[i].n,1);
			seg[i].set(r-adv-num[i]/2,r-adv,0,0,seg[i].n,1);
			adv+=num[i]/2;
			if(num[i]&1){
				seg[i].set(med,med+1,0,0,seg[i].n,1);
			}
		}
	}
	REP(i,n) REP(j,26) if(seg[j].query(i,i+1,0,0,seg[j].n)==1) ans[i]='a'+j;

	cout<<ans<<endl;


	return 0;
}