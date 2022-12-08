#include<iostream>
using namespace std;

int main() {

	string A;
	string B;
	cin>>A>>B;
	int q=1;

	for (int a=0; a<B.size(); a++){
		if (B[a]==A[q-1]){
			q=q+1;
		}
	}
	cout<<q<<"\n";
	return 0;

}