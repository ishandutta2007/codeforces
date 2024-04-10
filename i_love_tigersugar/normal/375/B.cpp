#include<algorithm>
#include<cstdio>
#include<vector>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
class BIT {
	private:
	vector<int> v;
	int n;
	public:
	BIT() {
		v.clear();
		n=0;
	}
	BIT(int _n) {
		n=_n;
		v=vector<int>(_n+7,0);
	}
	void add(int x) {
		while (x<=n) {
			v[x]++;
			x+=x&(-x);
		}
	}
	int get(int x) {
		int ret=0;
		while (x>0) {
			ret+=v[x];
			x=x&(x-1);
		}
		return (ret);
	}
};
char a[MAX][MAX];
vector<ii> seg;
BIT bit;
int m,n;
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
bool cmp(const ii &a,const ii &b) {
	return (a.se>b.se);
}
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	FOR(i,1,m) scanf("%s",a[i]+1);	
	FOR(i,1,m) {
		vector<int> sta,fin;
		sta.clear();fin.clear();
		FOR(j,1,n) {
			if (a[i][j]=='1' && (j==1 || a[i][j-1]=='0')) sta.push_back(j);
			if (a[i][j]=='1' && (j==n || a[i][j+1]=='0')) fin.push_back(j);
		}	
		REP(j,sta.size()) seg.push_back(ii(sta[j],fin[j]));
	}
	sort(seg.begin(),seg.end(),cmp);	
	bit=BIT(n);
}
void process(void) {
	int prev=0;
	int res=0;
	FORD(r,n,1) {
		while (prev<seg.size() && seg[prev].se>=r) {
			bit.add(seg[prev].fi);
			prev++;
		}		
		FOR(l,1,r) maximize(res,bit.get(l)*(r-l+1));
	}
	printf("%d",res);
}
int main(void) {
	init();
	process();
	return 0;
}