#include<iostream>
using namespace std;
int n,k=1;
string a[60];
int crct(int x,int y){
	if(a[x][y]!='.')
		return 1;
	x++;
	if(x==n || y==n)
		return 0;
	if(a[x][y]=='.' && a[x+1][y]=='.' && a[x][y+1]=='.' && a[x-1][y]=='.' && a[x][y-1]=='.'){
		a[x][y]='0';a[x+1][y]='0';a[x][y+1]='0'; a[x-1][y]='0';a[x][y-1]='0';
		for(int i=0;i<n;i++){
		}
		return 1;
	}
	return 0;}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			k=k*crct(i,j);}}
	if(k==1)cout<<"YES";
	else cout<<"NO";
}