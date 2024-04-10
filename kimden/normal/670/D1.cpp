#include <bits/stdc++.h>
using namespace std;
const int MAXN=200111;
typedef pair<int,int> pii;

struct pred{
	bool operator() (pii&x, pii&y){
		return x.first*1LL*y.second < y.first*1LL*x.second;
	}
};

int main()
{
	int n,k,a[MAXN],b[MAXN],dk;
	int i;
	vector<pii> v;
	double least=2e9;
	int bottom,top,sum;
	vector<pii>::iterator it;
	cin >> n >> k;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	for(i=0;i<n;i++){
		cin >> b[i];
		v.push_back(make_pair(b[i],a[i]));
	}
	sort(v.begin(),v.end(),pred());
	while(1){
		sort(v.begin(),v.end(),pred());
		bottom = v.front().first/v.front().second;
		top = bottom+1;
		it = v.begin();
		sum = 0;
		while(it!=v.end() && (int)(it->first/it->second)==bottom){
			sum += it->second * top - it->first;
			it++;
		}
		if(sum<=k){
			while(it!=v.begin()){
				it--;
				it->first = top*it->second;
			}
			k-=sum;
		}else{
			cout << bottom;
			return 0;
		}
	}
	return 0;
}