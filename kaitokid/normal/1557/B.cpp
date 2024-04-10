#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
map<int,int>mp;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,k,u=1;
    cin>>n>>k;
    mp.clear();
    for(int i=0;i<n;i++){cin>>a[i];mp[a[i]]=i;}
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        if(mp[a[i]]!=mp[a[i-1]]+1)u++;
    }
    if(k<u)cout<<"No\n";
    else cout<<"Yes\n";

}
  return 0;
}