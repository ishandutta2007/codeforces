#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

PII a[1 << 17];

int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = PII(x, y);
		//vis[i] = 0;
	}
	queue<int> Q;
	for(int i = 0; i < n; i++)
		if (a[i].first == 1){
			//vis[i] = 1;
			Q.push(i);
		}
	vector<PII> ans;
	while (!Q.empty()){
		int i = Q.front();
		Q.pop();
		if (a[i].first == 1){
			if (i < a[i].second)
				ans.push_back(PII(i, a[i].second));
			else
				ans.push_back(PII(a[i].second, i));
			a[a[i].second].first--;
			a[a[i].second].second ^= i;//a[i].second;
			if (a[a[i].second].first == 1)
				Q.push(a[i].second); 
		}
	}
	sort(ans.begin(), ans.end());
	int cnt = unique(ans.begin(), ans.end()) - ans.begin();
	cout<<cnt<<endl;
	for(int i = 0; i < cnt; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}