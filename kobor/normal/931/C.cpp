#include <bits/stdc++.h>

using namespace std;

int t[100000];
int zlicz[3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, mink=100000009, maxk=-100000009, l=0, w1, w2, wyps=0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>t[i];
		mink=min(mink, t[i]);
		maxk=max(maxk, t[i]);
	}
	if(maxk-mink<2){
		cout<<n<<'\n';
		for(int i=0; i<n; i++){
			cout<<t[i]<<' ';
		}
		cout<<'\n';
		return 0;
	}
	for(int i=0; i<n; i++){
		if(t[i]==mink){
			zlicz[0]++;
		}
		else if(t[i]==maxk){
			zlicz[2]++;
		}
		else{
			zlicz[1]++;
		}
	}
	w1=zlicz[1]+abs(zlicz[2]-zlicz[0]);
	w2=zlicz[0]+zlicz[2]+(zlicz[1]%2);
	cout<<min(w1, w2)<<'\n';
	if(w1<w2){
		if(zlicz[2]>zlicz[0]){
			for(int i=0; i<zlicz[2]-zlicz[0]; i++){
				cout<<maxk<<' ';
				wyps++;
			}
		}
		else{
			for(int i=0; i<zlicz[0]-zlicz[2]; i++){
				cout<<mink<<' ';
				wyps++;
			}
		}
		for(int i=wyps; i<n; i++){
			cout<<mink+1<<' ';
		}
		cout<<'\n';
		return 0;
	}
	else{
		if(zlicz[1]%2){
			cout<<mink+1<<' ';
		}
		for(int i=0; i<zlicz[0]+zlicz[1]/2; i++){
			cout<<mink<<' ';
		}
		for(int i=0; i<zlicz[2]+zlicz[1]/2; i++){
			cout<<maxk<<' ';
		}
		cout<<'\n';
		return 0;
	}
	return 0;
}