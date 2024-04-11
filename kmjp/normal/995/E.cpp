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

ll U,V,mo;

ll rev(ll a) {
	ll r=1, n=mo-2; a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

map<ll,int> D[2];
map<ll,int> F[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>U>>V>>mo;
	D[0][U]=0;
	D[1][V]=0;
	FOR(i,2) {
		queue<int> Q;
		Q.push(D[i].begin()->first);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			if(D[i][x]>=15) continue;
			FOR(j,3) {
				if((j^i)==0) y=(x+1)%mo;
				if((j^i)==1) y=(x+mo-1)%mo;
				if(j==2) {
					if(x==0) continue;
					y=rev(x);
				}
				if(D[i].count(y)) continue;
				D[i][y]=D[i][x]+1;
				F[i][y]=j;
				Q.push(y);
			}
		}
	}
	
	FORR(d0,D[0]) FORR(d1,D[1]) {
		int lef=200-d0.second-d1.second;
		if(min(abs(d0.first-d1.first),mo-abs(d0.first-d1.first))<=lef) {
			vector<int> VV;
			int cur=d0.first;
			while(cur!=U) {
				VV.push_back(F[0][cur]+1);
				if(F[0][cur]==0) cur=(cur+mo-1)%mo;
				else if(F[0][cur]==1) cur=(cur+1)%mo;
				else if(F[0][cur]==2) cur=rev(cur);
			}
			reverse(ALL(VV));
			
			x=d0.first;
			y=d1.first;
			if(x<y && y-x>lef) x+=mo;
			if(x>y && x-y>lef) y+=mo;
			while(x!=y) {
				if(y>x) VV.push_back(1), x++;
				else if(x>y) VV.push_back(2), x--;
			}
			
			
			cur=d1.first;
			while(cur!=V) {
				VV.push_back(F[1][cur]+1);
				if(F[1][cur]==0) cur=(cur+1)%mo;
				else if(F[1][cur]==1) cur=(cur+mo-1)%mo;
				else if(F[1][cur]==2) cur=rev(cur);
			}
			cout<<VV.size()<<endl;
			FORR(v,VV) cout<<v<<" ";
			cout<<endl;
			return;
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}