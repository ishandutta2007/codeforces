#include<iostream>
#include<algorithm>
using namespace std;
int g1[1009],g2[1009];
int main(){
	int n,p1,t=0,p2;
	string s1,s2;cin>>n>>s1>>s2;
	for(int i=0;i<n;i++){
		g1[i]=int(s1[i])-'0';}
	for(int i=0;i<n;i++){
		g2[i]=int(s2[i])-'0';}
	p1=n-1;p2=n-1;
	sort(g1,g1+n);sort(g2,g2+n);
	while(p1>=0){
		if(g2[p2]>=g1[p1]){
			p2--;
			t++;}
		p1--;}
	cout<<n-t<<endl;t=0;
	p1=n-1;p2=n-1;
	while(p1>=0){
		if(g2[p2]>g1[p1]){
			p2--;
			t++;}
		p1--;}
	cout<<t;
}