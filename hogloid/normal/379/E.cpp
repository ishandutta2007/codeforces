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


int n,k;

int hei[305][305];

int idx[305];
int h1[305],h2[305];

bool cmp(int a,int b){
	return (h2[a]-h1[a])<(h2[b]-h1[b]);
}
int pos[305];
bool enable[305];
const double INF=1e100;
double getX(int p,int q){
	if(h2[p]-h1[p]==h2[q]-h1[q]){
		if(h2[p]<=h2[q]) return -INF;
		else return INF;
	}
	int h3=h1[q]-h1[p],h4=h2[q]-h2[p];
	return -h3/(double)(h4-h3);
}

double res[305];
int stk[305];
int main(){
	cin>>n>>k;
	REP(i,n) REP(j,k+1) scanf("%d",&hei[i][j]);

	REP(i,k){
		CLR(enable);
		REP(j,n) h1[j]=hei[j][i],h2[j]=hei[j][i+1];

		REP(j,n) idx[j]=j;
		sort(idx,idx+n,cmp);
		REP(j,n) pos[idx[j]]=j;

		REP(j,n){
			int cur=j;
			dump(j);
			int cnt=0;
			REP(k,n) if(enable[idx[k]]){
				int who=idx[k];
				while(cnt>=2){
					double X=getX(stk[cnt-1],who),X2=getX(stk[cnt-2],stk[cnt-1]);
					if(X<=X2) --cnt;
					else break;
				}
				stk[cnt++]=who;
			}
			enable[j]=1;
			dump(cur);
			if(cnt==0) {
				res[j]+=(h2[cur]+h1[cur])/2.0;
			}else{
				REP(k,cnt){
					double st=0,en=1;
					dump(k);
					dump(stk[k]);dump(stk[k+1]);
					dump(getX(stk[k],stk[k+1]));
					if(k+1<cnt) chmin(en,getX(stk[k],stk[k+1]));
					if(k-1>=0) chmax(st,getX(stk[k-1],stk[k]));
					if(st<=en){
						dump(st);dump(en);
						int h3=h1[cur]-h1[stk[k]],h4=h2[cur]-h2[stk[k]];
						double h5=(h4*st+h3*(1-st)),h6=(h4*en+h3*(1-en));
						if(h5>=0 && h6>=0){
							res[cur]+=(h5+h6)/2.0*(en-st);
						}else if(h6<=0 && h5<=0) ;
						else{
							if(h5<0) swap(h5,h6);
							res[cur]+=h5*h5/(h5-h6)*(en-st)/2.0;;
						}
					}
				}
			}
		}
	}
	REP(i,n) printf("%.10f\n",res[i]);












	return 0;
}