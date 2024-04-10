#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n,k,res;

int main(){
	cin>>n>>k;
	while(1){
		if(k&1){printf("%lld",res+1);return 0;}
		res++;k>>=1;
	}
}