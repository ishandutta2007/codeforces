#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int mod = 1e9 + 7;

vector<int> bkt[605];
int lazy[605], cmx, hit;

void erase(int p){
	for(int i=0; i<cmx; i++){
		if(!bkt[i].empty() && bkt[i].back() + lazy[i] >= p){
			auto l = lower_bound(bkt[i].begin(), bkt[i].end(), p - lazy[i]);
			bkt[i].erase(l);
			return;
		}
	}
}

void insert(int s){
	for(int i=0; i<cmx; i++){
		if(bkt[i].back() + lazy[i] >= s){
			auto l = lower_bound(bkt[i].begin(), bkt[i].end(), s - lazy[i]);
			bkt[i].insert(l, s - lazy[i]);
			if(bkt[i].size() >> 11) hit = 1;
			return;
		}
	}
	bkt[cmx-1].push_back(s - lazy[cmx - 1]);
	if(bkt[cmx-1].size() >> 11) hit = 1;
}

void update(int s, int e){
	for(int i=0; i<cmx; i++){
		if(!bkt[i].empty()){
			int ps = bkt[i][0] + lazy[i], pe = bkt[i].back() + lazy[i];
			if(s <= ps && pe <= e) lazy[i]++;
			else if(max(s, ps) <= min(e, pe)){
				for(auto &j : bkt[i]){
					if(s <= j + lazy[i] && j + lazy[i] <= e) j++;
				}
			}
		}
	}
}

void remake(){
	vector<int> v;
	for(int i=0; i<cmx; i++){
		for(auto &j : bkt[i]) v.push_back(j + lazy[i]);
		lazy[i] = 0;
		bkt[i].clear();
	}
	for(int i=0; i<v.size(); i++){
		bkt[i >> 10].push_back(v[i]);
		cmx = (i >> 10) + 1;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int cnt = 0;
	int s, e;
	scanf("%d %d",&s,&e);
	bkt[0].push_back(s);
	cmx = 1;
	for(int i=1; i<n; i++){
		int s, e;
	//	s = rand() % 987654321;
	//	e = rand() % 987654321;
	//	if(s > e) swap(s, e);
		scanf("%d %d",&s,&e);
		erase(e);
		update(s, e-1);
		insert(s);
		if(hit){
			hit = 0;
			remake();
		}
	}
	int ret = 0;
	for(int i=0; i<605; i++) ret += bkt[i].size();
	cout << ret;
}