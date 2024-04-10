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


int N,K;
int A[1<<17];

vector<int> hoge(vector<int> L,vector<int> R) {
	vector<int> res(4,-1<<29);
	int i,j;
	FOR(i,4) FOR(j,4) {
		int w1=i/2,l1=i%2;
		int w2=j/2,l2=j%2;
		
		int p=L[i]+R[j]+(w1+w2>0)+(l1+l2>0);
		res[w1*2+w2]=max(res[w1*2+w2],p+(w2+l1+l2>0));
		res[w2*2+w1]=max(res[w2*2+w1],p+(w1+l1+l2>0));
		res[w1*2+l1]=max(res[w1*2+l1],p+(w2+l1+l2>0));
		res[w1*2+l2]=max(res[w1*2+l2],p+(w2+l1+l2>0));
		res[w2*2+l1]=max(res[w2*2+l1],p+(w1+l1+l2>0));
		res[w2*2+l2]=max(res[w2*2+l2],p+(w1+l1+l2>0));
	}
	return res;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) {
		cin>>x;
		A[x-1]=1;
	}
	
	vector<vector<int>> V;
	for(i=0;i<1<<N;i+=2) {
		if(A[i]+A[i+1]==2) {
			V.push_back({-1<<29,-1<<29,-1<<29,1});
		}
		else if(A[i]+A[i+1]==1) {
			V.push_back({-1<<29,1,1,-1<<29});
		}
		else {
			V.push_back({0,-1<<29,-1<<29,-1<<29});
		}
	}
	
	while(V.size()>1) {
		vector<vector<int>> V2;
		for(i=0;i<V.size();i+=2) {
			V2.push_back(hoge(V[i],V[i+1]));
		}
		swap(V,V2);
	}
	
	int ma=0;
	cout<<max({V[0][0],V[0][1]+1,V[0][2]+1,V[0][3]+1})<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}