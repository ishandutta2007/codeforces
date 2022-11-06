#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
	vector<int> rank,parent;
	int n;
public:
	DisjointSet(int n):n(n), rank(n+1), parent(n+1){}
	void makeSet(){
		for(int i = 1; i<=n; i++)
			parent[i] = i;
	}
	int find(int x){
		return parent[x]= (parent[x]==x ? x: find(parent[x]));
	}
	void Union(int x, int y){
		x = find(x), y = find(y);
		if(x==y)
			return;
		if(rank[x]==rank[y])
			rank[x]++;
		if(rank[x]<rank[y]){
			parent[x] = y;
		}
		else{
			parent[y] = x;
		}
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,p;
		cin >> n >> p;
		vector<int>arr(n+1);
		DisjointSet ds(n);
		ds.makeSet();
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			q.push({arr[i],i});
		}
		int ans = 0;
		while(q.size()&&q.top().first<p){
			pair<int,int>nxt = q.top(); q.pop();
			for(int i = nxt.second-1; i>0; i--){
				if(arr[i]%nxt.first==0){
					if(ds.find(i)==ds.find(nxt.second)){
						break;
					}
					else{
						ds.Union(i,nxt.second);
						ans+=nxt.first;
					}
				}
				else{
					break;
				}
			}
			for(int i = nxt.second+1; i<=n; i++){
				if(arr[i]%nxt.first==0){
					if(ds.find(i)==ds.find(nxt.second)){
						break;
					}
					else{
						ds.Union(i,nxt.second);
						ans+=nxt.first;
					}
				}
				else{
					break;
				}
			}
		}
		for(int i = 2; i<=n; i++){
			if(ds.find(i)!=ds.find(1)){
				ans+=p;
				ds.Union(i,1);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}