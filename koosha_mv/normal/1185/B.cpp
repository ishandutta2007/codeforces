#include<bits/stdc++.h>
using namespace std;
int main(){
	int q,s=0,qwe;
	string s1,s2;
	cin>>q;
	if(1==0){q=0;}
	else{
	for(int qq=0;qq<q;qq++){
		cin>>s1>>s2;
		s2+="  ";
		if(s1[0]==s2[0]){
		s=1;
		qwe=0;
		for(int i=1;i<s1.size();i++){
			if(s1[i]!=s2[s]){
				if(s2[s]==s2[s-1]){
				while(s2[s]==s2[s+1])
					s++;
				//cout<<s<<endl;
				s++;
				if(s1[i]!=s2[s]){
					//cout<<i<<" "<<s<<" ";
					cout<<"NO"<<endl;qwe=1;
					break;
				}	
				}
				else{
					cout<<"NO"<<endl;qwe=1;
					break;	
				}
			}
			s++;
		}
		
		s--;
		if(qwe==0){
			while(s2[s]==s2[s+1])
					s++;
				if(s==s2.size()-3)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
		}
		else
			cout<<"NO"<<endl;
	}
}
}