#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2;
map<char ,int > mp;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>s1>>s2;
        int l = s1.length();
        for(int i=0;i<l;i++)
        {
            mp[s1[i]]++;
        }
        int flag = 1;
        for(int i=0;i<l;i++){
            if(mp[s2[i]]){
                flag = 0;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }

    return 0;
}