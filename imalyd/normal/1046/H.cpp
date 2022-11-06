//Problem H
#include<bits/stdc++.h>
using namespace std;

int n,x[100005];
map<int,int>c;
char str[1000005];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",str);int l=strlen(str);
        for(int j=0;j<l;j++)x[i]^=1<<(str[j]-'a');
        ++c[x[i]];
    }//for(int i=1;i<=n;i++)printf("%d\n",x[i]);
    for(int i=1;i<=n;i++){
        ans+=c[x[i]];
        for(int j=0;j<26;j++)ans+=c[x[i]^(1<<j)];
    }
    cout<<((ans-n)>>1);
    return 0;
}