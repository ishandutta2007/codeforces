#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x,y,a,b;
		cin >> x >> y >> a >> b;
		if(x>y)swap(x,y);
		if(a>b)swap(a,b);
		int low = 0; int high = x/a+1; int mid = (low+high)/2;
		while(low+1<high){
			//2nd bs is for how many large gifts you can fit into the lower sized money count
			int lo = 0; int hi = x/b+1; int mi = (lo+hi)/2;
			while(lo+1<hi){
				if((x-mi*b)/a+mi>=mid){
					lo = mi;
				}
				else{
					hi = mi;
				}
				mi = (lo+hi)/2;
			}
			if(lo*a+(mid-lo)*b<=y){
				low = mid;
			}
			else{
				high = mid;
			}
			mid = (low+high)/2;
		}
		cout << low << "\n";
	}
	return 0;
}