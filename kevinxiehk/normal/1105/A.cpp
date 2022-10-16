#include<bits/stdc++.h>
using namespace std;
int mincost=999999,mint;
int n;
int len[1010];
void test(int a){
	int cost=0,b;
	for(int i=1;i<=n;i++){
		b=abs(len[i]-a);
		if(b>0)b--;
		cost+=b;
	}
	if(cost<mincost){
		mincost=cost;
		mint=a;
	}
}
int main(){

	cin>>n;
	for(int i=1;i<=n;i++)cin>>len[i];
	for(int i=1;i<=100;i++)test(i);
	cout<<mint<<" "<<mincost<<endl;
	return 0;
}