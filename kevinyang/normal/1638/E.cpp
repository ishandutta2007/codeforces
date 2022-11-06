#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<pair<signed,signed>,pair<signed,signed>>
struct BIT{
	vector<int>arr;
	int size;
	void init(int n){
		size = n;
		arr.resize(n+2);
	}
	void update(int x, int val){
		for(int a = x; a<=size; a+=a&-a){
			arr[a]+=val;
		}
	}
	int query(int x){
		int sum = 0;
		for(int a = x; a>0; a-=a&-a){
			sum+=arr[a];
		}
		return sum;
	}
	void change(int x, int val){
		int v = query(x)-query(x-1);
		update(x,val-v);
	}
	int query(int x, int y){//inclusive
		return query(y)-query(x-1);
	}
};
vector<int>sorted[1000005];
string queries[1000005];
int n,q;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q;
	BIT bt;
	bt.init(n+5);
	set<pii>s;// l,r,colour,time of query  [l,r] btw
	s.insert({{1,n},{1,0}});
	vector<int>v1(q+1);
	vector<int>v2(q+1);
	vector<int>v3(q+1);
	for(int i = 1; i<=q; i++){
		cin >> queries[i];
		if(queries[i]=="Color"){
			cin >> v1[i] >> v2[i] >> v3[i];
		}
		else if(queries[i]=="Add"){
			cin >> v1[i] >> v2[i];
		}
		else{
			cin >> v1[i];
		}
	}
	for(int i = 1; i<=n; i++){
		//sorted[i].push_back(-1);
		sorted[i].push_back(0);
	}
	for(int i = 1; i<=q; i++){
		if(queries[i]=="Color"){
			sorted[v3[i]].push_back(i);
		}
		else if(queries[i]=="Add"){
			sorted[v1[i]].push_back(i);
		}
	}
	vector<BIT>bit(n+1);
	for(int i = 1; i<=n; i++){
		bit[i].init((int)sorted[i].size());
	}
	for(int i = 1; i<=q; i++){
		if(queries[i]=="Add"){
			int idx = lower_bound(sorted[v1[i]].begin(),sorted[v1[i]].end(),i)-sorted[v1[i]].begin();
			bit[v1[i]].update(idx,v2[i]);
		}
	}
	for(int i = 1; i<=q; i++){
		if(queries[i]=="Color"){
			int l = v1[i]; int r = v2[i]; int cl = v3[i];
			if(true){
				pii pp = {{l,0},{0,0}};
				auto p = s.lower_bound(pp);
				if(p!=s.end()&&(*p).first.first==l){

				}
				else{
					p--;
					pii p2 = *p;
					pii add = {{p2.first.first,l-1},p2.second};
					s.insert(add);
					add = {{l,p2.first.second},p2.second};
					s.insert(add);
					s.erase(p);
				}
			}
			if(true){
				pii pp = {{r+1,0},{0,0}};
				auto p = s.lower_bound(pp);
				p--;
				if((*p).first.second!=r){
					pii p2 = *p;
					pii add = {{p2.first.first,r},p2.second};
					s.insert(add);
					add = {{r+1,p2.first.second},p2.second};
					s.insert(add);
					s.erase(p);
				}
			}
			while(true){
				pii pp = {{l,0},{0,0}};
				auto p = s.lower_bound(pp);
				pii p2 = *p;
				if(p==s.end())break;
				if(p2.first.first>r)break;
				int a = p2.first.first; int b = p2.first.second; int c = p2.second.first; int d = p2.second.second;
				int idx1 = lower_bound(sorted[c].begin(),sorted[c].end(),d)-sorted[c].begin();
				int idx2 = --lower_bound(sorted[c].begin(),sorted[c].end(),i)-sorted[c].begin();
				int sum = bit[c].query(idx1,idx2);
				bt.update(a,sum);
				bt.update(b+1,-sum);
				s.erase(p);
			}
			s.insert({{l,r},{cl,i}});
		}
		else if(queries[i]=="Add"){
			continue;
		}
		else{
			int l = v1[i];
			pii pp = {{l+1,0},{0,0}};
			auto p = s.lower_bound(pp); p--;
			pii p2 = *p;
			int a = p2.first.first; int b = p2.first.second; int c = p2.second.first; int d = p2.second.second;
			int idx1 = lower_bound(sorted[c].begin(),sorted[c].end(),d)-sorted[c].begin();
			int idx2 = --lower_bound(sorted[c].begin(),sorted[c].end(),i)-sorted[c].begin();
			int sum = bit[c].query(idx1,idx2);
			int v = bt.query(l);
			cout << v+sum << "\n";
		}
	}
	return 0;
}