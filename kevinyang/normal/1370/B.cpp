#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		vector<int>arr(2*n);
		int total = 0;
		for(int i = 0; i<2*n; i++){
			cin >> arr[i];
			total+=arr[i];
		}
		int ind1 = 0; int ind2 = 0;
		loop:
		for(int i = 0; i<2*n; i++){
			bool breaking = false;
			for(int j = i+1; j<2*n; j++){
				if((total-arr[i]-arr[j])%2==0){
					ind1 = i; ind2 = j;
					breaking = true; break;
				}
			}
			if(breaking)break;
		}
		vector<pair<int,int>>odd; vector<pair<int,int>>even;
		for(int i = 0; i<2*n; i++){
			if(i==ind1||i==ind2){
				continue;
			}
			if(arr[i]%2==1)odd.push_back(make_pair(arr[i],i+1));
			else even.push_back(make_pair(arr[i],i+1));
		}
		int count = 0;
		for(pair<int,int> nxt: odd){
			count++;
			if(count%2==1){
				cout << nxt.second << " ";
			}
			else{
				cout << nxt.second << "\n";
			}
		}
		for(pair<int,int> nxt: even){
			count++;
			if(count%2==1){
				cout << nxt.second << " ";
			}
			else{
				cout << nxt.second << "\n";
			}
		}
		
	}
	return 0;
}