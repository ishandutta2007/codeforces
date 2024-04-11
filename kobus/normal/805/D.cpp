#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string n;
	cin>>n;
	int modu=1000000007;
	int numb=0;
	int numbes=0;
	int numbdir=0;
	
	int resp=0;
	for(int i=0;i<n.size();i++){
		if(n[i]=='b'){
			numb++;
			numbes++;
		}
	}
	for(int i=n.size()-1;i>=0;i--){
		if(n[i]=='b'){
			numbdir++;
			numbes--;
		}
		else{
			numbdir=(numbdir*2)%modu;
			numbes--;
		}
	}
	cout<<(numbdir-numb)%modu<<"\n";
	return 0;
}