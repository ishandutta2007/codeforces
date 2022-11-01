#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
char s[200005],s2[200005];
vector<int> pos[30],pos2[30];
vector<lint> Lsum[30],Rsum[30];
int main(){
	int n;scanf("%d",&n);
	scanf("%s%s",s,s2);
	REP(i,n) pos[s[i]-'A'].pb(i);
	REP(i,n) pos2[s2[i]-'A'].pb(i);
	lint nl=n;
	lint all=nl*(nl+1)*(2*nl+1)/6;
	REP(i,26){
		Lsum[i].resize(pos2[i].size()+2);
		Rsum[i]=Lsum[i];
		REP(j,pos2[i].size()){
			Lsum[i][j]=(j==0?0:Lsum[i][j-1])+pos2[i][j]+1;
		}
		for(int j=((int)pos2[i].size())-1;j>=0;--j){
			Rsum[i][j]=Rsum[i][j+1]+(n-pos2[i][j]);
		}
	}

	long double res=0;
	REP(i,26){
		int k=-1;
		REP(j,pos[i].size()){
			while(k+1<(int)pos2[i].size() && pos2[i][k+1]<pos[i][j]) ++k;
			if(k>=0) res+=Lsum[i][k]*(n-pos[i][j])/(long double)all;
			if(k+1<(int)pos2[i].size()) res+=Rsum[i][k+1]*(pos[i][j]+1)/(long double)all;
		}
	}
	printf("%.10f\n",(double)res);

	return 0;
}