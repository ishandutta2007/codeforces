#include <bits/stdc++.h>

using namespace std;

int use[30];
string s;


int main()
{int n;
cin>>n;
cin>>s;
int k=0;
    for(int i=0;i<s.size();++i)
    {

        if(isupper(s[i]))
            s[i]=tolower(s[i]);

            if(!use[s[i]-'a'])
                k++, use[s[i]-'a']=1;

    }
    if(k==26)
        cout<<"YES\n";
    else cout<<"NO\n";


    return 0;
}