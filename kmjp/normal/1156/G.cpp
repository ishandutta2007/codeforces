#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
set<string> S;
string L[1010],R1[1010],R2[1010],O[1010];
map<string,string> name;
string lastres;
map<string,vector<string>> M;
map<string,int> line;
map<string,string> cache;

string nex(string s) {
	int i=s.size()-1;
	while(1) {
		s[i]++;
		if(s[i]=='z'+1) {
			s[i]='a';
			i--;
		}
		else break;
	}
	return s;
	
}


string tag() {
	static string s="aaaa";
	s=nex(s);
	while(S.count(s)) s=nex(s);
	
	return s;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>s;
		x=s.find('=');
		L[i]=s.substr(0,x);
		s=s.substr(x+1);
		x=s.find_first_of("$^#&");
		if(x!=string::npos) {
			R1[i]=s.substr(0,x);
			O[i]=s.substr(x,1);
			R2[i]=s.substr(x+1);
			
			if(name.count(R1[i])==0) name[R1[i]]=R1[i];
			if(name.count(R2[i])==0) name[R2[i]]=R2[i];
			R1[i]=name[R1[i]];
			R2[i]=name[R2[i]];
			
			name[L[i]]=tag();
			
			string tmp=R1[i]+O[i]+R2[i];
			if(cache.count(tmp)) {
				name[L[i]]=cache[tmp];
				if(L[i]=="res") lastres=name[L[i]];
				L[i]="";
			}
			else {
				cache[tmp]=name[L[i]];
			}
			
		}
		else {
			R1[i]=s;
			if(L[i]==R1[i]) {
				L[i]=="";
				continue;
			}
			if(name.count(R1[i])==0) name[R1[i]]=R1[i];
			R1[i]=name[R1[i]];
			name[L[i]]=R1[i];
		}
		if(L[i]=="res") lastres=name[L[i]];
		L[i]=name[L[i]];
		
		//cout<<L[i]<<" "<<R1[i]<<" "<<O[i]<<" "<<R2[i]<<endl;
	}
	
	if(lastres=="") return _P("0\n");
	
	set<string> T;
	T.insert(lastres);
	vector<string> ret;
	for(i=N-1;i>=0;i--) {
		if(L[i].size()&&T.count(L[i])) {
			if(O[i].size()) {
				if(L[i]==lastres) {
					L[i]="res";
				}
				ret.push_back(L[i]+"="+R1[i]+O[i]+R2[i]);
				T.insert(R1[i]);
				T.insert(R2[i]);
			}
		}
	}
	
	if(ret.empty()&&lastres!="res") ret.push_back("res="+lastres);
	
	cout<<ret.size()<<endl;
	reverse(ALL(ret));
	FORR(r,ret) cout<<r<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}