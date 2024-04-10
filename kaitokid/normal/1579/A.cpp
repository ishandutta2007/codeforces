#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int a[3]={0,0,0};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)a[s[i]-'A']++;

    if(a[1]!=a[2]+a[0])cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
return 0;
}