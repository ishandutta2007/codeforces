#include <bits/stdc++.h>

using namespace std;
int x,s,n,i;vector<int> t,ans;
void makearr(int z){while(z){t.push_back(z%10);z/=10;}}
int num(){int z=i;for(int y=0;y<t.size();y++)z+=t[y];return z;}
int main()
{
    cin>>s;
    x=int(log10(s))+1;
    for(i=max(s-(x*10),1);i<s;i++){t.clear();makearr(i);if(num()==s)ans.push_back(i);}
    cout<<ans.size()<<endl;
    for(int j=0;j<ans.size();j++)cout<<ans[j]<<endl;


    return 0;
}