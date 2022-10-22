#include<bits/stdc++.h>
using namespace std;
int n,a[50],x,r[6],y;
int main(){
	cin>>n;
	a[4]=0,a[8]=1,a[15]=2,a[16]=3,a[23]=4,a[42]=5;
	int ant=n;
	while(n--){
		scanf("%d",&x);
		y=a[x];
		if(y==0)r[y]++;
		if(y>0&&r[y-1]>0)r[y-1]--,r[y]++;
	}
	cout<<ant-6*r[5]<<endl;
	return 0;
	
}