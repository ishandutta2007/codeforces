#include <bits/stdc++.h>
using namespace std;
int v[112345];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	long long int resp=0,mark=0;
	for(int i=0;i<n;i++){
		long long int it,cl;
		cin>>it>>cl;
		if(it>=cl){
			resp+=cl;
		}
		else{
			resp+=it;
			if(2*it>=cl){
				v[mark]=cl-it;
				mark++;
			}
			else{
				v[mark]=it;
				mark++;
			}
		}
	}
	sort(v,v+mark);
	if(mark>0){
		for(int i=mark-1;i>=mark-k && i>=0;i--){
			resp+=v[i];
		}
	}
	cout<<resp<<"\n";
	return 0;
}