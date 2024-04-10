#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#define LL unsigned long long
#define N 110 
using namespace std;
LL n,m,k;
int main(){
	cin>>n>>m>>k;
	if(k<n){
		++k;
		cout<<k<<" "<<1<<endl;return 0;
	}
	k=k-n;++k;
	LL a=k/(m-1),b,c=1;++a;
	if(k%(m-c)==0) --a;
	b=k%(m-c);
	if(!b) b=m-c;
	if(a&1) ++b;
	else b=m+c-b;
	a=n+c-a;
	cout<<a<<" "<<b<<endl;
	return 0;
}