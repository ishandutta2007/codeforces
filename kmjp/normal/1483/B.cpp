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

int T,N;
int A[101010];


deque<int> D[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) D[i].clear();
		deque<int> Q;
		vector<int> R;
		int pre=-1,fir=-1;
		FOR(i,N) {
			cin>>A[i];
			
			if(pre==-1) {
				Q.push_back(i);
				D[i].push_back(i);
				pre=fir=i;
			}
			else {
				if(__gcd(A[pre],A[i])==1) {
					R.push_back(i);
					pre=-1;
				}
				else {
					D[fir].push_back(i);
					pre=i;
				}
			}
		}
		if(pre!=-1) {
			Q.push_front(Q.back());
			Q.pop_back();
		}
		
		int up=0;
		while(up<Q.size()+1) {
			up++;
			if(Q.size()==1) {
				x=Q.front();
				//cout<<"!"<<D[x].size()<<endl;
				if(__gcd(A[D[x].back()],A[D[x][0]])==1) {
					R.push_back(D[x][0]);
					D[x].pop_front();
					if(D[x].empty()) Q.pop_front();
					up=0;
				}
				else {
					break;
				}
			}
			else if(Q.size()>1) {
				x=Q.front();
				Q.pop_front();
				y=Q.front();
				//cout<<"!!"<<D[x].size()<<" "<<D[y].size()<<endl;
				if(__gcd(A[D[x].back()],A[D[y][0]])==1) {
					R.push_back(D[y][0]);
					D[y].pop_front();
					if(D[y].empty()) Q.pop_front();
					up=0;
					Q.push_back(x);
				}
				else {
					while(D[x].size()) D[y].push_front(D[x].back()),D[x].pop_back();
					up=0;
				}
			}
		}
		
		
		cout<<R.size();
		FORR(r,R) cout<<" "<<r+1;
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}