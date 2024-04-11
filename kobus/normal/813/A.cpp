#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int v[112345];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum=0;
	int pro,per;
	cin>>pro;
	for(int i=0;i<pro;i++){
		int el;
		cin>>el;
		sum+=el;
	}
	cin>>per;
	for(int i=0;i<per;i++){
		int a,b;
		cin>>a>>b;
		v[i]=a;
		if(sum>=a && sum<=b){
			cout<<sum<<"\n";
			return 0;
		}
	}
	sort(v,v+per);
	for(int i=0;i<per;i++){
		if(v[i]>sum){
			cout<<v[i]<<"\n";
			return 0;
		}
	}
	
	cout<<"-1\n";
	return 0;
}