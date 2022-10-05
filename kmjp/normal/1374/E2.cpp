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

int N,K,M;
vector<pair<ll,int>> C[4];

multiset<ll> X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>r>>x>>y;
		C[x*2+y].push_back({r,i});
	}
	
	
	FOR(i,4) {
		while(C[i].size()<M+1) C[i].push_back({1LL<<40,0});
		sort(ALL(C[i]));
	}
	
	ll ret=1LL<<60;
	vector<int> ri(4),now(4);
	ll sum=0;
	int num=2*K;
	now[1]=now[2]=K;
	FOR(i,K) sum+=C[1][i].first+C[2][i].first;
	while(num<M) {
		FOR(i,3) {
			if(C[i][now[i]].first<=C[(i+1)%3][now[(i+1)%3]].first && C[i][now[i]].first<=C[(i+2)%3][now[(i+2)%3]].first) {
				sum+=C[i][now[i]].first;
				now[i]++;
				num++;
				break;
			}
		}
	}
	if(num==M) ret=sum, ri=now;
	//cout<<i<<" "<<num<<" "<<sum<<" "<<now[0]<<" "<<now[1]<<" "<<now[2]<<" "<<now[3]<<endl;
	for(i=1;i<=M;i++) {
		sum+=C[3][i-1].first;
		now[3]++;
		num++;
		while(num>M) {
			int tar=-1;
			vector<int> cand;
			if(now[0]) cand.push_back(0);
			if(now[1]>max(0,K-i)) cand.push_back(1);
			if(now[2]>max(0,K-i)) cand.push_back(2);
			if(cand.empty()) break;
			FORR(c,cand) {
				int ok=1;
				FORR(d,cand) if(C[c][now[c]-1].first<C[d][now[d]-1].first) ok=0;
				if(ok==1) tar=c;
			}
			sum-=C[tar][now[tar]-1].first;
			now[tar]--;
			num--;
		}
		while(num<M) {
			int tar=-1;
			vector<int> cand={0,1,2};
			FORR(c,cand) {
				int ok=1;
				FORR(d,cand) if(C[c][now[c]].first>C[d][now[d]].first) ok=0;
				if(ok==1) tar=c;
			}
			sum+=C[tar][now[tar]].first;
			now[tar]++;
			num++;
		}
		for(j=1;j<=2;j++) {
			while(num==M && now[j]>max(0,K-i)) {
				if(C[0][now[0]].first<C[j][now[j]-1].first) {
					sum-=C[j][now[j]-1].first;
					sum+=C[0][now[0]].first;
					now[j]--;
					now[0]++;
				}
				else {
					break;
				} 
			}
		}
		//cout<<i<<" "<<num<<" "<<sum<<" "<<now[0]<<" "<<now[1]<<" "<<now[2]<<" "<<now[3]<<endl;
		if(num==M && ret>sum) ret=sum, ri=now;
	}
	
	
	
	if(ret>=1LL<<40) {
		cout<<-1<<endl;
		return;
	}
	cout<<ret<<endl;
	FOR(i,4) FOR(x,ri[i]) cout<<C[i][x].second+1<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}