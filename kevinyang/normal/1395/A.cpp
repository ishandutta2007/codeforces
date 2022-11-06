#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		vector<int>a(3);
		int w;
		bool f = false;
		for(int i = 0; i<3; i++)
			cin >> a[i];
		cin >> w;
		sort(a.begin(),a.end());
		int cur = 0;
		for(int i = 0; i<3; i++){
			cur+=(a[i]%2);
		}
		cur+=w%2;
		if(cur<=1)f = true;
		for(int i = 0; i<3; i++){
			a[i]--;
		}
		w+=3;
		cur = 0;
		if(a[0]>=0){
			for(int i = 0; i<3; i++){
				cur+=(a[i]%2);
			}
			cur+=w%2;
			if(cur<=1)f = true;
		}
		int sub = a[0];
		for(int i = 0; i<3; i++){
			a[i]-=sub;
		}
		cur = 0;
		w+=3*sub;
		if(a[0]>=0){
			for(int i = 0; i<3; i++){
				cur+=(a[i]%2);
			}
			cur+=w%2;
			if(cur<=1)f = true;
		}
		if(f){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}