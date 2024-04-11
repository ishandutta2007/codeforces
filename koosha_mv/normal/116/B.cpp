#include<iostream>
using namespace std;
int a[103][103]={0};
int k(int i, int j){
	if(a[i][j]==2 &&(a[i-1][j]==1 || a[i][j-1]==1 || a[i+1][j]==1 || a[i][j+1]==1))
		return 1;
	return 0;
}
int t(char s){
	if(s=='.')
		return 0;
	if(s=='P')
		return 1;
	return 2;
}
int main()
{
	int n,m;
	int sh=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		char s;
		cin>>s;
		a[i][j]=t(s);}}
	for(int i=0;i<n+2;i++){
		for(int j=0;j<m+2;j++){
			sh+=k(i,j);}}
	cout<<sh;
}