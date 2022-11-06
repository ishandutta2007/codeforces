//Problem A
#include<bits/stdc++.h>
using namespace std;

int t,n;
char str[107];
bool chk(char a,char b){
    for(int i=-2;i<4;i+=2)if(a+i==b)return 0;
    return 1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        int f=1;
        scanf("%d%s",&n,str);
        for(int i=0;i<(n>>1);i++)if(chk(str[i],str[n-i-1]))f=0;
        if(f)printf("YES\n");else printf("NO\n");
    }
    return 0;
}