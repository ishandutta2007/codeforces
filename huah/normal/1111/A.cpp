#include<bits/stdc++.h>
using namespace std;
bool f[26];
int main()
{
    f['a'-'a']=f['e'-'a']=f['i'-'a']=f['o'-'a']=f['u'-'a']=true;
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size()) {cout<<"No"<<endl;return 0;}
    bool flag=true;
    for(int i=0;i<a.size();i++)
        if(f[a[i]-'a']!=f[b[i]-'a']) {flag=false;break;}
    printf(flag?"Yes":"No");
}