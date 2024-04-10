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
char s[10005];
vector<string> words;
int main(){
	gets(s);
	int n=strlen(s);

	int i=0;
	string tmp;
	while(i<n){
		while(i<n && s[i]==' ') ++i;
		if(i==n) break;
		tmp.clear();
		if(s[i]<'a' || s[i]>'z') tmp+=s[i],++i;
		else while(i<n && s[i]>='a' && s[i]<='z') tmp+=s[i],++i;
		words.pb(tmp);
	}

	REP(i,words.size()){
		cout<<words[i];
		if(i+1<words.size() && (words[i+1][0]>='a' && words[i+1][0]<='z')) putchar(' ');
	}
	putchar('\n');


	return 0;
}