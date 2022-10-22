#include <bits/stdc++.h>
using namespace std;
vector<int> v[2];
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    string s;
    cin>>s;
    for(i=0;i<n;i++){
        v[s[i]-'0'].push_back(i);
    }
    if(v[0].size()<=1||v[1].size()<=1){
        printf("tokitsukaze");
        return 0;
    }
    int l=v[0][0],h=v[0][v[0].size()-1],ll=v[1][0],hh=v[1][v[1].size()-1];
    if(h-l<=k-1||hh-ll<=k-1)printf("tokitsukaze");
    else if(l>=k||h<n-k||ll>=k||hh<n-k||h-l>k||hh-ll>k)printf("once again");
    else printf("quailty");
}