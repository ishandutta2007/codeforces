#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
#include<cstdio>
#include<cstring>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
int n;
vector<string> cur;
char tmp[10];
int main(){
	scanf("%d",&n);
	cur.pb("");
	REP(hoge,n){
		scanf("%s",tmp);
		if(tmp[0]=='p'){
			REP(i,cur.size()) cout<<cur[i]<<'/';
			cout<<endl;
		}else{
			string dir;cin>>dir;

			if(dir[0]=='/'){
				cur.clear();
				cur.pb("");
			}
			REP(i,dir.size()) if(dir[i]=='/') dir[i]=' ';
			string s;
			stringstream ss;ss<<dir;
			while(ss>>s){
				if(s=="..") cur.pop_back();
				else cur.pb(s);
			}
		}
	}

	return 0;
}