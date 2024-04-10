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

int n1,n2;
pair<int,pi> vert[50005],horz[50005];


int main(){
	cin>>n1>>n2;
	REP(i,n1){
		int x,y,l;scanf("%d%d%d",&x,&y,&l);
		vert[i]=mp(x,mp(y,y+l));
	}
	
	int ans=0;
	REP(i,n2){
		int x,y,l;scanf("%d%d%d",&x,&y,&l);
		horz[i]=mp(y,mp(x,x+l));

		REP(j,n1){
			int vx=vert[j].fr,vy=vert[j].sc.fr,vy2=vert[j].sc.sc;

			int tmp=min({vx-x,x+l-vx,vy2-y,y-vy});
			chmax(ans,tmp);
		}

	}
	cout<<ans<<endl;



	return 0;
}