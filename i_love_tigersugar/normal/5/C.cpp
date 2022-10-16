#include<bits/stdc++.h>
#define MAX   1000100
using namespace std;
stack<int> st;
char s[MAX];
int d[MAX];
int c[MAX];
int n;
void init(void) {
    scanf("%s",&s[1]);
    n=strlen(&s[1]);
    while (!st.empty()) st.pop();
}
void process(void) {
    int i,len,cnt;
    for (i=1;i<=n;i=i+1) {
        if (s[i]=='(') st.push(i);
        else {
            if (st.empty()) {
                d[i]=-1;
                c[i]=-1;
            }
            else {
                d[i]=st.top();st.pop();
                if (s[d[i]-1]==')' && c[d[i]-1]>-1) c[i]=c[d[i]-1];
                else c[i]=d[i];
            }
            //printf("%d %d %d\n",i,d[i],c[i]);
        }
    }
    len=0;
    cnt=0;
    for (i=1;i<=n;i=i+1)
        if (s[i]==')' && c[i]>-1) {
            if (i-c[i]+1>len) {
                len=i-c[i]+1;
                cnt=1;
            }
            else if (i-c[i]+1==len) cnt++;
        }
    if (len==0) printf("0 1");
    else printf("%d %d",len,cnt);
}
int main(void) {
    init();
    process();
    return 0;
}