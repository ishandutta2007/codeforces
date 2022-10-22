#include<iostream>
using namespace std;
int main(){
	int t;string s;cin>>t;
	for(int lo=0;lo<t;lo++){
		cin>>s;
		int ff=0,zz=0,z[300009]={0},f[300009]={0},sf=0,sz=0;
		for(int i=0;i<s.size();i++){
			if((s[i]-'0')%2==0) z[sz]=s[i]-'0',sz++;
			else f[sf]=s[i]-'0',sf++;
		}
		while(ff<sf && zz<sz){
			if(z[zz]<f[ff]){
				cout<<z[zz];zz++;}
			else{cout<<f[ff];ff++;}
		}
		for(int i=ff;i<sf;i++) cout<<f[i];
		for(int i=zz;i<sz;i++) cout<<z[i];cout<<endl;
	}
}