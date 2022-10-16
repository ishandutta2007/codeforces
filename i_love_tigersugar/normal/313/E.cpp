#include<cstdio>
#include<deque>
#define MAX   100100
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
int c1[MAX];
int c2[MAX];
int res[MAX];
deque<ii> q;
int m,n;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	int i,t;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&t);
		c1[t]++;
	}
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&t);
		c2[t]++;
	}
	while (!q.empty()) q.pop_back();
}
void process(void) {
	int i,j,t;
	for (i=0;i<m;i=i+1) {
		for (j=1;j<=c1[i];j=j+1) q.push_back(ii(i,1));
		for (j=1;j<=c2[m-i-1];j=j+1) {
			if (!q.empty() && q.back().y==1) {
				t=q.back().x; q.pop_back();
				res[(t+m-i-1)%m]++;
			}
			else q.push_back(ii(m-i-1,2));
		}
	}
	while (!q.empty()) {
		int i=q.front().x; q.pop_front();
		int j=q.back().x; q.pop_back();
		res[(i+j)%m]++;
	}
	bool space=false;
	for (i=m-1;i>=0;i=i-1)
		for (j=1;j<=res[i];j=j+1) {
			if (space) printf(" ");
			else space=true;
			printf("%d",i);
		}
}
int main(void) {
	init();
	process();
	return 0;
}