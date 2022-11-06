#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
int sq = sqrt(500500);
int freq[500001];
int val[500001]; 
int arr[500001];
int ans[500001]; 
queue<int>q;
bool comp(pair<pair<int,int>,int>a, pair<pair<int,int>,int>b){
	if(a.first.first/sq==b.first.first/sq&&(a.first.first/sq)%2==1)return a.first.second<b.first.second;
	else if(a.first.first/sq==b.first.first/sq)return b.first.second<a.first.second;
	return a.first.first/sq<b.first.first/sq;
}
int cnt = 0;
inline void add(int x){
	freq[x]++;
	if(freq[x]==1&&!val[x]){
		val[x] = 1;
		q.push(x);
	}
}
inline void sub(int x){
	freq[x]--;
	if(freq[x]==1&&!val[x]){
		val[x] = 1;
		q.push(x);
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	
	memset(arr,0,sizeof(arr));
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	int qq;
	cin >> qq;
	memset(ans,0,sizeof(ans));
	pair<pair<int,int>,int> queries[qq]; 
	for(int i = 0; i<qq; i++){
		int x,y;
		cin >> x >> y;
		queries[i] = {{x,y},i};
	}
	sort(queries,queries+qq,comp);
	int l = 1; int r = 0;
	 memset(freq,0,sizeof(freq));
	memset(val,0,sizeof(val));
	for(int i = 0; i<qq; i++){
		int lx = queries[i].first.first; int rx = queries[i].first.second;
		while(r<rx){
			r++;
			add(arr[r]);
		}
		while(l>lx){
			l--;
			add(arr[l]);
		}
		while(l<lx){
			sub(arr[l]);
			l++;
		}
		while(r>rx){
			sub(arr[r]);
			r--;
		}
		while(q.size()&&freq[q.front()]!=1){
			val[q.front()] = false;
			q.pop();
		}
		if(q.size())ans[queries[i].second] = q.front();
	}
	for(int i = 0; i<qq; i++){
		cout << ans[i] << "\n";
	}
	return 0;
}