#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int T;
char s[N],t[N];
vector<pair<char,int>>solve(char*s){
    vector<pair<char,int>>a;
    int n=strlen(s);
    for(int i=0;i<n;++i)
        if(i&&s[i]==s[i-1])
            ++a[a.size()-1].second;
        else
            a.push_back({s[i],1});
    return a;
}
int main(){
    scanf("%d",&T);
    for(;T--;){
        scanf("%s%s",s,t);
        vector<pair<char,int>>a,b;
        a=solve(s);
        b=solve(t);
        if(a.size()!=b.size())
            puts("NO");
        else{
            bool flag=true;
            for(size_t i=0;i<a.size();++i)
                if(a[i].first!=b[i].first||a[i].second>b[i].second){
                    flag=false;
                    break;
                }
            if(flag)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}