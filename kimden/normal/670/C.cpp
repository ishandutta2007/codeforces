#include <bits/stdc++.h>
using namespace std;
const int MAXN=200111;
typedef pair<int,int> pii;

struct pred{
	bool operator() (pair<int,pii>&x, pair<int,pii>&y){
		if(x.second.first>y.second.first) return true;
		if(x.second.first<y.second.first) return false;
		if(x.second.second>y.second.second) return true;
		if(x.second.second<y.second.second) return false;
		return false;
	}
};

int main()
{
	int n,a,m,b[MAXN],c[MAXN];
	cin >> n;
	map<int,int> langs;
	for(int i=0;i<n;i++){
		cin >> a;
		langs[a]++;
	}
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> b[i];
	}
	for(int i=0;i<m;i++){
		cin >> c[i];
	}
	vector<pair<int,pii>> v;
	for(int i=0;i<m;i++){
		v.push_back(make_pair(i+1,make_pair(langs[b[i]],langs[c[i]])));
	}
	sort(v.begin(),v.end(),pred());
	cout << v.front().first;
	return 0;
}