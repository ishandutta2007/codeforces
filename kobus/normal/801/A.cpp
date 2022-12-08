#include<bits/stdc++.h>
using namespace std;
char v[112];

int main(){
	string n;
	cin>>n;
	int counter=0;
	int countermax=0;
	for(int i=0;i<n.size();i++){
		v[i]=n[i];
	}
	for(int i=0;i<n.size();i++){
		if (n[i]=='V' && n[i+1]=='K'){
			counter++;
		}
		if (counter>countermax){
			countermax=counter;
		}
	}
	counter=0;
	for(int i=0;i<n.size();i++){
		if(v[i]=='V'){
			v[i]='K';
		}
		else{
			v[i]='V';
		}
		for(int j=0;j<n.size();j++){
			if (v[j]=='V' && v[j+1]=='K'){
				counter++;
			}
			if (counter>countermax){
				countermax=counter;
			}
		}
		if(v[i]=='V'){
			v[i]='K';
		}
		else{
			v[i]='V';
		}
		counter=0;
	}
	cout<<countermax<<"\n";
	return 0;
}