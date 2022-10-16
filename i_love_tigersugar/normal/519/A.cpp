#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
const char ch[]="QRBNPK";
const int v[]={9,5,3,3,1,0};
const char win[]="White";
const char lose[]="Black";
const char draw[]="Draw";
int score(char c) {
    REP(i,6) if (ch[i]==c) return (v[i]);
    REP(i,6) if (ch[i]-'A'+'a'==c) return (-v[i]);
    return 0;
}
int main(void) {
    char s[13];
    int res=0;
    REP(love,8) {
        scanf("%s",s);
        REP(i,8) res+=score(s[i]);
    }
    if (res>0) printf("%s\n",win);
    if (res==0) printf("%s\n",draw);
    if (res<0) printf("%s\n",lose);
    return 0;
}