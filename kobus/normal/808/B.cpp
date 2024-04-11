#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

int v[212345];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	double fw=0;
	for(int i=0;i<k;i++){
		fw+=v[i];
	}
	double resp=0;
	resp+=fw;

	for(int i=k;i<n;i++){
		fw+=v[i];
		fw-=v[i-k];
		resp+=fw;
	}
	resp=resp/(n-k+1);

	cout.precision(8);
    cout.setf(ios::fixed);
	cout<<resp<<"\n";

	
	return 0;
}