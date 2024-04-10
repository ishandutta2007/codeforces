#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e6+10;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s;
    cin>>s;
    int n=s.size(),i;
    int f=0,lf=-1;
    ll del=0;
    for(i=0;i<n;i++){
        if(s[i]=='F'){
            if(i==f)del=0;
            else del=max(0LL,del+2-(i-lf));
            lf=i;
            f++;
        }
    }
    printf("%d",del+lf-(f-1));
}