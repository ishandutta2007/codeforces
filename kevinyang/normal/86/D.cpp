#include <bits/stdc++.h>
using namespace std;
#define int long long
int sq = 450;
bool comp(pair<int,int>a, pair<int,int>b){
	if(a.first/sq==b.first/sq)return a.second < b.second;
	return a.first<b.first;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<pair<int,int>>queries(q);
	vector<pair<int,int>>old(q);
	map<pair<int,int>,int>hm;
	for(int i = 0; i<q; i++){
		int x,y;
		cin >> x >> y;
		queries[i] = {x,y};
		old[i] = {x,y};
	}
	sort(queries.begin(),queries.end(),comp);
	vector<int>freq(1000005);
	int ans = 0;
	int l = 1; int r = 0;
	for(int i = 0; i<q; i++){
		int lx = queries[i].first; int rx = queries[i].second;
		while(r<rx){
			r++;
			freq[arr[r]]++;
			int v = freq[arr[r]];
			ans-=(v-1)*(v-1)*arr[r];
			ans+=v*v*arr[r];
		}
		while(l>lx){
			l--;
			freq[arr[l]]++;
			int v = freq[arr[l]];
			ans-=(v-1)*(v-1)*arr[l];
			ans+=v*v*arr[l];
		}
		while(r>rx){
			freq[arr[r]]--;
			int v = freq[arr[r]];
			ans-=(v+1)*(v+1)*arr[r];
			ans+=v*v*arr[r];
			r--;
		}
		while(l<lx){
			freq[arr[l]]--;
			int v = freq[arr[l]];
			ans-=(v+1)*(v+1)*arr[l];
			ans+=v*v*arr[l];
			l++;
		}
		hm[queries[i]] = ans;
	}
	for(int i = 0; i<q; i++){
		cout << hm[old[i]] << "\n";
	}
	return 0;
}