#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,e,d,p,ma,z;
int a,b;
long long s;
 
int main(){
	cin>>n>>s;
	for (int i=1; i<=n; i++) {
		cin>>a>>b;
		if (a<s && (100-b)>ma && b>0) ma=100-b;
		if (s>a || (s==a && b==0)) z++;
	}
	if (z!=0)cout<<ma; else cout<<-1;

	return 0;
}