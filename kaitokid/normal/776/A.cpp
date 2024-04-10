#include <bits/stdc++.h>

using namespace std;
string s[2];
int main()
{
int n;
   cin>>s[0]>>s[1]>>n;
for(int i=0;i<n;i++)
{
    cout<<s[0]<<" "<<s[1]<<endl;
 string x,y;
 cin>>x>>y;
 if(s[0]==x)s[0]=y;
 else s[1]=y;


}
 cout<<s[0]<<" "<<s[1];
    return 0;
}