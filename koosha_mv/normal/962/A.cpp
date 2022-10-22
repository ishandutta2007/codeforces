#include<iostream>
using namespace std;
long long a[200002],n,j=0,x;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;j+=x;a[i]=x;}
	j=(j/2)+(j%2);
	long long i=0;
	while(j>0){
		j-=a[i];
		i++;
	}
	cout<<i;
}