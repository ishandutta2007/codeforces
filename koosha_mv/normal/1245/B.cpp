#include<iostream>
using namespace std;
int main(){
	int t,n,a,b,c,ro,pa,si,r,p,s;
	string s1;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>a>>b>>c>>s1;
		ro=0;pa=0;si=0;
		for(int j=0;j<n;j++){
			if(s1[j]=='R')
				ro++;
			if(s1[j]=='P')
				pa++;
			if(s1[j]=='S')
				si++;}
		r=min(si,a);p=min(b,ro);s=min(c,pa);
		if(r+p+s<(n+1)/2)
			cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			for(int j=0;j<n;j++){
				if(s1[j]=='S'){
					if(r){
						r--;
						a--;
						cout<<'R';
					}
					else{
						if(b>p){
							cout<<'P';b--;
						}
						else{
							cout<<'S';
							c--;
						}
					}
				}
				if(s1[j]=='R'){
					if(p){
						p--;
						b--;
						cout<<'P';
					}
					else{
						if(c>s){
							c--;
							cout<<'S';
						}
						else{
							cout<<'R';
							a--;
						}
					}
				}
				if(s1[j]=='P'){
					if(s){
						s--;
						c--;
						cout<<'S';
					}
					else{
						if(b>p){
							b--;
							cout<<'P';
						}
						else{
							a--;
							cout<<'R';
						}
					}
				}
			}	
			cout<<endl;
		}
	}
}