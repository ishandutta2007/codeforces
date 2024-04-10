#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<sstream>
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
lint solve(int len,string pref){
	if(pref.empty()) pref="1";
	map<int,int> moe;
	vector<int> factor;
	int tmp=len;
	for(int i=2;i*i<=tmp;++i) if(tmp%i==0){
		factor.pb(i);
		while(tmp%i==0) tmp/=i;
	}
	if(tmp>1) factor.pb(tmp);
	int m=factor.size();
	REPN(i,1<<m,1){
		int d=1,s=-1;
		REP(j,m) if(i>>j&1){
			d*=factor[j];
			s*=-1;
		}
		moe[d]=s;
	}

	__typeof(moe.begin()) it=moe.begin();
	lint res=0;
	while(it!=moe.end()){
		int len2=len/it->fr;
		if(len2>=pref.size()){
			res+=(1ll<<(len2-pref.size()))*it->sc;
		}else{
			int flag=0;
			REP(i,pref.size()) if(pref[i%len2]!=pref[i]){
				flag=1;break;
			}
			if(!flag) res+=it->sc;
		}
		++it;
	}
	return res;
}
lint solve2(lint a){//..a)
	string s;
	while(a){
		s+=((a&1)+'0');
		a>>=1;
	}
	reverse(ALL(s));

	lint res=0;
	for(int i=1;i<s.size();++i) res+=solve(i,"");
	REPN(i,s.size(),1) if(s[i]=='1'){
		res+=solve(s.size(),s.substr(0,i)+"0");
	}
	return res;
}
int main(){
	lint l,r;cin>>l>>r;
	cout<<solve2(r+1)-solve2(l)<<endl;
	return 0;
}