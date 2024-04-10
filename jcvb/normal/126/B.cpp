#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
////////////////////////////////////
const int MAXN=1000000+5;
////////////////////////////////////
int n;
char s[MAXN];// 1 based
int z[MAXN];

void getz(){
    z[1]=n;
    int a=0;
    for (int i=2;i<=n;i++){
        if(a+z[a]-1>=i)z[i]=min(a+z[a]-i,z[i-a+1]);
        for(;s[1+z[i]]==s[i+z[i]];z[i]++);
        if(i+z[i]>a+z[a])a=i;
    }
}
void init(){
    memset(z,0,sizeof(z));
    scanf("%s",s+1);
    n=strlen(s+1);
}

int main()
{
    init();
    getz();
    int ma=0;
    for (int i=2;i<=n;i++)if(i+z[i]-1!=n)ma=max(ma,z[i]);else ma=max(ma,z[i]-1);
    for (int i=1;i<=n;i++)if(i+z[i]-1==n && z[i]<=ma){
        for (int j=1;j<=z[i];j++)putchar(s[j]);
        putchar('\n');
        return 0;
    }
    printf("Just a legend\n");
    return 0;
}