#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string s;
int a[2],ans;
int main()
{
ios::sync_with_stdio(0);
cin>>n>>k>>s;
int i=0,j=0;
a[s[0]-'a']++;
while(j<n)
{

if(min(a[0],a[1])>k){a[s[i]-'a']--;i++;continue;}

ans=max(ans,j-i+1);
j++;
if(j==n)break;
a[(s[j]-'a')]++;

}
cout<<ans;
return 0;
}