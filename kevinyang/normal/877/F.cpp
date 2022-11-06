#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int freq[300105];
int mxn = 100005;
vector<int>psa(mxn);
int sq = 280;
bool comp(pair<int,int>a, pair<int,int>b){
	if(a.first/sq!=b.first/sq){
		return a.first<b.first;
	}
	return a.second<b.second;
}
int cnt = 0;
void add(int x,int mul,int y){//right means mul = 1 otherwise mul = -1
	cnt+=freq[x];
	freq[y]++;
}
void erase(int x, int mul, int y){
	freq[y]--;
	cnt-=freq[x];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(freq,0,sizeof(freq));
	cin >> n >> k;
	vector<int>t(n+1);
	for(int i = 1; i<=n; i++){
		cin >> t[i];
	}
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		if(t[i]==2)arr[i]*=-1;
	}
	for(int i = 1; i<=n; i++){
		psa[i] = psa[i-1]+arr[i];
	}
	vector<int>sorted;
	for(int i = 0; i<=n; i++){
		sorted.push_back(psa[i]);
		sorted.push_back(psa[i]-k);
		sorted.push_back(psa[i]+k);
	}
	sort(sorted.begin(),sorted.end());
	vector<int>P(n+1);
	vector<int>L(n+1);
	vector<int>R(n+1);
	for(int i = 0; i<=n; i++){
		P[i] = lower_bound(sorted.begin(),sorted.end(),psa[i])-sorted.begin();
		L[i] = lower_bound(sorted.begin(),sorted.end(),psa[i]-k)-sorted.begin();
		R[i] = lower_bound(sorted.begin(),sorted.end(),psa[i]+k)-sorted.begin();
	}
	int base = (int)1e9;
	int q;
	cin >> q;
	vector<pair<int,int>>queries(q);
	vector<int>ans(q);
	for(int i = 0; i<q; i++){
		int x,y;
		cin >> x >> y;y*=base; y+=i;
		queries[i] = {x,y};
		
	}
	//map<pair<int,int>,int>hm;
	sort(queries.begin(),queries.end(),comp);
	freq[lower_bound(sorted.begin(),sorted.end(),0)-sorted.begin()]++;
	int r = 0; int l = 1;
	for(int i = 0; i<q; i++){
		int lx = queries[i].first; int rx = queries[i].second/base; int idx = queries[i].second%base;
		while(r<rx){
			r++;
			cnt+=freq[L[r]];
			freq[P[r]]++;
		}
		while(l>lx){
			l--;
			cnt+=freq[R[l-1]];
			freq[P[l-1]]++;
		}
		while(r>rx){
			freq[P[r]]--;
			cnt-=freq[L[r]];
			r--;
		}
		while(l<lx){
			freq[P[l-1]]--;
			cnt-=freq[R[l-1]];
			l++;
		}
		ans[idx] = cnt;
	}
	for(int i = 0; i<q; i++){
		cout << ans[i] << "\n";
	}
	return 0;
}