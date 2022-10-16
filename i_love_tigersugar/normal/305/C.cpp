#include<algorithm>
#include<cstdio>
#include<vector>
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
vector<int> val;
vector<ii> comp;
int n;
void init(void) {
	int i,t;
	scanf("%d",&n);
	for (i=0;i<n;i=i+1) {
		scanf("%d",&t);
		val.push_back(t);
	}
}
bool compress(void) {
	comp.clear();
	bool need=false;
	int i;
	comp.push_back(ii(val[0],1));
	for (i=1;i<val.size();i=i+1) {
		if (val[i]>val[i-1]) comp.push_back(ii(val[i],0));
		else need=true;
		comp[comp.size()-1].y++;
	}
	return (need);
}
void rebuild(void) {
	val.clear();
	int i,j,k,t;
	for (i=0;i<comp.size();i=i+1) {
		j=0;
		k=comp[i].y;
		t=comp[i].x;
		while ((1<<j)<=k) {
			if ((k|(1<<j))==k) val.push_back(t+j);
			j++;
		}
	}
	sort(val.begin(),val.end());
}
void process(void) {
	while (compress()) rebuild();
	printf("%d",val[val.size()-1]+1-val.size());
}
int main(void) {
	init();
	process();
	return 0;
}