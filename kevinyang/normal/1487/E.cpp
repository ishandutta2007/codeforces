#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n1,n2,n3,n4;
	cin >> n1 >> n2 >> n3 >> n4;
	vector<int>arr(n1+1);
	vector<int>arr2(n2+1);
	vector<int>arr3(n3+1);
	vector<int>arr4(n4+1);
	for(int i = 1; i<=n1; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=n2; i++){
		cin >> arr2[i];
	}
	for(int i = 1; i<=n3; i++){
		cin >> arr3[i];
	}
	for(int i = 1; i<=n4; i++){
		cin >> arr4[i];
	}
	vector<int>ans(n1+1);
	for(int i = 1; i<=n1; i++){
		ans[i] = arr[i];
	}
	vector<int>ans2(n2+1,(int)1e18);
	vector<int>ans3(n3+1,(int)1e18);
	vector<int>ans4(n4+1,(int)1e18);
	if(true){
		vector<vector<int>>adj(n2+1);
		int m;
		cin >> m;
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			adj[y].push_back(x);
		}
		set<pair<int,int>>s;s.insert({(int)2e18,1});
		for(int i = 1; i<=n1; i++){
			s.insert({ans[i],i});
		}
		for(int i = 1; i<=n2; i++){
			for(int nxt: adj[i]){
				s.erase({ans[nxt],nxt});
			}
			pair<int,int>p = *s.begin();
			ans2[i] = min(ans2[i],p.first+arr2[i]);
			for(int nxt: adj[i]){
				s.insert({ans[nxt],nxt});
			}
		}
	}
	if(true){
		vector<vector<int>>adj(n3+1);
		int m;
		cin >> m;
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			adj[y].push_back(x);
		}
		set<pair<int,int>>s;s.insert({(int)2e18,1});
		for(int i = 1; i<=n2; i++){
			s.insert({ans2[i],i});
		}
		for(int i = 1; i<=n3; i++){
			for(int nxt: adj[i]){
				s.erase({ans2[nxt],nxt});
			}
			pair<int,int>p = *s.begin();
			ans3[i] = min(ans3[i],p.first+arr3[i]);
			for(int nxt: adj[i]){
				s.insert({ans2[nxt],nxt});
			}
		}
	}
	if(true){
		vector<vector<int>>adj(n4+1);
		int m;
		cin >> m;
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			adj[y].push_back(x);
		}
		set<pair<int,int>>s; s.insert({(int)2e18,1});
		for(int i = 1; i<=n3; i++){
			s.insert({ans3[i],i});
		}
		for(int i = 1; i<=n4; i++){
			for(int nxt: adj[i]){
				s.erase({ans3[nxt],nxt});
			}
			pair<int,int>p = *s.begin();
			ans4[i] = min(ans4[i],p.first+arr4[i]);
			for(int nxt: adj[i]){
				s.insert({ans3[nxt],nxt});
			}
		}
	}
	int anss = (int)1e18;
	for(int i = 1; i<=n4; i++){
		anss = min(anss,ans4[i]);
	}
	if(anss>(int)1e9){
		cout << "-1\n";
		return 0;
	}
	cout << anss << "\n";
	return 0;
}