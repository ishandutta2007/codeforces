//Problem A
#include<bits/stdc++.h>
using namespace std;

int n;
char str[100005];
int main(){
    scanf("%d%s",&n,str);
    sort(str,str+n);
    printf("%s",str);
    return 0;
}