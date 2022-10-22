#include <bits/stdc++.h>
using namespace std;
char a[10000];
char b[10000];
short c[10000];
int main(){
    cin>>a>>b;
    int n=strlen(a),i;
    for(i=0;i<n;i++)if(a[i]!=b[i])c[i]=1;
    for(i=0;i<n;i++)cout<<c[i];
        }