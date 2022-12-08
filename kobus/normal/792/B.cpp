#include <iostream>

using namespace std;

int main(){
	
	int n,v[101],k,a;
	cin>>n>>k;
	int l=0;

	for (int q=0;q<=n;q++){
		v[q]=q+1;
	}
	for (int q=0;q<k;q++){
		cin>>a;
		cout<<v[(l+a)%n]<<" ";
		for (int w=((l+a)%n);w<n;w++){
			v[w]=v[w+1];
		} 
		l=(a+l)%n;
		n-=1;
	}
	cout<<"\n";

	return 0;
}