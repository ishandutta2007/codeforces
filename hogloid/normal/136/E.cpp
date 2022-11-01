#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cstdlib>
#include<cmath>
#define REP(num,num2) for(int num=0;num<(int)(num2);++num)
#define REPN(num,num2,init) for(int num=init;num<(int)(num2);++num)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define ITR(tp) __typeof((tp).begin())
#define SZ(t) ((int)t.size())
#define ALL(typ) (typ).begin(),(typ).end()
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
#define RANGE(t,n) (t).begin(),(t).begin()+n
#define fr first
#define sc second
#define SPR(x) ((x)*(x))
#define INF ((int)1e9)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
typedef vector<string> vs;
const double PI  = acos(-1.0);
int main(){
	string s,prev;cin>>s;
	int len=SZ(s);
	int max1=0,max0=0,min0=0;
	REP(i,len){
		if(s[i]=='0') ++max0;
		else if(s[i]=='1') ++max1;
		else ++max0,++max1;
	}
	min0=len-max1;
	if(max0>=len-max0+1) puts("00");
	prev=s;
	if(s[len-1]!='0'){
		s[len-1]='1';
		int max0_=0,min0_=0;
		REP(i,len){
			if(s[i]=='0') ++max0_,++min0_;
			else if(s[i]=='?') ++max0_;
		}
		if(min0_<=len/2 && len/2<=max0_) puts("01");
		s=prev;
	}
	if(s[len-1]!='1'){
		s[len-1]='0';
		int max0_=0,min0_=0;
		REP(i,len){
			if(s[i]=='0') ++max0_,++min0_;
			else if(s[i]=='?') ++max0_;
		}
		if(min0_<=len/2 && len/2<=max0_) puts("10");
		s=prev;
	}
	if(max1>=len-max1+2) puts("11");
	return 0;
}