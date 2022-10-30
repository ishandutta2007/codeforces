#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;

int q=9,r=5,b=3,n=3,p=1,k=0,s,s1;
char x;

int main(){
for (int i=0; i<8; i++)
	for (int j=0; j<8; j++)  {
		cin>>x;
		if (x=='q') s+=9; 
	    if (x=='r') s+=5; 
	    if (x=='b') s+=3; 
	    if (x=='n') s+=3; 
	    if (x=='p') s+=1; 
	    if (x=='k') s+=0; 

	    if (x=='Q') s1+=9; 
	    if (x=='R') s1+=5; 
	    if (x=='B') s1+=3; 
	    if (x=='N') s1+=3; 
	    if (x=='P') s1+=1; 
	    if (x=='K') s1+=0; 
	}

if (s1>s) cout<<"White"; else 
	if (s>s1) cout<<"Black"; else cout<<"Draw";





}