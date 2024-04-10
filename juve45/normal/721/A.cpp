#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int n;
string s;
int main()
{
cin>>n;

cin>>s;

for(int i=0;i<n;i++)
{
    if(s[i]=='B') v.push_back(1), i++;
    while(i<n && s[i]=='B')
    {
        i++;
        v[v.size()-1]++;
    }
}
cout<<v.size()<<'\n';
for(int i=0;i<v.size();i++)
    cout<<v[i]<<' ';
    return 0;
}