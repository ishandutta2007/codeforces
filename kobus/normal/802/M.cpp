#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int v[11234];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a,b;
	cin>>a>>b;

	for(int i=0;i<a;i++){
		cin>>v[i];
	}
	sort(v,v+a);
	int resp=0;
	for(int i=0;i<b;i++){
		resp+=v[i];
	}
	cout<<resp<<"\n";

	return 0;
}