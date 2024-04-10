#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	int a[3],b[3];
	cin>>a[0]>>a[2]>>a[1]>>b[0]>>b[2]>>b[1];
	vector<pair<int,int>>ops={
		{0,0},
		{0,1},
		{1,1},
		{1,2},
		{2,2},
		{2,0},
	};
	sort(ops.begin(),ops.end());
	int mx=min(a[0],b[2])+min(a[1],b[0])+min(a[2],b[1]);
	int mn=0;
	do{
		int at[3],bt[3];
		for(int i=0;i<3;++i)at[i]=a[i];
		for(int i=0;i<3;++i)bt[i]=b[i];
		int res=0;
		for(int i=0;i<6;++i){
			res+=min(at[ops[i].first],bt[ops[i].second]);
			at[ops[i].first]-=min(at[ops[i].first],bt[ops[i].second]);
			bt[ops[i].second]-=min(at[ops[i].first],bt[ops[i].second]);
		}
		mn=max(mn,res);
	}
	while(next_permutation(ops.begin(),ops.end()));
	cout<<n-mn<<" "<<mx<<endl;
}