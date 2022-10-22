#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn for(int i=0;i<n;i++)
int main(){
  string s;
  cin  >> s;
  int c=-1,zap=0,n=s.size();
  for(int i=0;i<n;i++){
  	if (s[i]=='.'){
  		zap=n-i;
  	}
  	if (c==-1 && s[i]!='0' && s[i]!='.'){
  		c=n-i;
  	}
  }
   int kol=0;
  for(int i=0;i<n;i++){
  	if (char(s[i])!='0' &&char(s[i])!='.' ){
  		kol++;
  	}
  }
  int pos=c-zap;
  if (pos>0){
  	pos--;
  }
  
  
  if (pos==0){
  	if (kol==1){
  		for(int i=0;i<n;i++){
  	if (char(s[i])!='0' &&char(s[i])!='.' ){
  		cout << s[i] ;
  		return 0;
  	}
  }
  	}
  	bool flag=false;
  	string ans="";
  	for(int i=0;i<n;i++){
  	if (char(s[i])!='0'){
  		cout <<ans <<  s[i] ;
  		ans="";
  		flag=true;
  	}
  	else if(flag){
  		ans+="0";
  	}
  }
 
  
  return 0;
  }
  bool flag=false;
  int f=0;
  	string ans="";
  	for(int i=0;i<n;i++){
  	if (f==1 && kol>1){
  		cout <<".";
  		f=2;
  	}
  	if (char(s[i])!='0' &&char(s[i])!='.' ){
  		cout <<ans <<  s[i] ;
  		ans="";
  		flag=true;
  		if (f==0){
  			f=1;
  		}
  	}
  	else if(flag && char(s[i])!='.'){
  		ans+="0";
  	}
  }
  cout << "E"<<pos;
  return 0;
    
   
}