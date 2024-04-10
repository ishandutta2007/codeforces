#include<bits/stdc++.h>
#define MAX   100100
#define x   first
#define y   second
using namespace std;
typedef pair<char,int> ci;
char s[MAX];
stack<ci> st;
int n;
void init(void) {
    scanf("%s",s);
    n=strlen(s);
}
void answer(void) {
    while (!st.empty()) st.pop();
    st.push(ci(s[0],1));
    int i,j,v;
    for (i=1;i<n;i=i+1) {
        if (s[i]!=st.top().x) {
            if (st.top().y%2==0) {          
                v=st.top().y;
                for (j=1;j<=v;j=j+1) st.pop();
                if (st.empty()) st.push(ci(s[i],1));
                else {
                    v=st.top().y;
                    st.push(ci(s[i],v+1));
                }
            }
            else st.push(ci(s[i],1));
        }
        else {
            v=st.top().y;
            st.push(ci(s[i],v+1));      
        }       
    }
    while (!st.empty() && st.top().y%2==0) {
        v=st.top().y;
        for (i=1;i<=v;i=i+1) st.pop();
    }
    if (st.empty()) printf("Yes");
    else printf("No");
}
int main(void) {
    init();
    answer();
    return 0;
}