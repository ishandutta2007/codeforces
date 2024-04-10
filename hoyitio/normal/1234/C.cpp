
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t,n;
    string s[3];
    cin>>t;
    while(t--)
    {
        int i, k = 0;
        cin>>n;
        cin>>s[0]>>s[1];
        for(i=0;i<n;i++)
        {
            if(s[k][i] > '2'){
                k = 1-k;
                if(s[k][i] <= '2'){
                    break;
                }
            }
        }
        if(k == 0 || i != n){
            printf("NO\n");
            continue ;
        }
        printf("YES\n");
    }

}