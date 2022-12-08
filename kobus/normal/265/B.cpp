#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int n, v[100001],r=0;
	cin>>n;
	for(int y=0; y<n; y++){
		int q;
		cin>>q;
		v[y]=q;
	}
	r=r+v[0];
	for (int w=0; w<n-1; w++){
		r=r+2+abs(v[w]-v[w+1]);

	}
	cout<<r+1<<"\n";

	return 0;

}