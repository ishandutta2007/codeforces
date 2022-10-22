#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
string s1,s2;ll sum=0,gr[1000099],rg[1000099],bg[1000099],br[1000099],gb[1000099],rb[1000099];ll p1=0,p2=0,cp2;int men(int x){if(s1[x]==s1[x-1]) return 0;if(s1[x-1]=='B' && s1[x]=='R') return rb[p2]-rb[p1];if(s1[x-1]=='B' && s1[x]=='G') return gb[p2]-gb[p1];if(s1[x-1]=='G' && s1[x]=='R') return rg[p2]-rg[p1];if(s1[x-1]=='G' && s1[x]=='B') return bg[p2]-bg[p1];if(s1[x-1]=='R' && s1[x]=='G') return gr[p2]-gr[p1];if(s1[x-1]=='R' && s1[x]=='B') return br[p2]-br[p1];}int main(){cin>>s1>>s2;f(i,1,s2.size()){gr[i]=gr[i-1],gb[i]=gb[i-1],rb[i]=rb[i-1],rg[i]=rg[i-1],bg[i]=bg[i-1],br[i]=br[i-1];if(s2[i-1]=='B' && s2[i]=='R') br[i]++;if(s2[i-1]=='B' && s2[i]=='G') bg[i]++;if(s2[i-1]=='G' && s2[i]=='R') gr[i]++;if(s2[i-1]=='G' && s2[i]=='B') gb[i]++;if(s2[i-1]=='R' && s2[i]=='G') rg[i]++;if(s2[i-1]=='R' && s2[i]=='B') rb[i]++;}while(s2[p2]!=s1[0] && p2<s2.size()-1) p2++;sum+=p2+1;f(i,1,s1.size()){if(s2[p1]==s1[i-1]) p1++;if(p1>=s2.size()) break;p2+=(p2<s2.size()-1);while(s2[p2]!=s1[i] && p2<s2.size()-1) p2++;p2=max(p2,p1);sum+=p2-p1+1;sum-=men(i);}cout<<sum;}