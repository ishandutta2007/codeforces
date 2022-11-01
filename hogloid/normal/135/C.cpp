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
char s[100005];
int len;
bool equable(int a,int b,int c){
	if(len%2==0){
		if(a+c>=b && a<=b+c) return true;
		return false;
	}else{
		if(a+c>=b-1 && a<=b-1+c) return true;
		return false;
	}
}

int main(){
	scanf("%s",s);
	len=strlen(s);
	
	int a=0,b=0,c=0;
	REP(i,len){
		if(s[i]=='0') ++a;
		if(s[i]=='1') ++b;
	}
	int zero=-1,one=-1,que=-1;
	REP(i,len){
		if(s[i]=='0') zero=i;
		if(s[i]=='1') one=i;
		if(s[i]=='?') que=i;
	}
	c=len-a-b;
	vector<string> ans;
	{//00
		if(len%2==0){
			if(a+c>=2+b) ans.pb("00");
		}else{
			if(a+c>=2+b-1) ans.pb("00");
		}
	}
	if(equable(a,b,c)){
		{//01
			if(max(que,zero)<one) ans.pb("01");
			else if(max(one,zero)<que){
				if(equable(a,b+1,c-1)) ans.pb("01");
			}
		}
		{//10
			if(max(que,one)<zero) ans.pb("10");
			else if(max(one,zero)<que){
				if(equable(a+1,b,c-1)) ans.pb("10");
			}
		}
	}
	{//11
		if(len%2==0){
			if(b+c>=2+a) ans.pb("11");
		}else{
			if(b+c-1>=2+a) ans.pb("11");
		}
	}

	REP(i,ans.size()) printf("%s\n",ans[i].c_str());
			
		

	return 0;
}