#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int INF=(int)1e9+7;
int a[MAX];
int b[MAX];
int fs[MAX];
int bs[MAX];
vector<int> res;
int n;
void print(void) {
	sort(res.begin(),res.end());
	res.resize(unique(res.begin(),res.end())-res.begin());
	printf("%d\n",res.size());
	FORE(it,res) {
		if (it!=res.begin()) printf(" ");
		printf("%d",*it);
	}
	exit(0);
}
void init(void) {
	scanf("%d",&n);
	if (n==1) {
		printf("-1");
		exit(0);
	}
	if (n==2) {
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		if (a>b) swap(a,b);
		res.push_back(2*a-b);
		res.push_back(2*b-a);
		if ((a+b)%2==0) res.push_back((a+b)/2);		
		print();
	}
	FOR(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	FOR(i,1,n-1) b[i]=a[i+1]-a[i];
	fs[1]=b[1];
	FOR(i,2,n-1) {
		if (fs[i-1]<INF && fs[i-1]==b[i]) fs[i]=b[i];
		else fs[i]=INF;
	}
	bs[n-1]=b[n-1];
	FORD(i,n-2,1) {
		if (bs[i+1]<INF && bs[i+1]==b[i]) bs[i]=b[i];
		else bs[i]=INF;
	}
	
}
void process(void) {
	if (fs[n-1]<INF) {
		res.push_back(a[1]-fs[n-1]);
		res.push_back(a[n]+fs[n-1]);
	}
	FOR(i,2,n-2) if (fs[i-1]<INF && bs[i+1]<INF && fs[i-1]==bs[i+1]) {
		int t=fs[i-1];
		if (a[i+1]-a[i]==2*t) res.push_back(a[i]+t);		
	}
	if (bs[2]<INF && a[2]-a[1]==2*bs[2]) res.push_back(a[1]+bs[2]);
	if (fs[n-2]<INF && a[n]-a[n-1]==2*fs[n-2]) res.push_back(a[n-1]+fs[n-2]);
	print();
}
int main(void) {
	init();
	process();
	return 0;
}