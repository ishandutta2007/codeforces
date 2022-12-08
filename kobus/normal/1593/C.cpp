#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> v(k);
		for(int i=0;i<k;i++){cin>>v[i];v[i]=n-v[i];}
		sort(v.begin(),v.end());
		int cat=n;
		int num=0;
		for(int i=0;i<k;i++){
			if(cat<=v[i])break;
			num++;
			cat-=v[i];
		}
		cout<<num<<endl;
	}
}