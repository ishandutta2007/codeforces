#include<bits/stdc++.h>
using namespace std;
char a[100005];

int main()
{
    int len;
    scanf("%s",&a);
    len = strlen(a);
    bool flag = false;
    for(int i=0;i<len;i++) {
        if(a[i] != 'a') flag = true;
        if(flag && a[i] == 'a') break;
        if(flag) a[i]--;
    }
    if(!flag) a[len-1] = 'z';
    printf("%s\n",a);
}