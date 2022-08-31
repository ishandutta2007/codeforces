#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,x[100001],y[100001],tot;
int main(){
	cin>>n;
	tot=1;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(x[i]==x[i-1]&&y[i]==y[i-1])continue;
		tot+=max(min(x[i],y[i])-max(x[i-1],y[i-1])+1,0);
		if(x[i-1]==y[i-1])--tot;
	}
	cout<<tot;
}