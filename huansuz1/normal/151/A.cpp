#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,k,l,c,d,p,nl,np;

int main(){
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	int litr=k*l/nl;
	int lime=c*d;
	int mass=p/np;
	int minn=123456;
	minn=litr;
	if (lime<minn) minn=lime;
	if (mass<minn) minn=mass;
	cout<<minn/n;


	
	return 0;
}