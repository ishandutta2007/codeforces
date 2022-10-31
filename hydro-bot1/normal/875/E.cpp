// Hydro submission #6340dd3e060557bf15811fa5@1665195326462
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 100005;

int p1, p2, n;
int a[MAX];

bool check(int x){
	set <int> s;
	s.insert(p1);
	s.insert(p2);
	for(int i = 1; i <= n; i++){
		s.erase(s.begin(), s.lower_bound(a[i] - x));
		s.erase(s.upper_bound(a[i] + x), s.end());
		if(s.empty())	return false;
		s.insert(a[i]);
	}//114514
	return true;
}

signed main(){
	cin>>n>>p1>>p2;
	int l = abs(p2 - p1), r = 1e9+7;
	for(int i = 1; i <= n; i++)	cin>>a[i];
	int ans;
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}