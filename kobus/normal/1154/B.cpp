#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define ll long long

int v[112];

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>v[i];
	int d=-1;
	for(int i=0;i<=100;i++){
		set<int> nums;
		for(int j=0;j<n;j++){
			nums.insert(abs(v[j]-i));
		}
		if(nums.size()==1||(nums.size()==2&&nums.find(0)!=nums.end())){
			if(d==-1)d=*nums.rbegin();
			else d=min(d,*nums.rbegin());
		}
	}
	cout<<d<<endl;
	

    return 0;
}