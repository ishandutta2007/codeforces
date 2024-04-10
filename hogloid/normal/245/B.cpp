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
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
string s;
int main(){
	cin>>s;
	REP(i,s.size()){
		if(s.substr(i,3)=="ftp"){
			s.insert(i+3,"://");
			break;
		}else if(s.substr(i,4)=="http"){
			s.insert(i+4,"://");
			break;
		}
	}
	for(int i=s.size()-2;i>=0;--i) if(s.substr(i,2)=="ru"){
		s.insert(i,".");
		if(i+3<s.size()) s.insert(i+3,"/");
		break;
	}
	cout<<s<<endl;

	return 0;
}