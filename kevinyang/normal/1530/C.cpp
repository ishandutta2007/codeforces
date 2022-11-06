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
		vector<int>arr(5*n,100LL);
		vector<int>arr2(5*n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<n; i++){
			cin >> arr2[i];
		}
		int sum = 0; int sum2 = 0;
		multiset<int>s;
		multiset<int>s2;
		multiset<int>p;
		multiset<int>p2;
		int cnt = 0;
		for(int i = 0; i<n; i++){
			cnt++;
			p.insert(arr[i]);
			p2.insert(arr2[i]);
			if(cnt%4!=0){
				int v = *--p.end();
				s.insert(v); p.erase(p.find(v)); sum+=v;
				v = *--p2.end();
				s2.insert(v); p2.erase(p2.find(v)); sum2+=v;
			}
			while(s.size()&&p.size()&&*s.begin()<*--p.end()){
				int v = *--p.end(); p.erase(p.find(v));
				int v2 = *s.begin(); s.erase(s.find(v2));
				s.insert(v); p.insert(v2); sum+=v-v2;
			}
			while(s2.size()&&p2.size()&&*s2.begin()<*--p2.end()){
				int v = *--p2.end(); p2.erase(p2.find(v));
				int v2 = *s2.begin(); s2.erase(s2.find(v2));
				s2.insert(v); p2.insert(v2); sum2+=v-v2;
			}
		}
		for(int i = n; i<5*n; i++){
			if(sum>=sum2)break;
			cnt++;
			p.insert(arr[i]);
			p2.insert(arr2[i]);
			if(cnt%4!=0){
				int v = *--p.end();
				s.insert(v); p.erase(p.find(v)); sum+=v;
				v = *--p2.end();
				s2.insert(v); p2.erase(p2.find(v)); sum2+=v;
			}
			while(s.size()&&p.size()&&*s.begin()<*--p.end()){
				int v = *--p.end(); p.erase(p.find(v));
				int v2 = *s.begin(); s.erase(s.find(v2));
				s.insert(v); p.insert(v2); sum+=v-v2;
			}
			while(s2.size()&&p2.size()&&*s2.begin()<*--p2.end()){
				int v = *--p2.end(); p2.erase(p2.find(v));
				int v2 = *s2.begin(); s2.erase(s2.find(v2));
				s2.insert(v); p2.insert(v2); sum2+=v-v2;
			}
		}
		cout << cnt-n << "\n";
	}
	return 0;
}