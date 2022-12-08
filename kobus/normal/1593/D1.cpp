#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		sort(v.begin(),v.end());
		int num=0;
		for(int i=0;i<n;i++){
			num=gcd(v[i]-v[0],num);
		}   
		if(num==0)num=-1;                      
		cout<<num<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	}
}