#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define INF 1000000000000000007
long long n;
set<char> S;
set<long long> M;
string s;
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>s;
        int flag = 0;
        sort(s.begin(),s.end());
        for (int i = 1;i<s.length();i++){
            if (s[i]-s[i-1]!=1 ){cout<<"No"<<endl;flag = 1;
            break;}

        }
        if (flag==0)
        cout<<"Yes"<<endl;
    }

}