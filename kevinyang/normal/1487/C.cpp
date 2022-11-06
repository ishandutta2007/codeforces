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
		if(n%2==1){
			vector<int>arr(n+1);
			set<pair<int,int>>s;
			for(int i = 1; i<=n; i++){
				vector<pair<int,int>>vals;
				for(int j = i+1; j<=n; j++){
					vals.push_back({arr[j],j});
				}
				sort(vals.begin(),vals.end());
				int rq = n/2-arr[i];
				for(int j = 0; j<n-i-rq; j++){
					pair<int,int>p = vals[j];
					arr[p.second]++;
					s.insert({i,p.second});
				}
				arr[i] = n/2;
			}
			for(int i = 1; i<=n; i++){
				for(int j = i+1; j<=n; j++){
					if(s.find({i,j})==s.end()){
						cout << "1 ";
					}
					else{
						cout << "-1 ";
					}
				}
			}
			cout << "\n";
		}
		else{
			vector<int>arr(n+1);
			set<pair<int,int>>s;
			for(int i = 1; i<=n; i++){
				vector<pair<int,int>>vals;
				for(int j = i+1; j<=n; j++){
					if(j==i+1&&i%2==1)continue;
					vals.push_back({arr[j],j});
				}
				sort(vals.begin(),vals.end());
				int rq = (n-1)/2-arr[i];
				for(int j = 0; j<n-i-rq-(i%2==1); j++){
					pair<int,int>p = vals[j];
					arr[p.second]++;
					s.insert({i,p.second});
				}
				arr[i] = (n-1)/2;
			}
			for(int i = 1; i<=n; i++){
				for(int j = i+1; j<=n; j++){
					if(j==i+1&&i%2==1){
						cout << "0 ";
						continue;
					}
					if(s.find({i,j})==s.end()){
						cout << "1 ";
					}
					else{
						cout << "-1 ";
					}
				}
			}
			cout << "\n";
		}
	}
	return 0;
}