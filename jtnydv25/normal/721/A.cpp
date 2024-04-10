#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec;
    int n;
    string s;
    cin>>n;
    cin>>s;
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i]=='B')
            cnt++;
        else
        {
            if(cnt)
                vec.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt)
        vec.push_back(cnt);
    cout<<vec.size()<<"\n";
    for(int x:vec)
        cout<<x<<" ";
    cout<<"\n";
}