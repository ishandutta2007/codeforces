#include <bits/stdc++.h>
using namespace std;
char niz[1000];
int main() {
	// your code goes here kurcina
    cin>>niz;
int k=strlen(niz),i;
    if(niz[0]>90)niz[0]-=32;
    for(i=0;i<k;i++)cout<<niz[i];
    
	return 0;
}