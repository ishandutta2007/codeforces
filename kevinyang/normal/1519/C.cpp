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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>arr2(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr2[i];
		}
		vector<vector<int>>stu(n+1);
		vector<vector<int>>psa(n+1);
		for(int i = 1; i<=n; i++){
			stu[i].push_back(0); //psa[i].push_back(0);
		}
		set<int>s;
		for(int i = 1; i<=n; i++){
			s.insert(i);
		}
		for(int i = 1; i<=n; i++){
			stu[arr[i]].push_back(arr2[i]);
		}
		for(int i = 1; i<=n; i++){
			sort(stu[i].begin(),stu[i].end());
			reverse(stu[i].begin()+1,stu[i].end());
		}
		for(int i = 1; i<=n; i++){
			psa[i].push_back(0);
			for(int j = 1; j<stu[i].size(); j++){
				psa[i].push_back(psa[i][j-1]+stu[i][j]);
			}
		}
		//cerr << "nae\n";
		for(int i = 1; i<=n; i++){
			set<int>rem;
			int ans = 0;
			for(int nxt: s){
				if(stu[nxt].size()-1<i)rem.insert(nxt);
				else{
					ans+=psa[nxt][(int)(psa[nxt].size()-1)/i*i];
				}
			}
			for(int nxt: rem)s.erase(nxt);
			cout << ans << " ";
		}
		cout << "\n";
	}
	return 0;
}