#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
set<int>s1,s2,s3[26];
int bit[mn],p[mn],num[26];
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int f(int x){return p[x]==x?x:(p[x]=f(p[x]));}
void u(int a,int b){p[f(a)]=f(b);}
int tot(){
    for(int i=0;i<26;i++)if(s3[i].size())return 1;
    return 0;
}
int main(){
   cin.tie(0);
   cin.sync_with_stdio(0);
   int tc;
   cin>>tc;
   while(tc--){
       vector<pii>ans;
       string s;
       cin>>s;
       for(char&c:s)c-='a';
       int n=s.size();
       fill(bit+1,bit+n+2,0);
       for(int i=1;i<=n+1;i++)up(i,1);
       iota(p+1,p+n+2,1);
       s1.clear(),s2.clear();
       for(int i=0;i<26;i++)s3[i].clear();
       vector<int>o(26);
       iota(o.begin(),o.end(),0);
       memset(num,0,sizeof(num));
       for(int i=0;i<n-1;i++)if(s[i]==s[i+1])num[s[i]]++;
       for(int i=1;i+1<n;i++){
           if(s[i-1]!=s[i]&&s[i]==s[i+1])s1.insert(i);
           if(s[i-1]==s[i]&&s[i]!=s[i+1])s2.insert(i);
       }
       if(n>=2) {
           if (s[0] == s[1])s1.insert(0);
           if (s[n - 2] == s[n - 1])s2.insert(n - 1);
       }
       for(int x:s2){
           auto it=s1.upper_bound(x);
           if(it==s1.end())continue;
           if(s[x]!=s[*it])s3[s[x]].insert(x),s3[s[*it]].insert(x);
       }
       while(tot()){
           sort(o.begin(),o.end(),[](int a,int b){return num[a]>num[b];});
           int ind;
           for(int i=0;i<26;i++)if(s3[o[i]].size()){
               ind=o[i];
               break;
           }
           int x=*s3[ind].begin();
           int y=*s1.upper_bound(x);
           s3[s[x]].erase(x);
           s3[s[y]].erase(x);
           num[s[x]]--,num[s[y]]--;
           ans.push_back({x,y});
           s2.erase(x);
           s1.erase(y);
           if(s1.count(x-1)){
                s1.erase(x-1);
                auto it=s2.upper_bound(x-1);
                if(it!=s2.begin()){
                    int l=*(--it);
                    for(int i=0;i<26;i++)s3[i].erase(l);
                }
           }
           else s2.insert(x-1);
           if(s2.count(y+1)){
                s2.erase(y+1);
                for(int i=0;i<26;i++)s3[i].erase(y+1);
           }
           else s1.insert(y+1);
           auto it=s2.upper_bound(x);
           if(it==s2.begin())continue;
           int l=*(--it);
           it=s1.upper_bound(l);
           if(it==s1.end())continue;
           if(s[l]!=s[*it])s3[s[l]].insert(l),s3[s[*it]].insert(l);
       }
       for(int l:s1){
           int r=*s2.upper_bound(l);
           for(int i=0;i<r-l;i++)ans.push_back({l+i,l+i});
       }
       ans.push_back({0,n-1});
       printf("%d\n",ans.size());
       for(pii p:ans){
           p.first++,p.second++;
           int r;
           printf("%d %d\n",qu(f(p.first)),r=qu(p.second));
           vector<int>rem;
           for(int i=f(p.first);qu(i)<=r;i=f(i+1)){
               rem.push_back(i);
           }
           for(int i:rem){
               up(i,-1);
               u(i,i+1);
           }
       }
   }
}