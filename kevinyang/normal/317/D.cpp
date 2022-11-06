#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	int sum = 1;
	set<int>s;
	for(int j = 2; j<=100000; j++){
		int cur = j;
		for(int k = 1; k<30; k++){
			cur*=j;
			if(cur>n)break;
			s.insert(cur);
		}
	}
	vector<int>grundy = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
	for(int i = 2; i<=min(n,100000LL); i++){
		if(s.find(i)!=s.end())continue;
		int cnt = 0;
		int k = i;
		while(k<=n){
			cnt++;
			k*=i;
		}
		sum^=grundy[cnt];
	}
	
	if(n>100000){
		int rem = n-100000;
		auto it = s.upper_bound(100000);
		while(it!=s.end()){
			rem--;
			it++;
		}
		rem%=2;
		sum^=rem;
	}
	
	if(sum>0){
		cout << "Vasya\n";
	}
	else{
		cout << "Petya\n";
	}
	return 0;
}