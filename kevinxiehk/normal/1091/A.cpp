#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	a++;
	c--;
	cout<<min(min(a,c),b)*3<<endl;
	return 0;
}