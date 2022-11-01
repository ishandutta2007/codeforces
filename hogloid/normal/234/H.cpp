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
int n[2];
int card[2][100005];
vector<int> perm,flip;
int adv[2];
int solve(int cur,int init){
	perm.clear();
	perm.pb(init);
	flip.clear();
	int res=0;
	while(adv[0]<n[0] || adv[1]<n[1]){
		if(cur==card[0][adv[0]]){
			perm.pb(adv[0]);
			++adv[0];
		}else if(cur==card[1][adv[1]]){
			perm.pb(adv[1]+n[0]);
			++adv[1];
		}else{
			flip.pb(adv[0]+adv[1]);
			cur^=1;
			++res;
		}
	}
	if(cur==1){
		++res;
		flip.pb(adv[0]+adv[1]);
	}

	return res;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	cin>>n[0];
	REP(i,n[0]) cin>>card[0][i];
	cin>>n[1];
	REP(i,n[1]) cin>>card[1][i];

	card[0][n[0]]=card[1][n[1]]=-INF;
	
	adv[0]=0;adv[1]=1;
	int A,B;
	A=solve(card[1][0],n[0]);
	
	adv[0]=1;adv[1]=0;
	B=solve(card[0][0],0);

	if(A<B){
		adv[0]=0;adv[1]=1;
		solve(card[1][0],n[0]);
	}
	
	REP(i,perm.size()) cout<<perm[i]+1<<' ';
	cout<<endl;
	cout<<min(A,B)<<endl;
	REP(i,flip.size()) cout<<flip[i]<<' ';
	cout<<endl;


	return 0;
}