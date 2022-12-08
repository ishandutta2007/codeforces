#include<iostream>
#include<cmath>
using namespace std;

int main(){

	int a,w=0;
	cin>>a;
	int v[26];
	string n;
	cin>>n;
	
	for (int q=0;q<26;q++){
		v[q]=1;
	}
	for (int q=0;q<a;q++){
		if ('a'<=n[q] && 'z'>=n[q]){
			v[n[q]-'a']++;
		}
		if ('A'<=n[q] && 'Z'>=n[q]){
			v[n[q]-'A']++;
		}
	}
	for (int q=0;q<26;q++){
		if (v[q]==1){
			w++;
		}
	}
	if (w==0){
		cout<<"YES"<<"\n";
	}
	else {
		cout<<"NO\n";
	}
	
	return 0;
}