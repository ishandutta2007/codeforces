#include<bits/stdc++.h>
using namespace std;
long long n,x,y;
void work(){
	cin>>n;
	x=n;
	y=2;
	while(x%2==0)x/=2,y<<=1;
	if((__int128)n-(__int128)y/2*(y-1)>0)cout<<y<<endl;
	else {
		if(x==1)cout<<-1<<endl;
		else cout<<x<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}