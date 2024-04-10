#include <bits/stdc++.h>
using namespace std;
char niz[100];
int main(){
int a=0,b=0,n,i;
    cin>>n>>niz;
    for(i=1;i<n;i++){
    if(niz[i]=='S' && niz[i-1]=='F')b++;
if(niz[i]=='F' && niz[i-1]=='S')a++;
}
if(a>b)cout<<"YES";
else cout<<"NO";
	return 0;
}