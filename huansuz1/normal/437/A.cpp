#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
  
using namespace std;
int a[12];
char b[4]={'A','B','C','D'};
string s;
  
int main(){
    for (int i=0; i<4; i++){
    	cin>>s;
    	int p=0;
    	for (int j=2; j<s.length(); j++)
    		if ((s[j]>='a' && s[j]<='z' )||(s[j]>='A' && s[j]<='Z') )  p=1;
    	if (p==1) a[i]=s.length()-2;
    }
    for (int i=0; i<4; i++)
    	for (int j=0; j<4; j++)
    		if (a[i]>a[j]) { swap(a[i],a[j]); swap(b[i],b[j]); }    
    
    if (a[0]>=a[1]*2 && a[2]>=a[3]*2) cout<<'C'; else 	
    	if (a[0]>=a[1]*2 && a[0]!=0) cout<<b[0]; else 
    		if (a[3]*2<=a[2] && a[3]!=0) cout<<b[3]; else cout<<'C';
    return 0;
}