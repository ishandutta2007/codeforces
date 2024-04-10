#include <bits/stdc++.h>

using namespace std;

int n, k;
map<char, int> m;

void pre()
{
    m['p']=1;
    m['.']=0;
    m['k']=0;
    m['q']=9;
    m['b']=3;
    m['n']=3;
    m['r']=5;
    m['P']=-1;
    m['K']=0;
    m['Q']=-9;
    m['B']=-3;
    m['N']=-3;
    m['R']=-5;

}
string s;
int main()
{
    pre();
    int ans=0;
    for(int i=1;i<=8;i++)
    {
cin>>s;
    for(int i=0;i<s.size();i++)
        ans+=m[s[i]];
    }

    if(ans==0)
        cout<<"Draw";
    else if(ans<0)
        cout<<"White";
    else cout<<"Black";
    return 0;
}