#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1000;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<ll> v,w;
	ll l;
	for(int i=0;i<n;i++){
		cin >> l;
		if(v.empty() || v.back()!=l){
			v.push_back(l);
		}
	}
	for(int i=0;i<m;i++){
		cin >> l;
		if(w.empty() || w.back()!=l){
			w.push_back(l);
		}
	}
	ll r = 0;
	auto it = v.begin();
	auto left = w.begin();
	auto right = w.begin()+1;
	bool b;
	while(it!=v.end()){
		b = true;
		while(llabs((*it)-(*left)) > llabs((*it)-(*right))){
			if(right==w.end()-1){
				b = false;
				break;
			}
			left++;
			right++;
		}
		if(b){
			r = max(r,llabs((*it)-(*left)));
		}else{
			r = max(r,llabs((*it)-(*right)));
		}
		it++;
	}
	cout << r;
}