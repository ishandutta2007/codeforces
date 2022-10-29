#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int i,j,tot,l,flag;
char ch, s[200001];

int main(){
    gets(s);
    l=strlen(s);
    tot=0;
    rep(i,0,l-2)
        if ((s[i]-'0')%2==0)
            tot++;
    if (tot==0){
        cout<<-1<<endl;
        return 0;
    }
    flag=1;
    rep(i,0,l-2)
        if (((s[i]-'0')%2==0)&&(s[i]<s[l-1])){
            flag=0;
            ch=s[i];
            s[i]=s[l-1];
            s[l-1]=ch;
            break;
        }
    if (flag){
        rrep(i,l-2,0)
            if ((s[i]-'0')%2==0){
                ch=s[i];
                s[i]=s[l-1];
                s[l-1]=ch;
                break;
            }
    }
    printf("%s\n",s);
    return 0;
}