#include <bits/stdc++.h>
using namespace std;
#define vc vector <int>
map <int,vc > a;
int main(){
	int n,c,d,h[5010];
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> h[i] >> d;
		a[h[i]].push_back(d);
	}
	sort(h,h+n);
	vc s;
	int ans=0;
	for (int i=0; i<n; i++){
		a[h[i]].push_back(h[i]);
		sort(a[h[i]].begin(),a[h[i]].end());
	}
	for (int i=0 ;i<n; i++){
		int j=0;
		while (a[h[i]][j]<ans){
			j++;
		}
		ans=a[h[i]][j];
		a[h[i]].erase(a[h[i]].begin()+j);
	}
	cout << ans;
	return 0;
}