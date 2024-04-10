#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
int lps[mn],lm[mn],rm[mn],ls[mn],rs[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    int ans=0;
    while(n--){
        string t;
        cin>>t;
        if(t.size()==1)continue;
        for(int i=1,j=0;i<t.size();){
            if(t[i]==t[j])lps[i++]=++j;
            else if(j)j=lps[j-1];
            else lps[i++]=0;
        }
        for(int i=0,j=0;i<s.size();){
            if(j==t.size())j=lps[j-1];
            else if(s[i]==t[j])lm[i++]=++j;
            else if(j)j=lps[j-1];
            else lm[i++]=0;
        }
        reverse(t.begin(),t.end());
        for(int i=1,j=0;i<t.size();){
            if(t[i]==t[j])lps[i++]=++j;
            else if(j)j=lps[j-1];
            else lps[i++]=0;
        }
        for(int i=s.size()-1,j=0;i>=0;){
            if(j==t.size())j=lps[j-1];
            else if(s[i]==t[j])rm[i--]=++j;
            else if(j)j=lps[j-1];
            else rm[i--]=0;
        }
        memset(ls,0x3f,sizeof(ls));
        memset(rs,0xc0,sizeof(rs));
        for(int i=s.size()-1;i>=0;i--)ls[lm[i]]=i;
        for(int i=0;i<s.size();i++)rs[rm[i]]=i;
        for(int i=t.size()-1;i>=0;i--)ls[i]=min(ls[i],ls[i+1]),rs[i]=max(rs[i],rs[i+1]);
        if(ls[t.size()]!=0x3f3f3f3f)ans++;
        else{
            int ad=0;
            for(int i=1;i<t.size();i++)if(ls[i]<rs[t.size()-i])ad=1;
            ans+=ad;
        }
    }
    cout<<ans;
}