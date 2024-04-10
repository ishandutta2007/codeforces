#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef pair<int,int> pii;
string s1,s2;
vector<int>v1,v2;
int ans2,ans1;
int main()
{
    cin>>s1>>s2;
    v1.push_back(0);
    v1.push_back(0);
    v2.push_back(0);
    v2.push_back(0);
  //  cout<<s2.size()-s1.size()<<endl;
    if(s1.size()>s2.size())
        for(int i=0;i<s1.size()-s2.size();i++)
            v2.push_back(0);
    else
        for(int i=0;i<s2.size()-s1.size();i++)
            v1.push_back(0);
    for(int i=0;i<s1.size();i++)
        v1.push_back(int(s1[i]-'0'));
    for(int i=0;i<s2.size();i++)
        v2.push_back(int(s2[i]-'0'));
    //cout<<v1.size()<<" "<<v2.size()<<endl;
    for(int i=0;i<v1.size();i++)
        if(v1[i]==v2[i])
        {
            v1[i]=0;
            v2[i]=0;
        }
    for(int i=0;i<v1.size()-2;i++)
    {
        int k=min(v1[i+1],v1[i+2]);
        v1[i]+=k;
        v1[i+1]-=k;
        v1[i+2]-=k;
        k=min(v2[i+1],v2[i+2]);
        v2[i]+=k;
        v2[i+1]-=k;
        v2[i+2]-=k;
        k=min(v2[i],v1[i]);
        v2[i]-=k;
        v1[i]-=k;
        if(v1[i]>v2[i]+1)
        {
            cout<<">"<<endl;
            return 0;
        }
        if(v1[i]+1<v2[i])
        {
            cout<<"<"<<endl;
            return 0;
        }
        v1[i+1]+=v1[i];
        v2[i+1]+=v2[i];
        v1[i+2]+=v1[i];
        v2[i+2]+=v2[i];
    }
    ans1=v1[v1.size()-2]*2+v1.back();
    ans2=v2[v2.size()-2]*2+v2.back();
    if(ans1>ans2)
        cout<<">"<<endl;
    else if(ans1<ans2)
        cout<<"<"<<endl;
    else
        cout<<"="<<endl;
}