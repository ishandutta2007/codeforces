//Problem A
#include<bits/stdc++.h>
using namespace std;

int n,m;
char str[233];
int main(){
    scanf("%d%s",&n,str);
    for(int i=0;i<n;i++)if(str[i]=='8')++m;
    printf("%d",min(n/11,m));
    return 0;
}