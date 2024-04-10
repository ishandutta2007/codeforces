#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000007
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	int a;
	for(int i=0;i<n;++i){
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int mx = 0;
	for(int i=0;i<n;i++){
		if(v[i]>mx){
			mx++;
		}
	}
	cout << mx+1;
}