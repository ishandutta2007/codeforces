#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
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

int n;
string t;
string str[100005];

void seek(int& pos,string& s){
	REP(i,s.size()){
		if(pos>=t.size()){
			pos=INF;continue;
		}
		while(pos<t.size() && t[pos]!=s[i]) ++pos;
		++pos;
	}
}
		
int main(){
	cin>>n;
	REP(i,n) cin>>str[i];

	cin>>t;
	
	string heart="<3";
	int m=t.size(),pos=0;
	REP(i,n){
		seek(pos,heart);
		seek(pos,str[i]);
	}
	seek(pos,heart);
	if(pos>t.size()) puts("no");
	else puts("yes");

	return 0;
}