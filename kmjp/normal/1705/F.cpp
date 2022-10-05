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

int N;
vector<int> V;
int ret[1010];
int ask(vector<int> V) {
	FORR(v,V) cout<<"FT"[v];
	cout<<endl;
	int ret;
	cin>>ret;
	if(ret==N) exit(0);
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> X,Y;
	FOR(i,N) {
		X.push_back(1);
		Y.push_back((i+1)%2);
	}
	int tx=ask(X);
	int ty=ask(Y);
	vector<int> unfixed;
	FOR(i,N) if(i>=N/3*2) unfixed.push_back(i);
	
	FOR(i,N/3) {
		vector<int> X2=X;
		X2[2*i]=X2[2*i+1]=0;
		k=ask(X2);
		if(k>tx) {
			ret[2*i]=ret[2*i+1]=0;
		}
		else if(k<tx) {
			ret[2*i]=ret[2*i+1]=1;
		}
		else {
			vector<int> Y2=Y;
			r=-1;
			if(unfixed.size()) {
				r=unfixed.back();
				unfixed.pop_back();
			}
			Y2[2*i]=0;
			Y2[2*i+1]=1;
			if(r!=-1) {
				Y2[r]=Y[r]^1;
				k=ask(Y2)-ty;
				if(k==3) {
					ret[2*i]=Y2[2*i];
					ret[2*i+1]=Y2[2*i+1];
					ret[r]=Y2[r];
				}
				if(k==1) {
					ret[2*i]=Y2[2*i];
					ret[2*i+1]=Y2[2*i+1];
					ret[r]=Y2[r]^1;
				}
				if(k==-1) {
					ret[2*i]=Y2[2*i]^1;
					ret[2*i+1]=Y2[2*i+1]^1;
					ret[r]=Y2[r];
				}
				if(k==-3) {
					ret[2*i]=Y2[2*i]^1;
					ret[2*i+1]=Y2[2*i+1]^1;
					ret[r]=Y2[r]^1;
				}
			}
			else {
				k=ask(Y2);
				if(k>ty) {
					ret[2*i]=Y2[2*i];
					ret[2*i+1]=Y2[2*i+1];
				}
				else {
					ret[2*i]=Y2[2*i]^1;
					ret[2*i+1]=Y2[2*i+1]^1;
				}
			}
		}
	}
	FORR(r,unfixed) {
		vector<int> X2=X;
		X2[r]=0;
		k=ask(X2);
		if(k<tx) ret[r]=1;
	}
	
	FOR(i,N) X[i]=ret[i];
	ask(X);
	//assert(0);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}