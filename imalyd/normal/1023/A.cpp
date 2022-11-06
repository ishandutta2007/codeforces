//Problem A
#include<bits/stdc++.h>
using namespace std;

int n,m,p=-1;
string s,t;
#define dbg(str) cout<<(#str)<<" = "<<(str)<<endl
int main(){
    cin>>n>>m>>s>>t;
    for(int i=0;i<n;i++)if(s[i]=='*')p=i;
    if(~p){
        /*dbg(s.substr(0,p));
        dbg(t.substr(0,p));
        dbg(s.substr(p+1,n-p-1));
        dbg(t.substr(m-(n-p-1),n-p-1));*/
        if(n-1<=m&&(!p||s.substr(0,p)==t.substr(0,p))&&(p==n-1||s.substr(p+1,n-p-1)==t.substr(m-(n-p-1),n-p-1)))
            printf("YES");else printf("NO");
    }else{
        if(s==t)printf("YES");else printf("NO");
    }
    return 0;
}