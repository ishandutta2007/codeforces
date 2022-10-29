#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int n,i,j,l,l1,flag,tab,tot,o,f[201][201],vis[201];
char s[200],s1[201],ans[201];

int main(){
    cin>>n;
    gets(s);
    gets(s);
    l=strlen(s);
    rep(i,0,25)
    rep(j,0,25)
        f[i][j]=0;
    flag=1;
    rep(i,2,n){
        gets(s1);
        l1=strlen(s1);
        j=0;
        while ((j<l1)&&(j<l)&&(s[j]==s1[j]))
            j++;
        if ((j!=l1)&&(j!=l)){
            f[s[j]-'a'][s1[j]-'a']=1;
        }
        else{
            if (l>l1)
                flag=0;
        }
        strcpy(s,s1);
        l=l1;
    }
    rep(i,0,25)
        vis[i]=1;
    rep(o,0,25){
        tab=1;
        rep(i,0,25)
            if (vis[i]){
            tot=1;
            rep(j,0,25)
                if (f[j][i])
                    tot=0;
            if (tot){
                vis[i]=0;
                ans[o]=i+'a';
                tab=0;
                rep(j,0,25)
                    f[i][j]=0;
                break;
            }
        }
        if (tab){
            flag=0;
            break;
        }
    }
    if (flag){
        rep(o,0,25)
            cout<<ans[o];
        cout<<endl;
    }
    else{
        cout<<"Impossible"<<endl;
    }
    return 0;
}