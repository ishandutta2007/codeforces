#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
string ans,s;
void ch(string u)
{
    while(u.size()<k)u=u+u;
    string rs="";
    for(int i=0;i<k;i++)rs+=u[i];
    if(rs<ans)ans=rs;
}
int main()
{

        ans="{";
       cin>>n>>k;
       cin>>s;
       string u="";
        for(int i=0;i<n;i++)
        {
            u+=s[i];
            ch(u);
        }
        cout<<ans<<endl;

    return 0;

}