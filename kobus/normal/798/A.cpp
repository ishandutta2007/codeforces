#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	string n;
	cin>>n;
	int counter=0;
	
	if(n.size()%2==0){
		for(int i=0;i<n.size()/2;i++){
			if(n[i]!=n[n.size()-i-1]){
				counter++;
			}
		}
		if(counter==1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	} 
	else{
		for(int i=0;i<(n.size()-1)/2;i++){
			if(n[i]!=n[n.size()-i-1]){
				counter++;
			}
		}
		if(counter==1 || counter==0){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	
	return 0;
}