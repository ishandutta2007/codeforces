#include <bits/stdc++.h>

using namespace std;
char s[500001],mov[500001];
int part[500001],tel[500001];
int f(int x){if(tel[x]==x)return x;return tel[x]=f(tel[x]);}
int main()
{
    int n,m,ptr,i;
    scanf("%d%d%d ",&n,&m,&ptr);
    ptr--;
    for(i=0;i<n;i++)scanf("%c",s+i);
    scanf(" ");
    for(i=0;i<m;i++)scanf("%c",mov+i);
    for(i=0;i<=n;i++)tel[i]=i;
    stack<int> st;
    for(i=0;i<n;i++){
        if(s[i]=='(')st.push(i);
        else part[i]=st.top(),part[st.top()]=i,st.pop();
    }
    for(i=0;i<m;i++){
        if(mov[i]=='L')ptr--,ptr=f(ptr);
        if(mov[i]=='R')ptr++,ptr=f(ptr);
        if(mov[i]=='D'){
            int lo=min(ptr,part[ptr]),hi=max(ptr,part[ptr]);
            tel[lo]=hi+1;
            tel[hi]=lo-1;
            ptr=f(hi+1);
            if(ptr>=n)ptr=f(lo-1);
        }
    }
    for(i=f(0);i<n;i++,i=f(i))printf("%c",s[i]);
}