#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k, c[N];
char s[N];
stack<int> st;

int main(){
    scanf("%d%d%s", &n, &k, s);
    for(int i = 0; i < n; i++){
        if(s[i] == '(') st.push(i);
        else{
            if(k < n){
                c[i] = c[st.top()] = 1;
                k += 2;
            }
            st.pop();
        }
    }
    for(int i = 0; i < n; i++) if(!c[i]) putchar(s[i]);
    puts("");
}