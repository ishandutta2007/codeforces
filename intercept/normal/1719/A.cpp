#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;
void work(){
	int a,b;
	cin>>a>>b;
	puts((a+b)&1?"Burenka":"Tonya");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}