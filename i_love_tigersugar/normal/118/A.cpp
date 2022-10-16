#include<bits/stdc++.h>
#define MAX   111
const char vowel[]="AOYEUIaoyeui";
bool isVowel(char c) {
    for (int i=0;i<12;i=i+1)
        if (vowel[i]==c) return (true);
    return (false);
}
bool isUppercase(char c) {
    return ('A'<=c && c<='Z');
}
char s[MAX];
int main(void) {
    scanf("%s",s);
    int n=strlen(s);
    for (int i=0;i<n;i=i+1) {
        if (isVowel(s[i])) continue;
        printf(".");
        printf("%c",isUppercase(s[i])?s[i]-'A'+'a':s[i]);
    }
    printf("\n");
    return 0;
}