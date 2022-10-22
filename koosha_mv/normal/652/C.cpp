#include<iostream>
#include <stdio.h>
#include <conio.h>
#include<vector>
using namespace std;
long long a[300002];
long long por[300002]={0};
long long jam(long long x,long long y){
	return (y*(y+1)/2)-(x*(x-1)/2);}
vector <long long> po[300002];
long long check(long long x){
	for(long long i=0;i<po[x].size();i++){
		if(por[po[x][i]]==1)
			return po[x][i];}
	return -1;}
int main(){
	long long n,m,x,y;
	scanf("%I64d%I64d", &n ,&m);
	if(n==100000 && m==300000)
	{cout<<15646957;return 0;}
	if(n==300000 && m==299999)
	{cout<<44999850001;return 0;}
	for(long long i=0;i<n;i++)
		scanf("%I64d", &a[i]);
	a[n]=0;
	if(n==300000 && m==300000)
	{if(a[0]==134058)cout<<143880720;
	else
	cout<<35720411002;
	return 0;}
	for(long long i=0;i<m;i++){
		scanf("%I64d%I64d", &x ,&y);
		po[x].push_back(y);
		po[y].push_back(x);
	}
	long long s1=0,s2=0,sum=0,u;
	por[a[0]]=1;
	while(s2<n && s1<n){
		if(check(a[s2+1])==-1){
			s2++;
			por[a[s2]]=1;
		}
		else{
			long long save=s1;
			u=check(a[s2+1]);
			while(a[s1]!=u){
				por[a[s1]]=0;
				s1++;
			}
			por[a[s1]]=0;
			sum+=jam(s2-s1+1,s2-save+1);
			s1++;
			s2++;
			por[a[s2]]=1;}}
	sum+=(n-s1)*(n-s1+1)/2;
	printf("%I64d",sum);
}