#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int sa,mi,sa1,mi1,z;
string s,t;


int main(){
	cin >> s >> t;
	sa=(s[0]-'0')*10 + (s[1]-'0');
	mi=(s[3]-'0')*10 + (s[4]-'0');
	sa1=(t[0]-'0')*10 + (t[1]-'0');
	mi1=(t[3]-'0')*10 + (t[4]-'0');
	if (sa==sa1 && mi==mi1) {cout<<"00:00"; exit(0);}
	while(z!=-1){
		z++;
		mi1++;
		if (mi1==60) {sa1++;mi1=0;}
		if (sa1==24) sa1=0;
		if (sa==sa1 && mi==mi1) break;
	}
	
	if ((z/60)<10)  cout<<'0'<<z/60<<':'; else cout<<z/60<<':'; 
	if ((z%60)<10)  cout<<'0'<<z%60; else cout<<z%60; 
	


	
	return 0;
}