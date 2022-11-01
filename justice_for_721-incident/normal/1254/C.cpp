#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
vector<pair<ll,int> >a,b;
deque<int>c,d;
ll s[1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=3; i<=n ;i++){
		cout << "1 " << 1 << ' ' << 2 << ' ' << i << endl;
		ll res;cin >> res;
		s[i]=res;
	}
	for(int i=3; i<=n ;i++){
		cout << "2 " << 1 << ' ' << 2 << ' ' << i << endl;
		int res;cin >> res;
		if(res==1) a.push_back({s[i],i});
		else b.push_back({s[i],i});
	}
	if(!a.empty()){
		sort(a.begin(),a.end());
		int boss=a.back().se;
		a.pop_back();
		c.push_back(boss);
		reverse(a.begin(),a.end());
		for(auto cur:a){
			cout << "2 " << 1 << ' ' << boss << ' ' << cur.se << endl;
			int res;cin >> res;
			if(res==1) c.push_front(cur.se);
			else c.push_back(cur.se);
		}
	}
	if(!b.empty()){
		sort(b.begin(),b.end());
		int boss=b.back().se;
		b.pop_back();
		d.push_back(boss);
		reverse(b.begin(),b.end());
		for(auto cur:b){
			cout << "2 " << 2 << ' ' << boss << ' ' << cur.se << endl;
			int res;cin >> res;
			if(res==1) d.push_front(cur.se);
			else d.push_back(cur.se);
		}
	}
	reverse(d.begin(),d.end());
	reverse(c.begin(),c.end());
	cout << "0 1 ";
	for(auto cur:d) cout << cur << ' ';
	cout << "2 ";
	for(auto cur:c) cout << cur << ' ';
	cout << endl;
}