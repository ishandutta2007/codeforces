#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(c<a||(c==a&&d>b)){
			int temp1 = a;
			int temp2 = b;
			a = c; b = d; c = temp1; d = temp2;
		}
		if(b<=c){
			int moves = c-b;//number of moves required to make two segements beside each other
			int moves2 = d-a;//number of moves to make both segments completely overlap
			int cur = 0;
			int required = k;
			int total = 1e18;
			for(int i = 0; i<n; i++){
				cur+=moves;
				if(required<=moves2){
					cur+=required;
					required = 0;
					break;
				}
				cur+=moves2;
				required-=moves2;
				total = min(total,cur+required*2);
			}
			cur+=required*2;
			total = min(total,cur);
			cout << total << "\n";
		}
		else if(c<=b&&d<=b){
			int moves = (b-a)-(d-c);//number of moves to make both segments completely overlap
			int cur = 0;
			int required = k-(d-c)*n;
			if(required<=0){
				cout << cur << "\n";
				continue;
			}
			for(int i = 0; i<n; i++){
				if(required<=moves){
					cur+=required;
					required = 0;
					break;
				}
				cur+=moves;
				required-=moves;
			}
			cur+=required*2;
			cout << cur << "\n";
		}
		else if(c<=b&&d>b){
			int moves = (d-a)-(b-c);
			int cur = 0;
			int required = k-(b-c)*n;
			if(required<=0){
				cout << cur << "\n";
				continue;
			}
			for(int i = 0; i<n; i++){
				if(required<=moves){
					cur+=required;
					required = 0;
					break;
				}
				cur+=moves;
				required-=moves;
			}
			cur+=required*2;
			cout << cur << "\n";
		}
	}
	return 0;
}