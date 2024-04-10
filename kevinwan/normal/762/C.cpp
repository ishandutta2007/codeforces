#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
int l[mn],r[mn];
int main()
{
    int i,j;
    string a,b;
    cin>>a>>b;
    b=" "+b;
    l[0]=-1;
    r[b.size()]=a.size();
    for(i=1;i<b.size();i++){
        l[i]=l[i-1]+1;
        while((l[i]<a.size()&&a[l[i]]!=b[i]))l[i]++;
    }
    for(i=b.size()-1;i;i--){
        r[i]=r[i+1]-1;
        while((r[i]>=0&&a[r[i]]!=b[i]))r[i]--;
    }
    int bes=0,bl=0,br=b.size();
    for(i=0,j=1;i<b.size();i++){
        j=max(j,i+1);
        while(j<b.size()&&r[j]<=l[i])j++;
        if(l[i]<r[j])if(i-j+b.size()>bes)bl=i,br=j,bes=i-j+b.size();
    }
    if(bes==0)printf("-");
    for(i=1;i<=bl;i++)printf("%c",b[i]);
    for(i=br;i<b.size();i++)printf("%c",b[i]);
}