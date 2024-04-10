#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=998244353;
const int mn=1e6+10;
string s[3];
int main(){
    cin>>s[0]>>s[1]>>s[2];
    sort(s,s+3);
    int ans=0x3f3f3f3f;
    do{
        string a;
        a=s[0];
        vector<int>lcp;
        lcp.resize(s[1].size());
        int i,j;
        for(i=1,j=0;i<s[1].size();){
            if(s[1][i]==s[1][j])lcp[i++]=++j;
            else if(j)j=lcp[j-1];
            else i++;
        }
        for(i=0,j=0;i<a.size();){
            if(j==s[1].size())break;
            else if(a[i]==s[1][j])i++,j++;
            else if(j)j=lcp[j-1];
            else i++;
        }
        for(;j<s[1].size();j++)a.push_back(s[1][j]);
        lcp.resize(s[2].size());
        for(i=1,j=0;i<s[2].size();){
            if(s[2][i]==s[2][j])lcp[i++]=++j;
            else if(j)j=lcp[j-1];
            else i++;
        }
        for(i=0,j=0;i<a.size();){
            if(j==s[2].size())break;
            else if(a[i]==s[2][j])i++,j++;
            else if(j)j=lcp[j-1];
            else i++;
        }
        for(;j<s[2].size();j++)a.push_back(s[2][j]);
        ans=min(ans,(int)a.size());
    }while(next_permutation(s,s+3));
    printf("%d",ans);
}