#include<iostream>
#include<algorithm>
using namespace std;
int n,x,a,j=0,kh[300009];
pair <int,int> p[300009];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		p[i].first=x;
		p[i].second=i;}
	sort(p,p+n);
	for(int i=0;i<n;i++){
		j=max(j,p[i].first);
		kh[p[i].second]=j;
		j++;}
	for(int i=0;i<n;i++)
		cout<<kh[i]<<" ";
}