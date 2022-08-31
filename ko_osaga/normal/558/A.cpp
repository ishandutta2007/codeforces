#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

vector<pi> l, r;
int n;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		if(x < 0) l.push_back(pi(-x,y));
		else r.push_back(pi(x,y));
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int sum1 = 0, sum2 = 0;
	for(int i=0; i<l.size() && i<r.size(); i++){
		sum1 += l[i].second;
		if(i < r.size()) sum1 += r[i].second;
	}
	if(l.size() < r.size()) sum1 += r[l.size()].second;

	for(int i=0; i<r.size() && i<l.size(); i++){
		sum2 += r[i].second;
		if(i < l.size()) sum2 += l[i].second;
	}
	if(r.size() < l.size()) sum2 += l[r.size()].second;
	
	printf("%d",max(sum1, sum2));

}