#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string S;
        cin>>S;
        bool allL=1,allR=1;
        for(int i=0;i<n;i++)
            if(S[i]=='>')
                allL=0;
            else if(S[i]=='<')
                allR=0;
        if(allL||allR)
        {
            cout<<n<<endl;
        }
        else
        {
            int cnt=0;
            for(int i=0;i<n;i++)
                if(S[i]=='-'||S[(i+n-1)%n]=='-')
                    cnt++;
            cout<<cnt<<endl;
        }
    }
    return 0;
}