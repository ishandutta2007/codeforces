#include<iostream>
using namespace std;

int main(){
	int a,b,c,d;cin>>a>>b>>c;
	cout<<1ll*(a%c?a/c+1:a/c)*(b%c?b/c+1:b/c);
	return 0;
}