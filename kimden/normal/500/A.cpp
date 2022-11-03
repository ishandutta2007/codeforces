#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n,t,m,k,i,j;
	int a[30001]={};
	bool b[30001]={};
	cin >> n >> t;
	for(i=1;i<=n-1;i++){
		cin >> a[i];
	}
	m=1;
	b[m]=true;
	while(m!=n ){
		m = m+a[m];
		b[m]=true;
	}
	if(b[t]){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}