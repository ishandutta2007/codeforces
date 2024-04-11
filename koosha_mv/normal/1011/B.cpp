#include<iostream>
using namespace std;
int a[103][2]={0},x,n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){cin>>x;a[x][0]++;}
	int mx=0,am,mn;
	for(int i=0;i<n;i++){
		mx=0;
		for(int j=0;j<102;j++)
		{
			if(a[j][0]/(a[j][1]+1)>mx){
				mx=a[j][0]/(a[j][1]+1);
				am=j;
			}
		}
		a[am][1]++;
	}
	mn=200;
	for(int i=0;i<102;i++){
		if(a[i][1]>0){
			mn=min(a[i][0]/a[i][1],mn);
		}
	}
	cout<<mn;
}