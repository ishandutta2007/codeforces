#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int mid = 0;
		int cnt = count(s.begin(),s.end(),'*');
		if(cnt==0){
			cout << "0\n";
			continue;
		}
		int left = 0; int right = count(s.begin()+cnt,s.end(),'*');
		int cur = 0;
		deque<int>dqleft; deque<int>dqright;
		if(true){
			int curcnt = 0;
			for(int i = 0; i<n; i++){
				if(s[i]=='.'){
					curcnt++;
					dqright.push_back(i);
					if(curcnt==right)break;
				}
			}
			queue<int>q;
			for(int i = 0; i<n; i++){
				q.push(i);
				if(s[i]=='*'){
					int x = q.front(); q.pop();
					cur+=i-x;
				}
			}
		}
		//cout << left << " " << right << " " << cur << "\n";
		int ans = cur;
		for(int i = 1; i+cnt<=n; i++){
			//cur-=right;
			if(s[i+cnt-1]=='*'){
				cur-=i+cnt-1;
				//right--;
			}
			else{
				cur-=i+cnt-1;
				dqright.push_back(i+cnt-1);
			}
			if(true){
				int x = dqright[0];
				dqright.pop_front();
				dqleft.push_back(x);
				cur+=2*x;
			}
			if(s[i-1]=='*'){
				cur-=i-1;
				//left++;
			}
			else{
				int x = dqleft[0];
				dqleft.pop_front();
				cur-=x;
			}
			ans = min(ans,cur);
		}
		cout << ans << "\n";
	}
	return 0;
}