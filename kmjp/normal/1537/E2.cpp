#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,K;
string S;

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	auto Z=Zalgo(S);
	
	int cur=1;
	for(i=1;i<N;i++) {
		if(S[i]>S[i%cur]) {
			break;
		}
		else if(S[i]<S[i%cur]) {
			cur=i+1;
		}
		else if(cur*2==i+1) {
			cur=i+1;
		}
		else {
			assert(cur*2>i+1);
			int k=i+1-cur;
			
			if(Z[cur]<k) {
				if(S[cur+Z[cur]]<S[Z[cur]]) cur=i+1;
			}
			else if(Z[k]<cur) {
				if(S[k+Z[k]]>S[Z[k]]) cur=i+1;
			}
			else {
				cur=i+1;
			}
		}
	}
	
	FOR(i,K) cout<<S[i%cur];
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}