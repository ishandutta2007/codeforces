#include <cstdio>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

int n,m,t;
vector<int> start[86405];
queue<pi> que;
int ret[20005];
int piv;

int main(){
	scanf("%d %d %d",&n,&m,&t);
	for (int i=0; i<n; i++) {
		char str[20];
		scanf("%s",str);
		int h = 3600 * ((str[0] - '0') * 10 + (str[1] - '0'));
		int m = 60 * ((str[3] - '0') * 10 + (str[4] - '0'));
		int d = ((str[6] - '0') * 10 + (str[7] - '0'));
		start[h+m+d].push_back(i);
	}
	int reach_max = 0;
	map<int,int> mp;
	for (int i=0; i<86400; i++) {
		for (int &j : start[i]){
			if(mp.size() == m){
				mp[piv]++;
				ret[j] = piv;
			}
			else{
				piv++;
				mp[piv]++;
				ret[j] = piv;
			}
			if(mp.size() == m) reach_max = 1;
			que.push(pi(i + t - 1,ret[j]));
		}
		while (!que.empty() && que.front().first == i) {
			mp[que.front().second]--;
			if(mp[que.front().second] == 0){
				mp.erase(que.front().second);
			}
			que.pop();
		}
	}
	if(!reach_max) puts("No solution");
	else{
		printf("%d\n",piv);
		for (int i=0; i<n; i++) {
			printf("%d\n",ret[i]);
		}
	}
}