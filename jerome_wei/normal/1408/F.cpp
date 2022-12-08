#include<bits/stdc++.h>
using namespace std;

int n;

typedef pair<int,int> pi;
vector<pi> ans;
inline void add(int x,int y){
	// cout << x << "," << y << endl;
	ans.push_back({x,y});
}

inline void solve(int l,int r){
	// cout << l << ":" << r << endl;
	if(l==r)return ;
	int mid = (l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	for(int i=l;i<=mid;i++)add(i,mid+i-l+1);
}

int main()
{
	cin >> n;
	int Len = 1;while(Len<<1<=n)Len<<=1;
	solve(1,Len);
	solve(n-Len+1,n);
	cout << ans.size() << endl;
	for(auto p:ans){
		printf("%d %d\n",p.first,p.second);
	}
}