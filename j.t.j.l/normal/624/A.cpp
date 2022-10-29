#include<bits/stdc++.h>

using namespace std;

int main(){
	int d, L, v1, v2;
	cin>>d>>L>>v1>>v2;
	printf("%.10lf\n", (double)(L - d) / (v1 + v2));
	//cout<<(double)(L - d) / (v1 + v2)<<endl;
	return 0;
}