#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n,m, w[111111],a,cnt=0;
char s[222222];
int main()
{
	cin>>s>>m;
	n=strlen(s);
	for(int i=0; i<m; i++){
		cin>>a;
		w[a]++;
	}	
	for(int i=1; 2*i<=n; i++){
		w[i]+=w[i-1];
		if(w[i]%2==0) 	
			w[i]=0;
		else
			w[i]=1;
	}		
	for(int i=1; 2*i<=n; i++)	
		if(w[i]%2==1){
			swap(s[i-1],s[n-i]);
			
		}
	cout<<s;	
	return 0;
}