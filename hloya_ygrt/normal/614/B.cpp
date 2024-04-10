#include <bits\stdc++.h>

using namespace std;
#define ll long long
    ll st = 0;
    string beaut;
    bool bea=0;

   void get_(string s){

        if (s[0] != '1')
           {
                beaut.resize(s.size());
                beaut = s;
                bea=1;
                return;
           }
        ll ans=0;
        for (int i=1;i<s.size();i++){
            if (s[i]!='0')
                {beaut = s;
            bea=1;
            return;
                }
                else
                    ans++;
        }
        st+=ans;

    }

    void bad()
    {
        cout<<0;
        exit(0);
    }
int main()
{
    string s;

    int n;
    cin>>n;

    for (int i=0;i < n;i++){
        cin>>s;

        if (s=="0")
            bad();

          get_(s);

    }
//cout<<bea<<endl;
  //  cout<<beaut<<endl;

if (!bea){
        printf("1");

        for (int i=0;i<st;i++)
            printf("0");
    } else
    {
        cout<<beaut;
        for (int i=0;i<st;i++)
                printf("0");
    }
    return 0;
}