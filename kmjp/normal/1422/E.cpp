#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;
int N;
string ret[101010];
int len[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	vector<vector<int>> T;
	
	int num=0;
	for(i=N-1;i>=0;i--) {
		char c=S[i];
		if(T.size()&&T.back()[0]==c) {
			if((T.size()==1 || T[T.size()-2][0]<c)&&T.back()[1]==i+1) {
				T.back()[2]--;
				if(T.back()[2]==0) T.pop_back();
				num--;
			}
			else {
				T.back()[1]=i;
				T.back()[2]++;
				num++;
			}
		}
		else {
			T.push_back({c,i,1});
			num++;
		}
		
		len[i]=num;
		if(num>10) {
			x=T.size()-1;
			y=T[x][2];
			FOR(j,5) {
				ret[i].push_back(T[x][0]);
				y--;
				if(y==0) {
					x--;
					y=T[x][2];
				}
			}
			ret[i]+="...";
			if(T[0][2]==1) {
				ret[i].push_back(T[1][0]);
				ret[i].push_back(T[0][0]);
			}
			else {
				ret[i].push_back(T[0][0]);
				ret[i].push_back(T[0][0]);
			}
			
		}
		else {
			FORR(t,T) FOR(j,t[2]) ret[i]+=(char)t[0];
			reverse(ALL(ret[i]));
		}
	}
	
	FOR(i,N) {
		cout<<len[i]<<" "<<ret[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}