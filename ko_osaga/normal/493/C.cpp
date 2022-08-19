#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> pi;

vector<pi> v;

int main(){
	int n;
	scanf("%d",&n);
	int c1 = 0, c2 = 0;
	while(n--){
		int t;
		scanf("%d",&t);
		c1 += 3;
		v.push_back(pi(t,1));
	}
	scanf("%d",&n);
	while(n--){
		c2 += 3;
		int t;
		scanf("%d",&t);
		v.push_back(pi(t,2));
	}
	sort(v.begin(), v.end());
	int cnt[3] = {};
	int minab = c1 - c2;
	int pa = c1, pb = c2;
	for(int i=0; i<v.size();){
		int e = i;
		while(e < v.size() && v[i].first == v[e].first){
			e++;
		}
		for(int j=i; j<e; j++){
			cnt[v[j].second]--;
		}
		if(minab < cnt[1] - cnt[2] + c1 - c2){
			minab = cnt[1] - cnt[2] + c1 - c2;
			pa = cnt[1] + c1, pb = cnt[2] + c2;
		}
		else if(minab == cnt[1] - cnt[2] + c1 - c2){
			if(pa < cnt[1] + c1){
				pa = cnt[1] + c1, pb = cnt[2] + c2;
			}
		}
		i = e;
	}
	printf("%d:%d",pa,pb);
}