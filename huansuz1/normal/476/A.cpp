#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n,m,k,p,t;
int main(){
	cin>>n>>m;
	if (n<m) cout<<-1; else
		if (n==m) cout<<n; else {
		k=n/2; p=n%2;
		while((k+p)%m!=0){
		k--;p+=2; 
		if (k<0) {t=1; break;}
		}
		if (t==0) cout<<k+p; else cout<<-1;
		
		}




}