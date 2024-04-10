#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    bool up=false;
string s;
cin>>s;
for(int i=0;i<n;i++)
{if(s[i]=='U')s[i]='D';
else if(s[i]=='D')s[i]='U';
}
cout<<s<<endl;
}
    return 0;

}