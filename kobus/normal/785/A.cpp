#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int resp=0;
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if (s=="Tetrahedron"){
			resp+=4;
		}
		if (s=="Cube"){
			resp+=6;
		}
		if (s=="Octahedron"){
			resp+=8;
		}
		if (s=="Dodecahedron"){
			resp+=12;
		}
		if (s=="Icosahedron"){
			resp+=20;
		}
	}
	cout<<resp<<"\n";
	return 0;
}