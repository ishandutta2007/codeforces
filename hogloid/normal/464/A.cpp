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

int n,p;
char s[1005];

bool able[1005][30][30][2];//len >=2
//[1]:over [0]:equal
int main(){
	
	cin>>n>>p;
	scanf("%s",s);
	if(n==1){
		if(s[0]=='a'+p-1) puts("NO");
		else printf("%c\n",s[0]+1);
	}else{

		REP(i,p) REP(j,p) if(i!=j){
			able[n-2][i][j][1]=1;
			if(mp(i,j)>mp(s[n-2]-'a',s[n-1]-'a')) able[n-2][i][j][0]=1;
		}

		for(int i=n-3;i>=0;--i) REP(j,p) REP(k,p) if(j!=k){
			REP(l,p) if(k!=l && j!=l){
				able[i][j][k][1]|=able[i+1][k][l][1];
				if(j==s[i]-'a') able[i][j][k][0]|=able[i+1][k][l][0];
				else if(j>s[i]-'a') able[i][j][k][0]|=able[i+1][k][l][1];
			}
		}
		
		string res;
		REP(i,p) REP(j,p) if(able[0][i][j][0]){
			res+=i+'a';
			res+=j+'a';

			
			int i2=i,j2=j,cur=0,sign=0;
			while(cur<n-2){
				if(i2>s[cur]-'a') sign=1;
				REP(k,p) if(able[cur+1][j2][k][sign] && k!=i2 && k!=j2){
					res+=k+'a';
					i2=j2;
					j2=k;
					++cur;
					break;
				}
			}
			cout<<res<<endl;

			return 0;
		}
		puts("NO");
	}



	return 0;
}