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


lint mid1[55],mid2[55];
int leftid[55],rightid[55];
lint con[55][2][2];
lint k,x,n,m;

int main(){
	cin>>k>>x>>n>>m;
	mid1[1]=1;
	mid2[2]=1;
	leftid[1]=rightid[1]=1;
	leftid[2]=rightid[2]=2;
	for(int i=3;i<=k;++i){
		leftid[i]=leftid[i-2];
		rightid[i]=rightid[i-1];

		mid1[i]=mid1[i-1]+mid1[i-2];
		mid2[i]=mid2[i-1]+mid2[i-2];

		REP(t,2) REP(t2,2) con[i][t][t2]=con[i-1][t][t2]+con[i-2][t][t2];
		++con[i][rightid[i-2]-1][leftid[i-1]-1];
	}
	dump(mid1[k]);dump(mid2[k]);

	REP(bit,(1<<4)){
		dump(bit);
		lint want=x,cnt=0;

		int begin[2]={0},end[2]={0};
		REP(s,2) REP(t,2){
			if(bit>>cnt&1){
				want-=con[k][s][t];
				end[s]=1;
				begin[t]=1;
			}
			++cnt;
		}
		if(want<0) continue;
		dump(want);
		int len1=n-begin[0]-end[0];
		int len2=m-begin[1]-end[1];

		if(len1<0 || len2<0) continue;
		
		lint x=-1,y=-1;
		for(int i=0;i<=len1/2;++i){
			lint want2=want-i*mid1[k];
			if(want2<0) continue;
			if(want2%mid2[k]==0 && want2/mid2[k]<=len2/2){
				x=i;
				y=want2/mid2[k];
				break;
			}
		}
		

		if(x>=0 && x<=len1/2 && y>=0 && y<=len2/2){

			string s1,s2;
			if(begin[0]) s1+='C';
			if(begin[1]) s2+='C';
			
			REP(i,x) s1+="AC";
			REP(i,y) s2+="AC";

			REP(i,len1-x*2) s1+='W';
			REP(i,len2-y*2) s2+='W';

			if(end[0]) s1+='A';
			if(end[1]) s2+='A';

			cout<<s1<<endl<<s2<<endl;
			return 0;
		}
	}

	cout<<"Happy new year!"<<endl;

	return 0;
}