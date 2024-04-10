#include <bits/stdc++.h>
using namespace std;
#define int long long
int sq = 350;
bool comp(pair<int,int>a, pair<int,int>b){
	if(a.first/sq!=b.first/sq){
		return a.first<b.first;
	}
	return a.second < b.second;
}
int cnt = 0;
vector<int>freq(200005);
void add(int x){
	freq[x]++;
	if(freq[x]==x)cnt++;
	if(freq[x]==x+1)cnt--;
}
void rem(int x){
	freq[x]--;
	if(freq[x]==x)cnt++;
	if(freq[x]==x-1)cnt--;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		if(arr[i]>n){
			arr[i] = n+1;
		}
	}
	vector<pair<int,int>>old(q);
	vector<pair<int,int>>queries(q);
	for(int i = 0; i<q; i++){
		int x,y;
		cin >> x >> y;
		old[i] = {x,y};
		queries[i] = {x,y};
	}
	int l = 1; int r = 0;
	map<pair<int,int>,int>hm;
	sort(queries.begin(),queries.end(),comp);
	for(int i = 0; i<q; i++){
		int lx = queries[i].first; int rx = queries[i].second;
		while(r<rx){
			r++;
			add(arr[r]);
		}
		while(l>lx){
			l--;
			add(arr[l]);
		}
		while(r>rx){
			rem(arr[r]);
			r--;
		}
		while(l<lx){
			rem(arr[l]);
			l++;
		}
		hm[queries[i]] = cnt;
	}
	for(int i = 0; i<q; i++){
		cout << hm[old[i]] << "\n";
	}
	return 0;
}