#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int v[212345];

int main(){
	
	int n;
	cin>>n;
	int a=2123456789;
	int a2=0;
	 for(int q=0;q<n;q++){
	 	cin>>v[q];
	}
	std::sort(v,v+n);
	for (int q=0;q<n-1;q++){
		if(abs(v[q+1]-v[q])<a){
			a=abs(v[q+1]-v[q]);
		}
	}
	for (int q=0;q<n-1;q++){
		if(abs(v[q+1]-v[q])==a){
			a2++;
		}
	}
	cout<<a<<" "<<a2<<"\n";
	return 0;
}