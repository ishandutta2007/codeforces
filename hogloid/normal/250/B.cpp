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
string s,ans;;
vector<string> block;
string fix(string a){
	while(a.size()<4) a='0'+a;
	return a;
}
int main(){
	cin>>n;
	while(n--){
		ans.clear();
		cin>>s;
		block.clear();
		string tmp;
		REP(i,s.size()){
			tmp.clear();
			int j=i;
			while(j<s.size() && s[j]!=':') tmp+=s[j],++j;
			block.pb(tmp);
			i=j;
		}
		int more=8-block.size();
		if(more<0){
			REP(i,block.size()) if(block[i]==""){
				block.erase(block.begin()+i);
				break;
			}
			more=0;
		}
		int first=1;
		REP(i,block.size()){
			if(!first) ans+=':';
			first=0;
			ans+=fix(block[i]);
			if(more>0 && block[i]==""){
				--i;
				--more;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}