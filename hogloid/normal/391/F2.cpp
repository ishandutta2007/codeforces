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
#define dump(x)  cerr << (#x) << " = " << (x) << endl
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
const lint INF=1e18;
int n,k;
set<pair<lint,pi> >inter;
set<int> exist;
lint ar[100005];
int main(){
	cin>>n>>k;
	k+=2;
	int m=0;
	ar[0]=INF;
	ar[1]=2*INF;
	REP(i,n){
		ar[i+2]=readL();
	}

	ar[n+2]=-INF;
	ar[n+3]=0;

	n+=4;

	lint res=0;
	REP(i,n){
		int j=i;
		while(j+1<n && ar[j+1]<=ar[j]){
			++j;
		}
		int k=j+1;
		while(k+1<n && ar[k+1]>=ar[k]) ++k;
		if(k<n){
			res+=ar[k]-ar[j];
			ar[m++]=ar[j];
			ar[m++]=ar[k];
		}
		i=k;
	}
	REP(i,m) exist.insert(i);
	n=m;

	REP(i,m/2) inter.insert(mp(ar[i*2+1]-ar[i*2],mp(i*2,0)));
	REP(i,m/2-1) inter.insert(mp(ar[i*2+1]-ar[i*2+2],mp(i*2+1,1)));
	
	REP(hoge,m/2-k){
		auto it=inter.begin();
		res-=it->fr;
		if(it->sc.sc==0){
			int pos=it->sc.fr;
			auto p1=exist.find(pos);
			dump(*p1);
			auto p2=p1;++p2;

			auto q2=p1;--q2;
			auto q1=q2;--q1;

			auto r1=p2;++r1;
			auto r2=r1;++r2;
			
			inter.erase(inter.begin());
			inter.erase(mp(-(ar[*p1]-ar[*q2]),mp(*q2,1)));
			inter.erase(mp(-(ar[*r1]-ar[*p2]),mp(*p2,1)));

			inter.insert(mp(-(ar[*r1]-ar[*q2]),mp(*q2,1)));



			exist.erase(p2);
			exist.erase(pos);
		}else{
			int pos=it->sc.fr;
			auto p2=exist.find(pos);
			auto p1=p2;--p1;
			
			inter.erase(inter.begin());
			inter.erase(mp(ar[*p2]-ar[*p1],mp(*p1,0)));


			auto q1=p2;++q1;
			auto q2=q1;++q2;

			inter.erase(mp(ar[*q2]-ar[*q1],mp(*q1,0)));

			inter.insert(mp(ar[*q2]-ar[*p1],mp(*p1,0)));

			exist.erase(p2);

			q1=exist.lower_bound(pos);
			exist.erase(q1);

		}
	}
	res-=2*INF;
	cout<<res<<endl;




	return 0;
}