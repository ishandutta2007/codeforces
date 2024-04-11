#include<iostream>
using namespace std;
long long h[1000000],m[1000000];
int main(){
	string s;
	long long sum=0,sh=0,sm=0,s1=0,s2=0;
	cin>>s;
	s+="ZZZZZZ";
	for(long long i=0;i<s.size();i++){
		if(s[i]=='h' && s[i+1]=='e' && s[i+2]=='a' && s[i+3]=='v' && s[i+4]=='y'){
			h[sh]=i;
			sh++;}
		if(s[i]=='m' && s[i+1]=='e' && s[i+2]=='t' && s[i+3]=='a' && s[i+4]=='l'){
			m[sm]=i;
			sm++;}
	}
	while(s1<sh && s2<sm){
		if(h[s1]<m[s2]){
			sum+=(sm-s2);
			s1++;}
		else{
			s2++;
		}
	}
	cout<<sum;
}