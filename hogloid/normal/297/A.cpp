#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl

#define sz(x) ((int)x.size())
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
string a,b;
int main(){
	cin>>a>>b;
	int n=a.size(),m=b.size();
	
	REP(hoge,2005){
		int j=n-1;
		int fail=0;
		for(int i=sz(b)-1;i>=0;--i){
			if(j<0){
				fail=1;
				break;
			}
			if(b[i]=='0'){
				if(a[j]!='0') fail=1;
				--j;
			}else if(b[i]=='1'){
				if(a[j]!='1') fail=1;
				--j;
			}else{
				while(j>=0 && a[j]=='0') --j;
				if(j<0) fail=1;
				--j;
			}
		}
		if(!fail){
			puts("YES");
			return 0;
		}
			

		int sum=0;
		REP(j,sz(b)-1) if(b[j]!='0') sum^=1;
		
		char c=*b.rbegin();
		int code=c-'0';
		if(c=='2') code=1;
		if(sum!=code){
			b='2'+b;
		}
		b.resize(b.size()-1);

	}
	puts("NO");


	return 0;
}