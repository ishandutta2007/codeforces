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
map<pair<int,int>,vector<double>> M;
vector<vector<double>> V;
int id[501010];
double ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		double r=hypot(x,y);
		if(r==0) continue;
		int g=__gcd(abs(x),abs(y));
		x/=g;
		y/=g;
		M[{x,y}].push_back(r);
	}
	
	FORR(m,M) {
		sort(ALL(m.second));
		vector<double> W;
		W.push_back(0);
		int L=0,R=0;
		double LS=0,RS=0,sum=0;;
		while(L+R<min(K,(int)m.second.size())) {
			double ml=m.second[L];
			double mr=m.second[m.second.size()-1-R];
			double ladd=(LS+ml+RS)*(K-(L+R+1))+(ml*L-LS)+(RS-ml*R)+sum;
			double radd=(LS+mr+RS)*(K-(L+R+1))+(mr*L-LS)+(RS-mr*R)+sum;
			//cout<<L<<" "<<R<<" "<<ladd<<" "<<radd<<endl;
			if(ladd>radd) {
				LS+=ml;
				L++;
				W.push_back(ladd);
				sum+=(ml*L-LS)+(RS-ml*R);
			}
			else {
				RS+=mr;
				R++;
				W.push_back(radd);
				sum+=(mr*L-LS)+(RS-mr*R);
			}
		}
		
		V.push_back(W);
	}
	V.push_back({0,0});
	N=V.size();
	priority_queue<pair<double,int>> Q;
	FOR(i,N) {
		Q.push({V[i][1]-V[i][0],i});
	}
	while(K--) {
		ret+=Q.top().first;
		x=Q.top().second;
		//cout<<"!"<<Q.top().first<<" "<<x<<endl;
		Q.pop();
		id[x]++;
		if(id[x]+1<V[x].size()) {
			Q.push({V[x][id[x]+1]-V[x][id[x]],x});
		}
		
	}
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}