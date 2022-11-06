//Problem A
#include<bits/stdc++.h>
using namespace std;

int n;
char str[100005];

int main(){
    scanf("%d%s",&n,str);
    sort(str,str+n);
    int f=0;
    for(int i=0;i<n-1;i++)if(str[i]==str[i+1])f=1;
    if(f||n==1)printf("Yes");else printf("No");
    return 0;
}