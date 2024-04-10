#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1e5;

struct edge {
	int p,w;
};

int children[mxN+1]={};
vector<pair<int,int>> adj[mxN+1];
priority_queue<edge> pq1,pq2;
long long dfs(int at, int from) {
	//D(at);D(from);
	long long ans = 0;
	for(auto p:adj[at]) {
		int to = p.first;
		if(to==from) continue;
		ans+=dfs(to,at)+(long long)abs(p.second)*children[to];
		children[at]+=children[to];
		if(p.second<0) {
			pq1.push({to,-p.second});
		} else {
			pq2.push({to,p.second});
		}
		
	}
	if(children[at]==0) children[at]=1;
	//D(at);D(children[at]);
	return ans;
}

bool operator<(const edge& a, const edge& b) {
	return (long long)(a.w-a.w/2)*children[a.p] <(long long)(b.w-b.w/2)*children[b.p];
}
edge es[mxN];
int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		long long s;
		cin >> n >> s;
		pq1 = priority_queue<edge>();pq2 = priority_queue<edge>();
		memset(children,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;++i) adj[i].clear();
		for(int i=0;i<n-1;++i) {
			int u,v,w,c;
			cin >> u >> v >> w >> c;
			if(c==1) w=-w;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		long long cur = dfs(1,-1);
		//D(cur);
		int ans = 0;
		while(cur>s) {
			long long tmp1=0,tmp2=0,tmp3=0,mx;
			//D(cur);
			edge best1={-1,-1}, best2, best3;
			if(!pq1.empty()) {
				best1 = pq1.top();pq1.pop();
				tmp1 = (long long)(best1.w-best1.w/2)*children[best1.p];
				if(cur-tmp1<=s){
					ans++;break;
				}
				if(!pq1.empty()) {
					best3 = pq1.top();
					tmp3 = tmp1+(long long)(best3.w-best3.w/2)*children[best3.p];
				}

				tmp1+=(long long)(best1.w/2-((best1.w/2) /2))*children[best1.p];
			}

			if(!pq2.empty()) {
				best2 = pq2.top();
				tmp2 = (long long)(best2.w-best2.w/2)*children[best2.p];
			}
			//D(tmp1);D(tmp2);D(tmp3);
			mx = max(tmp1,max(tmp2,tmp3));
			if(tmp1==mx or tmp3 == mx) {
				//cout << "used 2 times 1 coin edge\n";
				cur-=(long long)(best1.w-best1.w/2)*children[best1.p];
				best1.w = (best1.w/2);
				pq1.push(best1);
				ans++;
			} else if(tmp2 == mx) {
				//cout << "used 2 coins edge\n";
				cur-=tmp2;
				ans+=2;
				best2.w= best2.w/2;
				pq2.pop();pq2.push(best2);
				if(best1.p!=-1) pq1.push(best1);
			}
		}
		cout << ans << endl;
	}
}