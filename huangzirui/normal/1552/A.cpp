#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500010,mod=998244353;
int i,j,n,m,l,k;
char s[maxn],t[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",&s);
        for(int i=0;i<n;i++)t[i]=s[i];
        sort(s,s+n);
        int ans=0;
        for(int i=0;i<n;i++)ans+=(t[i]!=s[i]);
        cout<<ans<<endl;
    }
}