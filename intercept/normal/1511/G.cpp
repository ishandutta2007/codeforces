#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=2e5+9;
const int B=709;
int n,m,q;
int a[M],b[M],ans[M];
vector<pii>g[M];
void build(int r){
	for(int i=1;i<=m;++i)b[i]=0;
	for(int i=1;i<=r;++i){
		if(a[i]){
			for(int j=0;j<18;++j){
				if(i>=1<<j)b[i-(1<<j)]^=1<<j;
			}
		}
	}
	
	for(int i=m;i>=1;--i){
		for(int j=0;j<18;++j){
			if(b[i]>>j&1){
				if(i>=1<<j)b[i-(1<<j)]^=1<<j;
			}
		}
	}

	for(int i=m;i>=1;--i){
		b[i]^=b[i+1];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		a[x]^=1;
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int l,r;
		cin>>l>>r;
		g[r].eb(l,i);
	}
	for(int o=1;o<=m;o+=B){
		build(o-1);
		for(int i=o;i<o+B&&i<=m;++i){
			for(auto t:g[i]){
				ans[t.se]=b[t.fi];
				for(int j=o;j<=i;++j){
					if(a[j]){
						if(j>t.fi)ans[t.se]^=j-t.fi;
					}
				}
			}
		}
	}
	for(int i=1;i<=q;++i)cout<<(ans[i]?"A":"B");
	return 0;
}
/*
3 10
1 4 2
1
1 4



1000000000
0010000000
0010000000
0000001000
0001000000
0100000000
0000010000
0000000010
*/