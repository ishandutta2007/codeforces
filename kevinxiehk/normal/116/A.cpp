#include<bits/stdc++.h>
using namespace std;
int main(){
	long long max=0,on,off,n,now=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>off>>on;
		now+=on;
		now-=off;
		if(now>max)max=now;
	}
	cout<<max<<endl;
	return 0;
}