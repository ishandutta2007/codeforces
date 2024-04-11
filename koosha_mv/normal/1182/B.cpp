#include<iostream>
#include<math.h>
#include<algorithm>
#include <string>

using namespace std;
int col[500]={0},row[500]={0},t=0,h,w;
string a[1000];
int p(int i,int j){
	int t=0,xx,yy;
	int x[4]={0,1,0,-1},y[4]={1,0,-1,0};
	if(a[i][j]!='*' || a[i+1][j]!='*' || a[i][j+1]!='*' || a[i][j]!='*' || a[i][j]!='*' )
		return 0;
	for(int q=0;q<4;q++){
		xx=i+x[q];yy=j+y[q];
		while(xx>=0 && xx<h && yy>=0 && yy<w && a[xx][yy]=='*'){
			xx+=x[q];
			yy+=y[q];
			t++;}}
	return t+1;}
int main(){
	int n,sum=0;
	string s;
	cin>>h>>w;
	for(int i=0;i<h;i++){
		cin>>s;
		t+= count(s.begin(), s.end(), '*');
		a[i]=s;}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(p(i,j)>0){
				if(p(i,j)==t){
					cout<<"YES";
					return 0;}
				else{
					cout<<"NO";
					return 0;}}}}
	cout<<"NO";
}