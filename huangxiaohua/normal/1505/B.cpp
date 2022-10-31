#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,x,y,t,sb;

int chk(int sb){
	if(sb<=9){return sb;}
	int k=0;
	while(sb){k+=sb%10;sb/=10;}
	return chk(k);
}

int main(){
	cin>>sb;
	cout<<chk(sb);
}