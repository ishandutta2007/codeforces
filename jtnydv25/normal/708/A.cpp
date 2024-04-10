#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l = s.length();
    vector<int> ind;
    ind.push_back(-1);
    for(int i = 0;i<l;i++)
        if(s[i] == 'a')
            ind.push_back(i);
    ind.push_back(l);    
    for(int i = 0;i<ind.size()-1;i++)
        if(ind[i+1]-ind[i] != 1)
        {
            for(int j = ind[i]+1;j<ind[i+1];j++)
                s[j] = 'a' +(s[j]-'a'-1);
            cout<<s;
            return 0;
        }      
    s[l-1]='z';
    cout<<s;  
}