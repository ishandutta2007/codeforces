#include<bits/stdc++.h>
#define MAX   1000100
char s[MAX];
int delay[MAX];
int nmale[MAX];
int prev[MAX];
int n;
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%s",&s[1]);
    n=strlen(&s[1]);
    prev[1]=0;
    nmale[1]=0;
    int i;
    for (i=2;i<=n;i=i+1) {
        if (s[i-1]=='F') prev[i]=i-1;
        else prev[i]=prev[i-1];
        nmale[i]=nmale[i-1]+(s[i-1]=='M');
    }
}
void count(void) {
    int i;
    for (i=1;i<=n;i=i+1)
        if (s[i]=='F') {
            if (nmale[i]==0) delay[i]=0;
            else {
                if (prev[i]==0) delay[i]=0;
                else delay[i]=delay[prev[i]]+1-(i-prev[i]-1);
                if (delay[i]<0) delay[i]=0;
            }           
        }
    int res=0;
    for (i=1;i<=n;i=i+1)
        if (s[i]=='F' && nmale[i]>0) maximize(res,delay[i]+nmale[i]);
    printf("%d",res);
}
int main(void) {
    init();
    count();
    return 0;
}