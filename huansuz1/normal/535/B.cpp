#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>


using namespace std;
long long n,a[12423],b[12347],z,k,m;
void rec(int v){
    if (v>=n) {
    	int p=1;
    	for (int i=0; i<n; i++) {
    		b[z]=(b[z]*p)+a[i];
    		p=10;
    	}
    	z++;
    	return;
    }
    a[v]=4; 
    rec(v+1);
    a[v]=7;
    rec(v+1);
}           

int main(){

cin>>m;
for (int i=1; i<=9; i++) {
	n=i;
	rec(0);               
}
sort(a,a+z);
b[0]=4;
for (int i=0; i<z; i++)
	if (b[i]==m)  { cout<<i+1; return 0;}
return 0;
}