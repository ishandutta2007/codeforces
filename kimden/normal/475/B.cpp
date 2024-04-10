#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	bool b=true;
	char c1,c2,c3,c4;
	char c;
	for(int i=0;i<n;i++){
	   c='\n';
	   while(c=='\n') cin >> c;
	   if(i==0){
		   c1=c;
	   }
	   if(i==n-1){
		   c2=c;
	   }
	}
	for(int i=0;i<m;i++){
	   c='\n';
	   while(c=='\n') cin >> c;
	   if(i==0){
		   c3=c;
	   }
	   if(i==m-1){
		   c4=c;
	   }
	}
	b = b && !((c1=='<' && c3=='^')||(c1=='>' && c3=='v'));
	b = b && !((c1=='>' && c4=='^')||(c1=='<' && c4=='v'));
	b = b && !((c2=='<' && c4=='^')||(c2=='>' && c4=='v'));
	b = b && !((c2=='>' && c3=='^')||(c2=='<' && c3=='v'));
	if(b){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}