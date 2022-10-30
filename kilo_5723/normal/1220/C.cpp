#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=5e5+5;
char s[maxn];
int main(){
    int i;
    char ch='z';
    scanf("%s",s);
    for (i=0;s[i];i++){
        puts(ch<s[i]?"Ann":"Mike");
        ch=min(ch,s[i]);
    }
    return 0;
}