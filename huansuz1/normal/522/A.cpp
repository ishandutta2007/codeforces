#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<map>

using namespace std;
string x[1234],y[1234],s,a[1234][1234],l="abcdefghijklmnopqrstuvwxyz";
int n,b[1234];
int main(){
cin>>n;
for (int i=0; i<n; i++) {
	cin>>x[i]>>s>>y[i]; 
	s="";
	s=x[i];
	for (int j=0; j<x[i].length(); j++)
		if (s[j]>='A' && s[j]<='Z') s[j]=l[s[j]-'A'];
	x[i]=s;
	s="";
	s=y[i];
	for (int j=0; j<y[i].length(); j++)
		if (s[j]>='A' && s[j]<='Z') s[j]=l[s[j]-'A'];
	y[i]=s;       
	if (y[i]=="polycarp") a[1][b[1]++]=x[i]; else {
		int p=0;
		for (int j=1; j<=n; j++){
			for (int o=0; o<b[j]; o++)
				if (a[j][o]==y[i]) {a[j+1][b[j+1]++]=x[i]; p=1; break;}
			if (p==1) {break; }
		}
	}
}

int k=0;
for (int i=1; i<=n; i++){
	if (b[i]==0) break; 
	k=i;
}
cout<<k+1;






}