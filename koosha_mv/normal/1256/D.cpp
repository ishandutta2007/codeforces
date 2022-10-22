#include<iostream>
using namespace std;
int main(){
	long long q,n,k,j=0,l;
	string s;cin>>q;
	while(q--){
		cin>>n>>k>>s;
		j=0;
		for(long long i=0;i<s.size();i++){
			if(s[i]=='0'){
				l=min(i-j,k);
				swap(s[i],s[i-l]);
				j++;
				k-=l;}}
		cout<<s<<endl;}}