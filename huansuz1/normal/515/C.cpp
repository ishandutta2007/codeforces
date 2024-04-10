#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int k,n,m,a[100],z;
string s;


int main(){
cin>>m>>s;
n=s.length()-1;

while(n!=-1){
k=s[n]-'0';
if (k==2) a[z++]=2;
if (k==3) a[z++]=3;
if (k==4) {a[z++]=3;a[z++]=2;a[z++]=2; }
if (k==5) {a[z++]=5; }
if (k==6) {a[z++]=3;a[z++]=5; }
if (k==7) {a[z++]=7; }
if (k==8) {a[z++]=7;a[z++]=2;a[z++]=2;a[z++]=2; }
if (k==9) {a[z++]=3;a[z++]=3;a[z++]=7; a[z++]=2; }
n--;

}
sort(a,a+z);
for (int i=z-1; i>=0; i--)
cout<<a[i];


return 0;
}