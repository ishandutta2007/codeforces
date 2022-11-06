#include<bits/stdc++.h>
using namespace std;
int n,a[105][3];
char str[105];
int main(){
    scanf("%s",str+1),n=strlen(str+1);
    for(int i=1;i<=n;i++){
        if(str[i]=='A')for(int j=-1;j<2;j++)a[i+j][0]=1;
        if(str[i]=='B')for(int j=-1;j<2;j++)a[i+j][1]=1;
        if(str[i]=='C')for(int j=-1;j<2;j++)a[i+j][2]=1;
    }
    for(int i=1;i<=n;i++)if(a[i][0]&&a[i][1]&&a[i][2]){printf("Yes");return 0;}
    printf("No");
    return 0;
}