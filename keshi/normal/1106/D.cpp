#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,u,v;
	cin >> n >> m;
	vector <int> a[n];
	for (int i=0 ;i<m; i++){
		cin >> u >> v;
		u--;
		v--;
		a[v].push_back(u);
		a[u].push_back(v);
	}
	bool s[n]={0};
	int d=1,w;
	vector <int> ans;
	s[0]=1;
	priority_queue<int, vector<int>, greater<int> > q;
	q.push(0);
	while (q.size()>0){
		w=q.top();
		q.pop();
		ans.push_back(w+1);
		for (int i=0 ; i< a[w].size() ;i++){
			if (!s[a[w][i]]){
				q.push(a[w][i]);
				s[a[w][i]]=1;
			}
		}
		//sort(q.begin(),q.end(),greater<int>());
	}
	for (int i=0; i<n; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}