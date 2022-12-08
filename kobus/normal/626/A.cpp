#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[200];
	char b;
	int answer=0;
	int var=3779;

	for (int i=0; i<n; i++){
		cin>>b;
		if (b=='U'){
			a[i]= var;
		}
		if (b=='D'){
			a[i]= -1*var;
		}
		if (b=='R'){
			a[i]= 1;
		}
		if (b=='L'){
			a[i]= -1;
		}
	
	}


	for (int r=0;r<=n; r++){
		int v=0;
		int g=r;
		while (g<n){
			v=v+a[g];
			g=g+1;
			if (v==0){
				answer=answer+1;
			}
		}
	}
	cout<<answer<<"\n";
	return 0;
}